/*
 * Copyright (c) 2009, 2010, 2011, 2012, 2013, 2014 Nicira, Inc.
 * Copyright (c) 2013 Simon Horman
 *
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
#include <config.h>
#include "packets.h"
#include "odp-execute.h"
#include <linux/openvswitch.h>
#include <stdlib.h>
#include <string.h>
#include "dpif.h"
#include "netlink.h"
#include "ofpbuf.h"
#include "odp-util.h"
#include "packets.h"
#include "flow.h"
#include "unaligned.h"
#include "util.h"
#include "ofp-print.h"
#include "dynamic-string.h"
#include "reorderingbuf.h"

static void
odp_eth_set_addrs(struct ofpbuf *packet,
                  const struct ovs_key_ethernet *eth_key)
{
    struct eth_header *eh = ofpbuf_l2(packet);

    if (eh) {
        memcpy(eh->eth_src, eth_key->eth_src, sizeof eh->eth_src);
        memcpy(eh->eth_dst, eth_key->eth_dst, sizeof eh->eth_dst);
    }
}

static void
odp_set_tunnel_action(const struct nlattr *a, struct flow_tnl *tun_key)
{
    enum odp_key_fitness fitness;

    fitness = odp_tun_key_from_attr(a, tun_key);
    ovs_assert(fitness != ODP_FIT_ERROR);
}

static void
set_arp(struct ofpbuf *packet, const struct ovs_key_arp *arp_key)
{
    struct arp_eth_header *arp = ofpbuf_l3(packet);

    arp->ar_op = arp_key->arp_op;
    memcpy(arp->ar_sha, arp_key->arp_sha, ETH_ADDR_LEN);
    put_16aligned_be32(&arp->ar_spa, arp_key->arp_sip);
    memcpy(arp->ar_tha, arp_key->arp_tha, ETH_ADDR_LEN);
    put_16aligned_be32(&arp->ar_tpa, arp_key->arp_tip);
}

static void
odp_execute_set_action(struct ofpbuf *packet, const struct nlattr *a,
                       struct pkt_metadata *md)
{
    enum ovs_key_attr type = nl_attr_type(a);
    const struct ovs_key_ipv4 *ipv4_key;
    const struct ovs_key_ipv6 *ipv6_key;
    const struct ovs_key_tcp *tcp_key;
    const struct ovs_key_udp *udp_key;
    const struct ovs_key_sctp *sctp_key;

   

    switch (type) {
    case OVS_KEY_ATTR_PRIORITY:
        md->skb_priority = nl_attr_get_u32(a);
        break;

    case OVS_KEY_ATTR_TUNNEL:
        odp_set_tunnel_action(a, &md->tunnel);
        break;

    case OVS_KEY_ATTR_SKB_MARK:
        md->pkt_mark = nl_attr_get_u32(a);
        break;

    case OVS_KEY_ATTR_ETHERNET:
        odp_eth_set_addrs(packet,
                          nl_attr_get_unspec(a, sizeof(struct ovs_key_ethernet)));
        break;

    case OVS_KEY_ATTR_IPV4:
        ipv4_key = nl_attr_get_unspec(a, sizeof(struct ovs_key_ipv4));
        packet_set_ipv4(packet, ipv4_key->ipv4_src, ipv4_key->ipv4_dst,
                        ipv4_key->ipv4_tos, ipv4_key->ipv4_ttl);
        break;

    case OVS_KEY_ATTR_IPV6:
        ipv6_key = nl_attr_get_unspec(a, sizeof(struct ovs_key_ipv6));
        packet_set_ipv6(packet, ipv6_key->ipv6_proto, ipv6_key->ipv6_src,
                        ipv6_key->ipv6_dst, ipv6_key->ipv6_tclass,
                        ipv6_key->ipv6_label, ipv6_key->ipv6_hlimit);
        break;

    case OVS_KEY_ATTR_TCP:
        tcp_key = nl_attr_get_unspec(a, sizeof(struct ovs_key_tcp));
        packet_set_tcp_port(packet, tcp_key->tcp_src, tcp_key->tcp_dst);
        break;

    case OVS_KEY_ATTR_UDP:
        udp_key = nl_attr_get_unspec(a, sizeof(struct ovs_key_udp));
        packet_set_udp_port(packet, udp_key->udp_src, udp_key->udp_dst);
        break;

    case OVS_KEY_ATTR_SCTP:
        sctp_key = nl_attr_get_unspec(a, sizeof(struct ovs_key_sctp));
        packet_set_sctp_port(packet, sctp_key->sctp_src, sctp_key->sctp_dst);
        break;

    case OVS_KEY_ATTR_MPLS:
         set_mpls_lse(packet, nl_attr_get_be32(a));
         break;

    case OVS_KEY_ATTR_ARP:
        set_arp(packet, nl_attr_get_unspec(a, sizeof(struct ovs_key_arp)));
        break;

    case OVS_KEY_ATTR_DP_HASH:
        md->dp_hash = nl_attr_get_u32(a);
        break;

    case OVS_KEY_ATTR_RECIRC_ID:
        md->recirc_id = nl_attr_get_u32(a);
        break;

    case OVS_KEY_ATTR_UNSPEC:
    case OVS_KEY_ATTR_ENCAP:
    case OVS_KEY_ATTR_ETHERTYPE:
    case OVS_KEY_ATTR_IN_PORT:
    case OVS_KEY_ATTR_VLAN:
    case OVS_KEY_ATTR_ICMP:
    case OVS_KEY_ATTR_ICMPV6:
    case OVS_KEY_ATTR_ND:
    case OVS_KEY_ATTR_TCP_FLAGS:
    case __OVS_KEY_ATTR_MAX:
    default:
        OVS_NOT_REACHED();
    }


}

static void
odp_execute_actions__(void *dp, struct ofpbuf *packet, bool steal,
                      struct pkt_metadata *,
                      const struct nlattr *actions, size_t actions_len,
                      odp_execute_cb dp_execute_action, bool more_actions);

static void
odp_execute_sample(void *dp, struct ofpbuf *packet, bool steal,
                   struct pkt_metadata *md, const struct nlattr *action,
                   odp_execute_cb dp_execute_action, bool more_actions)
{
    const struct nlattr *subactions = NULL;
    const struct nlattr *a;
    size_t left;

    NL_NESTED_FOR_EACH_UNSAFE (a, left, action) {
        int type = nl_attr_type(a);

        switch ((enum ovs_sample_attr) type) {
        case OVS_SAMPLE_ATTR_PROBABILITY:
            if (random_uint32() >= nl_attr_get_u32(a)) {
                return;
            }
            break;

        case OVS_SAMPLE_ATTR_ACTIONS:
            subactions = a;
            break;

        case OVS_SAMPLE_ATTR_UNSPEC:
        case __OVS_SAMPLE_ATTR_MAX:
        default:
            OVS_NOT_REACHED();
        }
    }

    odp_execute_actions__(dp, packet, steal, md, nl_attr_get(subactions),
                          nl_attr_get_size(subactions), dp_execute_action,
                          more_actions);
}

static void
odp_execute_actions__(void *dp, struct ofpbuf *packet, bool steal,
                      struct pkt_metadata *md,
                      const struct nlattr *actions, size_t actions_len,
                      odp_execute_cb dp_execute_action, bool more_actions)
{
    const struct nlattr *a;
    unsigned int left;




    NL_ATTR_FOR_EACH_UNSAFE (a, left, actions, actions_len) {
        int type = nl_attr_type(a);

        switch ((enum ovs_action_attr) type) {
            /* These only make sense in the context of a datapath. */
        case OVS_ACTION_ATTR_OUTPUT:
        case OVS_ACTION_ATTR_USERSPACE:
        case OVS_ACTION_ATTR_RECIRC:
            if (dp_execute_action) {
                /* Allow 'dp_execute_action' to steal the packet data if we do
                 * not need it any more. */
                bool may_steal = steal && (!more_actions
                                           && left <= NLA_ALIGN(a->nla_len)
                                           && type != OVS_ACTION_ATTR_RECIRC);
                dp_execute_action(dp, packet, md, a, may_steal);
            }
            break;

        case OVS_ACTION_ATTR_HASH: {
            const struct ovs_action_hash *hash_act = nl_attr_get(a);

            /* Calculate a hash value directly.  This might not match the
             * value computed by the datapath, but it is much less expensive,
             * and the current use case (bonding) does not require a strict
             * match to work properly. */
            if (hash_act->hash_alg == OVS_HASH_ALG_L4) {
                struct flow flow;
                uint32_t hash;

                flow_extract(packet, md, &flow);
                hash = flow_hash_5tuple(&flow, hash_act->hash_basis);
                md->dp_hash = hash ? hash : 1;
            } else {
                /* Assert on unknown hash algorithm.  */
                OVS_NOT_REACHED();
            }
            break;
        }

        case OVS_ACTION_ATTR_PUSH_VLAN: {
            const struct ovs_action_push_vlan *vlan = nl_attr_get(a);
            eth_push_vlan(packet, htons(ETH_TYPE_VLAN), vlan->vlan_tci);
            break;
        }

        case OVS_ACTION_ATTR_POP_VLAN:
            eth_pop_vlan(packet);
            break;

        case OVS_ACTION_ATTR_PUSH_MPLS: {
            const struct ovs_action_push_mpls *mpls = nl_attr_get(a);
            push_mpls(packet, mpls->mpls_ethertype, mpls->mpls_lse);
            break;
         }

        case OVS_ACTION_ATTR_POP_MPLS:
            pop_mpls(packet, nl_attr_get_be16(a));
            break;

        case OVS_ACTION_ATTR_SET:
            odp_execute_set_action(packet, nl_attr_get(a), md);
            break;

        case OVS_ACTION_ATTR_SAMPLE:
            odp_execute_sample(dp, packet, steal, md, a, dp_execute_action,
                               more_actions || left > NLA_ALIGN(a->nla_len));
            break;

        case OVS_ACTION_ATTR_UNSPEC:
        case __OVS_ACTION_ATTR_MAX:
            OVS_NOT_REACHED();
        }
    }
}


