#include <stddef.h>
#include <stdint.h>
#include "ofp-errors.h"


#define RDBUF_MAXSIZE 100
#define PKT_BUF_MAXSIZE 1000

struct tcp_buf * create_new_tcp_buf(uint32_t flow_id);

void delete_tcp_buf(struct tcp_buf *tcp_buffer);

struct tcp_buf * get_tcp_buf(uint32_t flow_id);

void insert_descending_order(struct tcp_buf *tcp_buffer, struct ofpbuf *pkt);

uint32_t get_next_seqnum(struct tcp_buf *tcp_buffer, int seq, struct ofpbuf *packet, bool loss_recovery);

int get_packet_list(struct ofpbuf *out_packets[], struct ofpbuf * packet, uint32_t flow_id, uint32_t in_port);