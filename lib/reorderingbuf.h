#include <stddef.h>
#include <stdint.h>
#include "ofp-errors.h"


#define RDBUF_MAXSIZE 100
#define PKT_BUF_MAXSIZE 1000

struct mpsdn_tcp_buf * create_new_tcp_buf(uint32_t flow_id);

void delete_tcp_buf(struct mpsdn_tcp_buf *tcp_buffer);

struct mpsdn_tcp_buf * get_mpsdn_tcp_buf(uint32_t flow_id);

void insert_descending_order(struct mpsdn_tcp_buf *tcp_buffer, struct ofpbuf *pkt);

uint32_t get_next_seqnum(struct mpsdn_tcp_buf *tcp_buffer, int seq, struct ofpbuf *packet, bool loss_recovery);

int get_packet_list(struct ofpbuf *out_packets[], struct ofpbuf * packet, uint32_t flow_id);