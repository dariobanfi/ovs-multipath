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

struct mpsdn_tcp_buf {  
    uint32_t flow_id;
    struct ofpbuf * buffer[PKT_BUF_MAXSIZE];
    uint32_t expected_seqnum;
    long long int timeout;
    int inserted_items;
    bool fin_state;
};

struct mpsdn_tcp_buf * rdb[RDBUF_MAXSIZE];
int RDB_COUNT = 0;
int TCP_BUF_DYNAMIC_SIZE = 100;

struct mpsdn_tcp_buf * create_new_tcp_buf(uint32_t flow_id){
    struct mpsdn_tcp_buf * tcp_buf;
    RDB_COUNT++;
    tcp_buf = malloc (sizeof (struct mpsdn_tcp_buf));
    tcp_buf->flow_id = flow_id;
    tcp_buf->inserted_items = 0;;
    tcp_buf->expected_seqnum = 0;
    tcp_buf->timeout = time_msec();
    tcp_buf->fin_state = false;
    return tcp_buf;
}


void delete_tcp_buf(struct mpsdn_tcp_buf *tcp_buffer){
    int i,j;
    int del_index;

    syslog(LOG_INFO, "Deleting tcp_buf");

    del_index = -1;
    for(i=0;i<RDB_COUNT;i++){
        if(!rdb[i]){
            syslog(LOG_INFO, "FATAL ERROR! BUFF WAS NULL index %d", i);
        }
        else if(rdb[i] == tcp_buffer){
            // Deleting packets
            // for(j=0;j<PKT_BUF_MAXSIZE;j++){
                // if(tcp_buffer->buffer[j]){
                    // ofpbuf_delete(tcp_buffer->buffer[j]); // TODO: Segfault sometimes.. Is it really necessary?  
                // }
            // }
            del_index = i;
            free(tcp_buffer);
            break;

        }
    }

    // Compact array
    if(del_index!=-i-1){
        RDB_COUNT--;
        for(i=del_index;i<RDB_COUNT;i++){
             rdb[i] = rdb[i+1];
        }
    }
}


struct mpsdn_tcp_buf * get_mpsdn_tcp_buf(uint32_t flow_id){
    int i;
    struct mpsdn_tcp_buf * new_buf;
    if(RDB_COUNT == 0){
        syslog(LOG_INFO, "Creating new tcp_buf, existing %d", RDB_COUNT);
        new_buf = create_new_tcp_buf(flow_id);
        rdb[RDB_COUNT-1] = new_buf;
        return new_buf;
    }
    else{
        for(i=0;i<RDB_COUNT;i++){
            if(!rdb[i]){
                syslog(LOG_INFO, "FATAL ERROR! BUFF WAS NULL index %d", i);
            }
            else if(rdb[i]->flow_id == flow_id){
                // syslog(LOG_INFO, "Found existing tcp_buf for flow_id %"PRIu32, flow_id);
                return rdb[i];
            }
        }

        // If existing tcp_buf is not found
        syslog(LOG_INFO, "Creating new tcp_buf, existing %d", RDB_COUNT);
        new_buf = create_new_tcp_buf(flow_id);
        rdb[RDB_COUNT-1] = new_buf;
        return new_buf;
    }
}


