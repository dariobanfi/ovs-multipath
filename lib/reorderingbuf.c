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

#define RDBUF_MAXSIZE 10
#define RDBUF_CNT 0
#define TCP_BUF_MAXSIZE 0

VLOG_DEFINE_THIS_MODULE(reorderingbuf);

struct mpsdn_tcp_buf {
    uint32_t flow_id;
    struct ofpbuf * buffer[TCP_BUF_MAXSIZE];
    uint32_t expected_seqnum;
    long long int timeout;
    int inserted_items;
};

struct mpsdn_tcp_buf * rdb[RDBUF_MAXSIZE];


struct mpsdn_tcp_buf * create_new_tcp_buf(uint32_t flow_id){
    struct mpsdn_tcp_buf * tcp_buf;
    tcp_buf->flow_id = flow_id;
    tcp_buf->inserted_items = 0;;
    tcp_buf->expected_seqnum = 0;
    tcp_buf->timeout = time_msec();
    return tcp_buf;
}


struct mpsdn_tcp_buf * get_mpsdn_tcp_buf(uint32_t flow_id){
    int i;
    if(rdb == NULL){
        return create_new_tcp_buf(flow_id);
    }
    else{
        for(i=0;i<RDBUF_CNT;i++){
            if(rdb[i]->flow_id == flow_id){
                return rdb[i];
            }
        }
        return create_new_tcp_buf(flow_id);
    }
}