static int inserted_items = 0;
static int expected_seqnum  = -1;
static struct ofpbuf *minibuffer[1000];
pthread_mutex_t mutex_lock;
    



void
odp_execute_buffer_actions(void *dp, struct ofpbuf *packet, bool steal,
                    struct pkt_metadata *md,
                    const struct nlattr *actions, size_t actions_len,
                    odp_execute_cb dp_execute_action, uint32_t in_port, uint32_t flow_id)
{
    uint8_t tcp_flags;
    struct tcp_header *tcp;
    uint32_t seq;
    int i;
    uint32_t seq_work;



    struct ofpbuf *out_packets[MAX_RDB_SIZE];
    struct ofpbuf *buf_pkt;
    int out_packets_size;

    if(packet && get_ip_proto(ofpbuf_data(packet), ofpbuf_size(packet)) == IPPROTO_TCP){


        out_packets_size = get_packet_list(out_packets, packet, flow_id);
        syslog(LOG_INFO, "%d packets to be send this round", out_packets_size);
        for(i=0; i<out_packets_size;i++){
            odp_execute_actions__(dp, out_packets[i], steal, md, actions, actions_len,
                  dp_execute_action, false);            
        }

        // tcp = ofpbuf_l4(packet);
        // tcp_flags = TCP_FLAGS(tcp->tcp_ctl);    
        // seq = get_tcp_seq(packet);


        // if (tcp_flags & TCP_SYN){
        //     pthread_mutex_lock(&mutex_lock);
        //     expected_seqnum = seq+1;
        //     pthread_mutex_unlock(&mutex_lock);

        //     syslog(LOG_INFO, "SYN_seq %"PRIu32 " new_expected %"PRIu32 " size %d" , seq, expected_seqnum, inserted_items);
            // odp_execute_actions__(dp, packet, steal, md, actions, actions_len,
            //       dp_execute_action, false);
        //     pthread_mutex_lock(&mutex_lock);
        //     inserted_items = 0;
        //     pthread_mutex_unlock(&mutex_lock);

        //     // TODO: delete buffer ofpbufs here
        //     return;
        // }



        // if(seq <= expected_seqnum){
            // syslog(LOG_INFO, "sending %"PRIu32 " expected %" PRIu32 " port %"PRIu32 " size %d", seq, expected_seqnum, in_port, inserted_items);

            // odp_execute_actions__(dp, packet, steal, md, actions, actions_len,
            //       dp_execute_action, false);

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
    }

    // Not TCP, just send out
    else{
        odp_execute_actions__(dp, packet, steal, md, actions, actions_len,
                          dp_execute_action, false);
    }

    if (!actions_len && steal) {
        /* Drop action. */
        ofpbuf_delete(packet);
    }
}





void
odp_execute_actions(void *dp, struct ofpbuf *packet, bool steal,
                    struct pkt_metadata *md,
                    const struct nlattr *actions, size_t actions_len,
                    odp_execute_cb dp_execute_action)   
{

    odp_execute_actions__(dp, packet, steal, md, actions, actions_len,
                          dp_execute_action, false);
    
    if (!actions_len && steal) {
        /* Drop action. */
        ofpbuf_delete(packet);
    }
}


void
odp_execute_mpsdn(void *dp, struct ofpbuf *packet, bool steal,
                    struct pkt_metadata *md,
                    const struct nlattr *actions, size_t actions_len,
                    odp_execute_cb dp_execute_action)
{

    odp_execute_actions__(dp, packet, steal, md, actions, actions_len,
        dp_execute_action, false);

    if (!actions_len && steal) {
        /* Drop action. */
        ofpbuf_delete(packet);
    }
}
