#include <stddef.h>
#include <stdint.h>
#include "ofp-errors.h"


/* Max number of TCP reordering buffers in the switch */
#define OVS_TCP_BUFFER_MAXSIZE 100

/* Maximum size of an adaptive TCP Buffer */
#define PKT_BUF_MAXSIZE 1000

/* Max number of onsecutive buffer events that will cause the buffer to be emptied*/
#define CONSECUTIVE_BUFFERING_TREESHOLD 100

/* On a loss event, used to slide the expected sequence forward to better handle multiple
consecutive losses */
#define LOSS_RECOVERY_SLIDING 20

/* Maximum size of a TCP buffer */
#define TCP_BUF_SIZE 400

/* TCP buffer structure */
struct tcp_buf {  
    uint32_t flow_id;
    struct ofpbuf * buffer[PKT_BUF_MAXSIZE];
    uint32_t expected_seqnum;
    long long int timeout;
    int inserted_items;
    int consecutive_buffering_events;
    bool fin_state;
};

/* Creates a TCP buffer with the flow_id key */
struct tcp_buf * create_new_tcp_buf(uint32_t flow_id);

/* Deletes a TCP buffer with the flow_id key */
void delete_tcp_buf(struct tcp_buf *tcp_buffer);

/* Gets the pointer to a TCP Buffer */
struct tcp_buf * get_tcp_buf(uint32_t flow_id);

/* Insertion sort of the packet in the buffer using its seqnum */
void insert_descending_order(struct tcp_buf *tcp_buffer, struct ofpbuf *pkt);

/* Computes the expected sequence number for the next packet */
uint32_t get_next_seqnum(struct tcp_buf *tcp_buffer, int seq, struct ofpbuf *packet, bool loss_recovery);

/* Returns a list of ordered packet
   uint32_t in_port is used only for debugging purposes 
*/
int get_packet_list(struct ofpbuf *out_packets[], struct ofpbuf * packet, uint32_t flow_id, uint32_t in_port);