int get_packet_list(struct ofpbuf *out_packets[MAX_RDB_SIZE], struct ofpbuf * packet, uint32_t flow_id){


    struct mpsdn_tcp_buf * tcpbuf;
    tcpbuf = get_mpsdn_tcp_buf(flow_id);

    uint8_t tcp_flags;
    struct tcp_header *tcp;
    uint32_t seq;
    int i, out_packets_count;
    uint32_t seq_work;

    tcp = ofpbuf_l4(packet);
    tcp_flags = TCP_FLAGS(tcp->tcp_ctl);    
    seq = get_tcp_seq(packet);
    out_packets_count = 0;


    if (tcp_flags & TCP_SYN){
        tcpbuf->expected_seqnum = seq+1;

        syslog(LOG_INFO, "SYN_seq %"PRIu32 " new_expected %"PRIu32 " size %d" , seq, tcpbuf->expected_seqnum, tcpbuf->inserted_items);
        out_packets[0] = packet;
        out_packets_count++;
        tcpbuf->inserted_items = 0;

        // TODO: delete existing buffer ofpbufs here
    }



    // if(seq <= expected_seqnum){
    //     syslog(LOG_INFO, "sending %"PRIu32 " expected %" PRIu32 " port %"PRIu32 " size %d", seq, expected_seqnum, in_port, inserted_items);

    //     odp_execute_actions__(dp, packet, steal, md, actions, actions_len,
    //           dp_execute_action, false);

    //     if(seq == expected_seqnum){
    //         pthread_mutex_lock(&mutex_lock);
    //         expected_seqnum = get_next_seqnum(expected_seqnum, packet);
    //         pthread_mutex_unlock(&mutex_lock);
    //     }


    //     // Check if there are packets waiting to be sent
    //     int removed_items = 0;
    //     for(i=inserted_items-1;i>= 0;i--){
    //         seq_work = get_tcp_seq(minibuffer[i]);


    //         if(seq_work <= expected_seqnum){
    //             syslog(LOG_INFO, "outbuffing %" PRIu32 " expected %" PRIu32 " size %d", seq_work, expected_seqnum, inserted_items - removed_items);
    //             removed_items++;
    //             odp_execute_actions__(dp, minibuffer[i], steal, md, actions, actions_len,
    //                 dp_execute_action, false);
    //             if(seq_work == expected_seqnum){
    //                 pthread_mutex_lock(&mutex_lock);
    //                 expected_seqnum = get_next_seqnum(expected_seqnum, minibuffer[i]);
    //                 pthread_mutex_unlock(&mutex_lock);
    //             }

    //         }
    //     }
    //     pthread_mutex_lock(&mutex_lock);
    //     inserted_items = inserted_items - removed_items;
    //     pthread_mutex_unlock(&mutex_lock);

    // }
    // //Buffer full
    // else if(inserted_items<400){
    //     syslog(LOG_INFO, "buffering %"PRIu32 " expected %" PRIu32 " port %"PRIu32 " size %d", seq, expected_seqnum, in_port, inserted_items);
    //     buf_pkt = ofpbuf_clone(packet);
    //     insert_descending_order(buf_pkt);
    // }

    // else{
    //     syslog(LOG_INFO, "!! -- BUFFER FULL -- !!");
    //     seq_work = get_tcp_seq(minibuffer[inserted_items-1]);

    //     // If inc packet has smallest seq
    //     if(seq<seq_work){
    //         syslog(LOG_INFO, "resetting %" PRIu32 " - sending out latest packet and emptying buffer", seq);
    //         // Send out
    //         odp_execute_actions__(dp, packet, steal, md, actions, actions_len,
    //             dp_execute_action, false);

    //         for(i=inserted_items-1;i>= 0;i--){
    //             seq_work = get_tcp_seq(minibuffer[i]);
    //             syslog(LOG_INFO, "resetting %" PRIu32, seq_work);
    //             odp_execute_actions__(dp, minibuffer[i], steal, md, actions, actions_len,
    //                 dp_execute_action, false);
    //             if(i==0)
    //                 expected_seqnum = get_tcp_seq(minibuffer[i])+1448;
    //         }

    //         pthread_mutex_lock(&mutex_lock);
    //         inserted_items=0;
    //         pthread_mutex_unlock(&mutex_lock);

    //     }
    //     // Buf packet is smaller
    //     else{

    //         syslog(LOG_INFO, "resetting %" PRIu32 " - sending lowest buf packet and emptying", get_tcp_seq(minibuffer[inserted_items-1]));
    //         odp_execute_actions__(dp, minibuffer[inserted_items-1], steal, md, actions, actions_len,
    //             dp_execute_action, false);
        
    //         pthread_mutex_lock(&mutex_lock);
    //         inserted_items--;
    //         pthread_mutex_unlock(&mutex_lock);

          
    //         buf_pkt = ofpbuf_clone(packet);
    //         insert_descending_order(buf_pkt);

    //         for(i=inserted_items-1;i>= 0;i--){
    //             seq_work = get_tcp_seq(minibuffer[i]);
    //             syslog(LOG_INFO, "resetting %" PRIu32, seq_work);
    //             odp_execute_actions__(dp, minibuffer[i], steal, md, actions, actions_len,
    //                 dp_execute_action, false);
    //             if(i==0)
    //                 expected_seqnum = get_tcp_seq(minibuffer[i])+1448;

    //         }

    //         pthread_mutex_lock(&mutex_lock);
    //         inserted_items=0;
    //         pthread_mutex_unlock(&mutex_lock);
    //     }

    //     expected_seqnum += (get_tcp_payload_size(packet)*50);

    // }


    return out_packets_count;
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


int get_next_seqnum(int seq, struct ofpbuf *packet, bool loss_recovery){
    unsigned int size;
    uint8_t tcp_flags;
    struct tcp_header *tcp;

    tcp = ofpbuf_l4(packet);
    tcp_flags = TCP_FLAGS(tcp->tcp_ctl);    
    size = get_tcp_payload_size(packet);

    // Sliding the expected seq forward to recover from the probable burst
    // of losts packets
    if(loss_recovery){
        return seq + (get_tcp_payload_size(packet)*50);
    }
    else {
        if(tcp_flags & TCP_FIN){
            syslog(LOG_INFO, "packet above was FIN");
            return seq + size + 1;
        }
        else{
            return seq + size;
        }
    }
}
