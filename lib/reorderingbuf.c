/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <syslog.h>
#include "reorderingbuf.h"
#include <inttypes.h>
#include <stdlib.h>
#include "ofpbuf.h"
#include "vconn.h"
#include "vlog.h"
#include "packets.h"
#include "odp-util.h"
#include "unaligned.h"
#include "util.h"
#include "ofp-print.h"
#include "dynamic-string.h"
#include "timeval.h"

VLOG_DEFINE_THIS_MODULE(reorderingbuf);

/* Array of TCP Buffers*/
struct tcp_buf * ovs_tcp_buffer[OVS_TCP_BUFFER_MAXSIZE];

/* Number of TCP buffers in the ovs_tcp_buffer array*/
int tcp_buffers_count = 0;


/* Creates a new TCP buffer with key flow_id and returns its pointer */
struct tcp_buf * create_new_tcp_buf(uint32_t flow_id){
    struct tcp_buf * tcp_buf;
    tcp_buffers_count++;
    tcp_buf = malloc (sizeof (struct tcp_buf));
    tcp_buf->flow_id = flow_id;
    tcp_buf->inserted_items = 0;
    tcp_buf->consecutive_buffering_events = 0;
    tcp_buf->expected_seqnum = -1;
    tcp_buf->timeout = time_msec();
    tcp_buf->fin_state = false;
    return tcp_buf;
}


/* Deletes a TCP buffer */
void delete_tcp_buf(struct tcp_buf *tcp_buffer){
    int i,j;
    int del_index;

    VLOG_DBG("Deleting tcp_buf with id: % " PRIu32, tcp_buffer->flow_id);

    // Delete the buffer
    del_index = -1;
    for(i=0;i<tcp_buffers_count;i++){
        if(!ovs_tcp_buffer[i]){
            VLOG_ERR("Error! Buffer not found at %d", i);        
        }
        else if(ovs_tcp_buffer[i] == tcp_buffer){
            del_index = i;
            free(tcp_buffer);
            break;
        }
    }

    // Compact the array
    if(del_index!=-i-1){
        tcp_buffers_count--;
        for(i=del_index;i<tcp_buffers_count;i++){
             ovs_tcp_buffer[i] = ovs_tcp_buffer[i+1];
        }
    }
}

/* Gets the pointer to a TCP Buffer */
struct tcp_buf * get_tcp_buf(uint32_t flow_id){
    int i;
    struct tcp_buf * new_buf;
    if(tcp_buffers_count == 0){
        VLOG_DBG("Creating new tcp_buf, existing %d id %" PRIu32, tcp_buffers_count, flow_id);
        new_buf = create_new_tcp_buf(flow_id);
        ovs_tcp_buffer[tcp_buffers_count-1] = new_buf;
        return new_buf;
    }
    else{
        for(i=0;i<tcp_buffers_count;i++){
            if(!ovs_tcp_buffer[i]){
                VLOG_ERR("Error! Buffer not found at %d", i);
            }
            else if(ovs_tcp_buffer[i]->flow_id == flow_id){
                return ovs_tcp_buffer[i];
            }
        }
        // If existing tcp_buf is not found
        VLOG_DBG("Creating new tcp_buf, existing %d", tcp_buffers_count);
        new_buf = create_new_tcp_buf(flow_id);
        ovs_tcp_buffer[tcp_buffers_count-1] = new_buf;
        return new_buf;
    }
}