void insert_descending_order(struct mpsdn_tcp_buf *tcp_buffer, struct ofpbuf *pkt){

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
        while((seq_new < seq_buf) && (index<tcp_buffer->inserted_items)){
            index++;
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
}


uint32_t get_next_seqnum(struct mpsdn_tcp_buf *tcp_buffer, int seq, struct ofpbuf *packet, bool loss_recovery){
    unsigned int size;
    uint8_t tcp_flags;
    struct tcp_header *tcp;

    tcp = ofpbuf_l4(packet);
    tcp_flags = TCP_FLAGS(tcp->tcp_ctl);    
    size = get_tcp_payload_size(packet);

    // Sliding the expected seq forward to recover from the probable burst
    // of losts packets
    if(loss_recovery){
        return (seq + (get_tcp_payload_size(packet)*50)) % 0xFFFFFFFF;
    }
    else {
        if(tcp_flags & TCP_FIN){
            syslog(LOG_INFO, "packet above was FIN");
            tcp_buffer->fin_state = true;
            return seq + size + 1 % 0xFFFFFFFF;
        }
        else{
            return (seq + size) % 0xFFFFFFFF;
        }
    }
}


int get_packet_list(struct ofpbuf *out_packets[], struct ofpbuf * packet, uint32_t flow_id){


    struct mpsdn_tcp_buf * tcp_buf;    
    uint8_t tcp_flags;
    struct tcp_header *tcp;
    uint32_t seq;
    int i, out_packets_count;
    uint32_t seq_work;
    struct ofpbuf * buf_pkt;
    int removed_items;



    // Getting the buffer for the flow, or creating a new one if 
    // not existing
    tcp_buf = get_mpsdn_tcp_buf(flow_id);

    tcp = ofpbuf_l4(packet);
    tcp_flags = TCP_FLAGS(tcp->tcp_ctl);    
    seq = get_tcp_seq(packet);

    out_packets_count = 0;


    if (tcp_flags & TCP_SYN){
        tcp_buf->expected_seqnum = seq+1;

        syslog(LOG_INFO, "SYN_seq %" PRIu32 " new_expected %" PRIu32 " size %d" , seq, tcp_buf->expected_seqnum, tcp_buf->inserted_items);
        out_packets[out_packets_count] = packet;
        out_packets_count++;

        // TODO: delete existing buffer ofpbufs here
    }
    else if(tcp_buf->fin_state){

        delete_tcp_buf(tcp_buf);
        out_packets[out_packets_count] = packet;
        out_packets_count++;
    }


    else if(seq <= tcp_buf->expected_seqnum){
        syslog(LOG_INFO, "sending %"PRIu32 " expected %" PRIu32 " size %d", seq, tcp_buf->expected_seqnum, tcp_buf->inserted_items);

        out_packets[out_packets_count] = packet;
        out_packets_count++;

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

    //Buffer full
    else if(tcp_buf->inserted_items<TCP_BUF_DYNAMIC_SIZE){
        syslog(LOG_INFO, "buffering %"PRIu32 " expected %" PRIu32 " size %d", seq, tcp_buf->expected_seqnum, tcp_buf->inserted_items);
        buf_pkt = ofpbuf_clone(packet);
        insert_descending_order(tcp_buf, buf_pkt);
    }

    else{
        syslog(LOG_INFO, "!! -- BUFFER FULL -- !!");
        seq_work = get_tcp_seq(tcp_buf->buffer[tcp_buf->inserted_items-1]);

        // If inc packet has smallest seq
        if(seq<seq_work){
            syslog(LOG_INFO, "resetting %" PRIu32 " - sending out latest packet and emptying buffer", seq);
            // Send out
            out_packets[out_packets_count] = packet;
            out_packets_count++;

            for(i=tcp_buf->inserted_items-1;i>= 0;i--){
                seq_work = get_tcp_seq(tcp_buf->buffer[i]);
                syslog(LOG_INFO, "resetting %" PRIu32, seq_work);

                out_packets[out_packets_count] = tcp_buf->buffer[i];
                out_packets_count++;

                // Adjusting seqnum
                if(i==0){
                    tcp_buf->expected_seqnum = get_next_seqnum(tcp_buf, seq_work, tcp_buf->buffer[i], false);
                }
            }

            tcp_buf->inserted_items=0;

        }
        // Buf packet is smaller
        else{

            syslog(LOG_INFO, "resetting %" PRIu32 " - sending lowest buf packet and emptying", get_tcp_seq(tcp_buf->buffer[tcp_buf->inserted_items-1]));

            out_packets[out_packets_count] = tcp_buf->buffer[tcp_buf->inserted_items-1];
            out_packets_count++;
    
            tcp_buf->inserted_items--;
          
            buf_pkt = ofpbuf_clone(packet);
            insert_descending_order(tcp_buf, buf_pkt);

            for(i=tcp_buf->inserted_items-1;i>= 0;i--){
                seq_work = get_tcp_seq(tcp_buf->buffer[i]);
                syslog(LOG_INFO, "resetting %" PRIu32, seq_work);

                out_packets[out_packets_count] = tcp_buf->buffer[i];
                out_packets_count++;

                if(i==0){
                    tcp_buf->expected_seqnum = get_next_seqnum(tcp_buf, seq_work, tcp_buf->buffer[i], false);
                }

            }

            tcp_buf->inserted_items=0;
        }

        // Sliding 50 sequences forward for recovery
        tcp_buf->expected_seqnum = get_next_seqnum(tcp_buf, tcp_buf->expected_seqnum, packet, true);

    }


    return out_packets_count;
}
