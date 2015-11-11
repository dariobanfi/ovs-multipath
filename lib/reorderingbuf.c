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



int CONSECUTIVE_BUFFERING_TREESHOLD = 100;
int LOSS_RECOVERY_SLIDING = 20;
int TCP_BUF_DYNAMIC_SIZE = 400;



struct tcp_buf {  
    uint32_t flow_id;
    struct ofpbuf * buffer[PKT_BUF_MAXSIZE];
    uint32_t expected_seqnum;
    long long int timeout;
    int inserted_items;
    int consecutive_buffering_events;
    bool fin_state;
};

struct tcp_buf * rdb[RDBUF_MAXSIZE];
int rdb_count = 0;


struct tcp_buf * create_new_tcp_buf(uint32_t flow_id){
    struct tcp_buf * tcp_buf;
    rdb_count++;
    tcp_buf = malloc (sizeof (struct tcp_buf));
    tcp_buf->flow_id = flow_id;
    tcp_buf->inserted_items = 0;
    tcp_buf->consecutive_buffering_events = 0;
    tcp_buf->expected_seqnum = -1;
    tcp_buf->timeout = time_msec();
    tcp_buf->fin_state = false;
    return tcp_buf;
}


void delete_tcp_buf(struct tcp_buf *tcp_buffer){
    int i,j;
    int del_index;

    syslog(LOG_INFO, "Deleting tcp_buf id %"PRIu32, tcp_buffer->flow_id);

    del_index = -1;
    for(i=0;i<rdb_count;i++){
        if(!rdb[i]){
            syslog(LOG_INFO, "FATAL ERROR! BUFF WAS NULL index %d", i);
        }
        else if(rdb[i] == tcp_buffer){
            del_index = i;
            free(tcp_buffer);
            break;

        }
    }

    // Compact array
    if(del_index!=-i-1){
        rdb_count--;
        for(i=del_index;i<rdb_count;i++){
             rdb[i] = rdb[i+1];
        }
    }
}


struct tcp_buf * get_tcp_buf(uint32_t flow_id){
    int i;
    struct tcp_buf * new_buf;
    if(rdb_count == 0){
        syslog(LOG_INFO, "Creating new tcp_buf, existing %d id %" PRIu32, rdb_count, flow_id);
        new_buf = create_new_tcp_buf(flow_id);
        rdb[rdb_count-1] = new_buf;
        return new_buf;
    }
    else{
        for(i=0;i<rdb_count;i++){
            if(!rdb[i]){
                syslog(LOG_INFO, "FATAL ERROR! BUFF WAS NULL index %d", i);
            }
            else if(rdb[i]->flow_id == flow_id){
                // syslog(LOG_INFO, "Found existing tcp_buf for flow_id %"PRIu32, flow_id);
                return rdb[i];
            }
        }

        // If existing tcp_buf is not found
        syslog(LOG_INFO, "Creating new tcp_buf, existing %d", rdb_count);
        new_buf = create_new_tcp_buf(flow_id);
        rdb[rdb_count-1] = new_buf;
        return new_buf;
    }
}


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
                // Send out packets before this
                syslog(LOG_INFO, "LOOK");
                tcp_buffer->expected_seqnum = get_next_seqnum(tcp_buffer, seq_new, pkt, false); // If this happens I could recover - logging to see if it ever happens
            } 
            if(tcp_buffer->buffer[index])
                seq_buf = get_tcp_seq(tcp_buffer->buffer[index]);

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
            syslog(LOG_INFO, "packet above was FIN");
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

        syslog(LOG_INFO, "SYN_seq %" PRIu32 " new_expected %" PRIu32 " in_port %"PRIu32 "  size %d" , seq, tcp_buf->expected_seqnum, in_port, tcp_buf->inserted_items);
        out_packets[out_packets_count] = packet;
        out_packets_count++;

        // TODO: delete existing buffer ofpbufs here
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
    else if(seq <= tcp_buf->expected_seqnum){
        syslog(LOG_INFO, "sending %"PRIu32 " expected %" PRIu32 " in_port %"PRIu32 " size %d", seq, tcp_buf->expected_seqnum, in_port, tcp_buf->inserted_items);

        out_packets[out_packets_count] = packet;
        out_packets_count++;
        tcp_buf->consecutive_buffering_events = 0;

        // Increasing sequence only if it matches
        if(seq == tcp_buf->expected_seqnum){
            tcp_buf->expected_seqnum = get_next_seqnum(tcp_buf, tcp_buf->expected_seqnum, packet, false);
        }


        // // Check if there are packets waiting to be sent
        removed_items = 0;
        for(i=tcp_buf->inserted_items-1;i>= 0;i--){
            seq_work = get_tcp_seq(tcp_buf->buffer[i]);

            if(seq_work <= tcp_buf->expected_seqnum){
                syslog(LOG_INFO, "outbuffing %" PRIu32 " expected %" PRIu32 " size %d", seq_work, tcp_buf->expected_seqnum, tcp_buf->inserted_items - removed_items);
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

    //Buffer not full yet
    else if(tcp_buf->inserted_items<TCP_BUF_DYNAMIC_SIZE && tcp_buf->consecutive_buffering_events < CONSECUTIVE_BUFFERING_TREESHOLD){
        syslog(LOG_INFO, "buffering %"PRIu32 " expected %" PRIu32 " in_port %"PRIu32 " size %d", seq, tcp_buf->expected_seqnum, in_port, tcp_buf->inserted_items);
        buf_pkt = ofpbuf_clone(packet);
        insert_descending_order(tcp_buf, buf_pkt);
    }

    else{

        syslog(LOG_INFO, "!! -- BUFFER FULL -- !!");
        if(tcp_buf->consecutive_buffering_events >= CONSECUTIVE_BUFFERING_TREESHOLD)
            syslog(LOG_INFO, "!! -- Because of an apparent loss -- !!");


        seq_work = get_tcp_seq(tcp_buf->buffer[tcp_buf->inserted_items-1]);

        // If incoming packet has the smallest seq
        if(seq<seq_work){
            syslog(LOG_INFO, "resetting %" PRIu32 " - sending out latest packet and emptying buffer", seq);
            out_packets[out_packets_count] = packet;
            out_packets_count++;
        }
        // If a packet in the buffer has the smallest sequence
        else{
            syslog(LOG_INFO, "resetting %" PRIu32 " - sending lowest buf packet and emptying", get_tcp_seq(tcp_buf->buffer[tcp_buf->inserted_items-1]));
            out_packets[out_packets_count] = tcp_buf->buffer[tcp_buf->inserted_items-1];
            out_packets_count++;
            tcp_buf->inserted_items--;
            buf_pkt = ofpbuf_clone(packet);
            insert_descending_order(tcp_buf, buf_pkt);
        }

        // Completely empty buffers
        for(i=tcp_buf->inserted_items-1;i>= 0;i--){
            seq_work = get_tcp_seq(tcp_buf->buffer[i]);
            syslog(LOG_INFO, "resetting %" PRIu32, seq_work);

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
        else{
            TCP_BUF_DYNAMIC_SIZE = TCP_BUF_DYNAMIC_SIZE+TCP_BUF_DYNAMIC_SIZE/2;
        }

    }


    return out_packets_count;
}