/* Insertion sort of the packet in the buffer using its seqnum */
void insert_descending_order(struct tcp_buf *tcp_buffer, struct ofpbuf *pkt){
    int i, index;
    uint32_t seq_buf, seq_new;

    index = 0;
    if(tcp_buffer->inserted_items == 0){
        tcp_buffer->buffer[0] = pkt;
    }
    else{
        seq_buf = get_tcp_seq(tcp_buffer->buffer[index]);
        seq_new = get_tcp_seq(pkt);
        // Find the correct position for the item
        while((seq_new <= seq_buf) && (index<tcp_buffer->inserted_items)){
            index++;
            if(seq_new == seq_buf){
                tcp_buffer->expected_seqnum = get_next_seqnum(tcp_buffer, seq_new, pkt, false);
            } 
            if(tcp_buffer->buffer[index]){
                seq_buf = get_tcp_seq(tcp_buffer->buffer[index]);
            }
        }
        // Shift the elements to the right
        for(i=tcp_buffer->inserted_items;i>index;i--){
            tcp_buffer->buffer[i] = tcp_buffer->buffer[i-1];
        }
        tcp_buffer->buffer[index] = pkt;
    }

    tcp_buffer->inserted_items++;
    tcp_buffer->consecutive_buffering_events++;
}


uint32_t get_next_seqnum(struct tcp_buf *tcp_buffer, int seq, struct ofpbuf *packet, bool loss_recovery){
    unsigned int size;
    uint8_t tcp_flags;
    struct tcp_header *tcp;

    tcp = ofpbuf_l4(packet);
    tcp_flags = TCP_FLAGS(tcp->tcp_ctl);    
    size = get_tcp_payload_size(packet);

    // Sliding the expected seq forward to recover from the probable burst
    // of losts packets
    if(loss_recovery){
        return (seq + (get_tcp_payload_size(packet)*LOSS_RECOVERY_SLIDING)) % 0xFFFFFFFF;
    }
    else {
        if(tcp_flags & TCP_FIN){
            VLOG_INFO("Last packet above was FIN");
            tcp_buffer->fin_state = true;
            return (seq + size + 1) % 0xFFFFFFFF;
        }
        else{
            return (seq + size) % 0xFFFFFFFF;
        }
    }
}


int get_packet_list(struct ofpbuf *out_packets[], struct ofpbuf * packet, uint32_t flow_id, uint32_t in_port){

    struct tcp_buf * tcp_buf;    
    uint8_t tcp_flags;
    struct tcp_header *tcp;
    uint32_t seq;
    int i, out_packets_count;
    uint32_t seq_work;
    struct ofpbuf * buf_pkt;
    int removed_items;


    // Getting the buffer for the flow, or creating a new one if 
    // not existing
    tcp_buf = get_tcp_buf(flow_id);

    tcp = ofpbuf_l4(packet);
    tcp_flags = TCP_FLAGS(tcp->tcp_ctl);    
    seq = get_tcp_seq(packet);

    out_packets_count = 0;


    if (tcp_flags & TCP_SYN){
        tcp_buf->expected_seqnum = seq+1;
        VLOG_INFO("[SYN packet] sequence: %" PRIu32 " expected: %" PRIu32 " in_port: %"PRIu32 "  size: %d",
            seq, tcp_buf->expected_seqnum, in_port, tcp_buf->inserted_items);
        out_packets[out_packets_count] = packet;
        out_packets_count++;
    }
    else if(tcp_buf->fin_state){
        delete_tcp_buf(tcp_buf);
        out_packets[out_packets_count] = packet;
        out_packets_count++;
    }
    // Retransmission or packets which come without a SYN or after a FIN
    // Just send out
    else if(tcp_buf->expected_seqnum == -1){
        out_packets[out_packets_count] = packet;
        out_packets_count++;
    }
    // Sending out and checking if the the gap in the reordering buffer has been filled
    else if(seq <= tcp_buf->expected_seqnum){
        VLOG_INFO("[sending in order packet] seq: %"PRIu32 " expected: %" PRIu32 " in_port: %"PRIu32 " size: %d",
            seq, tcp_buf->expected_seqnum, in_port, tcp_buf->inserted_items);

        out_packets[out_packets_count] = packet;
        out_packets_count++;
        tcp_buf->consecutive_buffering_events = 0;

        // Increasing sequence only if it matches
        if(seq == tcp_buf->expected_seqnum){
            tcp_buf->expected_seqnum = get_next_seqnum(tcp_buf, tcp_buf->expected_seqnum, packet, false);
        }

        // Check if there are packets waiting to be sent
        removed_items = 0;
        for(i=tcp_buf->inserted_items-1;i>= 0;i--){
            seq_work = get_tcp_seq(tcp_buf->buffer[i]);

            if(seq_work <= tcp_buf->expected_seqnum){
                VLOG_INFO("[sending out from buffer] sequence: %" PRIu32 " expected: %" PRIu32 " size: %d",
                    seq_work, tcp_buf->expected_seqnum, tcp_buf->inserted_items - removed_items);
                removed_items++;            
                out_packets[out_packets_count] = tcp_buf->buffer[i];
                out_packets_count++;
                if(seq_work == tcp_buf->expected_seqnum){
                    tcp_buf->expected_seqnum = get_next_seqnum(tcp_buf, tcp_buf->expected_seqnum, tcp_buf->buffer[i], false);
                }
            }
        }
        tcp_buf->inserted_items = tcp_buf->inserted_items - removed_items;
    }
    // Buffer not full yet, buffering the packet
    else if(tcp_buf->inserted_items<TCP_BUF_SIZE && tcp_buf->consecutive_buffering_events < CONSECUTIVE_BUFFERING_TREESHOLD){
        VLOG_INFO("[buffering] sequence: %"PRIu32 " expected: %" PRIu32 " in_port: %"PRIu32 " size: %d",
            seq, tcp_buf->expected_seqnum, in_port, tcp_buf->inserted_items);
        buf_pkt = ofpbuf_clone(packet);
        insert_descending_order(tcp_buf, buf_pkt);
    }
    // Buffer full or loss event detecte
    else{
        VLOG_WARN("!! -- Empty Buffer Event -- !!");
        if(tcp_buf->consecutive_buffering_events >= CONSECUTIVE_BUFFERING_TREESHOLD)
            syslog(LOG_INFO, "!! -- Because of an apparent loss -- !!");

        seq_work = get_tcp_seq(tcp_buf->buffer[tcp_buf->inserted_items-1]);

        // If incoming packet has the smallest sequence
        if(seq<seq_work){
            VLOG_INFO("[resetting buffer] sequence: %" PRIu32, seq);
            out_packets[out_packets_count] = packet;
            out_packets_count++;
        }
        // If a packet in the buffer has the smallest sequence
        else{
            VLOG_INFO("[resetting] sequence: %" PRIu32, get_tcp_seq(tcp_buf->buffer[tcp_buf->inserted_items-1]));
            out_packets[out_packets_count] = tcp_buf->buffer[tcp_buf->inserted_items-1];
            out_packets_count++;
            tcp_buf->inserted_items--;
            buf_pkt = ofpbuf_clone(packet);
            insert_descending_order(tcp_buf, buf_pkt);
        }

        // Completely empty the buffer
        for(i=tcp_buf->inserted_items-1;i>= 0;i--){
            seq_work = get_tcp_seq(tcp_buf->buffer[i]);
            VLOG_INFO("resetting %" PRIu32, seq_work);
            get_next_seqnum(tcp_buf, seq_work, tcp_buf->buffer[i], false);
            out_packets[out_packets_count] = tcp_buf->buffer[i];
            out_packets_count++;

            // Adjusting seqnum
            if(i==0){
                tcp_buf->expected_seqnum = get_next_seqnum(tcp_buf, seq_work, tcp_buf->buffer[i], false);
            }
        }

        tcp_buf->inserted_items=0;

        if(tcp_buf->consecutive_buffering_events >= CONSECUTIVE_BUFFERING_TREESHOLD){
            tcp_buf->expected_seqnum = get_next_seqnum(tcp_buf, tcp_buf->expected_seqnum, packet, true);
        }
    }

    return out_packets_count;
}
