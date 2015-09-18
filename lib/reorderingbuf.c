// /*
//  * Licensed under the Apache License, Version 2.0 (the "License");
//  * you may not use this file except in compliance with the License.
//  * You may obtain a copy of the License at:
//  *
//  *     http://www.apache.org/licenses/LICENSE-2.0
//  *
//  * Unless required by applicable law or agreed to in writing, software
//  * distributed under the License is distributed on an "AS IS" BASIS,
//  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  * See the License for the specific language governing permissions and
//  * limitations under the License.
//  */

// #include <config.h>
// #include "reorderingbuf.h"
// #include <inttypes.h>
// #include <stdlib.h>
// #include "coverage.h"
// #include "ofp-util.h"
// #include "ofpbuf.h"
// #include "timeval.h"
// #include "util.h"
// #include "vconn.h"
// #include "vlog.h"


//  #define RDRBUF_CNT 0

// VLOG_DEFINE_THIS_MODULE(reorderingbuf);

// struct mpsdn_tcp_buf {
//     struct ofpbuf *buffer;
//     int count;
//     int expected_sequence;
//     long long int timeout;
// };

// struct reorderingbuf {
//     struct mpsdn_tcp_buf buffers[RDRBUF_CNT];
// };

// int
// reorderingbuf_capacity(void)
// {
//     return RDRBUF_CNT;
// }

// struct reorderingbuf *
// reorderingbuf_create(void)
// {
//     return xzalloc(sizeof *reorderingbuf_create());
// }


// void mpsdn_tcp_buf_delete(struct mpsdn_tcp_buf * buf){
//     size_t i;
//     for(i=0;i<buf->size;i++){
//         ofpbuf_delete(buf->buffer[i]);   
//     }
//     free(buf);
// }

// void
// reorderingbuf_destroy(struct reorderingbuf *pb)
// {
//     if (buffers) {
//         size_t i;

//         for (i = 0; i < RDRBUF_CNT; i++) {
//             mpsdn_tcp_buf_delete(&pb->buffers[i]);
//         }

//         free(pb);
//     }
// }


// uint32_t
// reorderingbuf_save(struct reorderingbuf *pb, const void *buffer, size_t buffer_size,
//             ofp_port_t in_port)
// {
//     struct packet *p = &pb->packets[pb->buffer_idx];
//     pb->buffer_idx = (pb->buffer_idx + 1) & PKTBUF_MASK;
//     if (p->buffer) {
//         if (time_msec() < p->timeout) {
//             return UINT32_MAX;
//         }
//         ofpbuf_delete(p->buffer);
//     }

//     /* Don't use maximum cookie value since all-1-bits ID is special. */
//     if (++p->cookie >= COOKIE_MAX) {
//         p->cookie = 0;
//     }

//     /* Use 2 bytes of headroom to 32-bit align the L3 header. */
//     p->buffer = ofpbuf_clone_data_with_headroom(buffer, buffer_size, 2);

//     p->timeout = time_msec() + OVERWRITE_MSECS;
//     p->in_port = in_port;
//     return make_id(p - pb->packets, p->cookie);
// }

// enum ofperr
// reorderingbuf_retrieve(struct reorderingbuf *pb, uint32_t id, struct ofpbuf **bufferp,
//                 ofp_port_t *in_port)
// {
//     static struct vlog_rate_limit rl = VLOG_RATE_LIMIT_INIT(1, 20);
//     struct packet *p;
//     enum ofperr error;

//     if (id == UINT32_MAX) {
//         error = 0;
//         goto error;
//     }

//     if (!pb) {
//         VLOG_WARN_RL(&rl, "attempt to send buffered packet via connection "
//                      "without buffers");
//         error = OFPERR_OFPBRC_BUFFER_UNKNOWN;
//         goto error;
//     }

//     p = &pb->packets[id & PKTBUF_MASK];
//     if (p->cookie == id >> PKTBUF_BITS) {
//         struct ofpbuf *buffer = p->buffer;
//         if (buffer) {
//             *bufferp = buffer;
//             if (in_port) {
//                 *in_port = p->in_port;
//             }
//             p->buffer = NULL;
//             COVERAGE_INC(reorderingbuf_retrieved);
//             return 0;
//         } else {
//             COVERAGE_INC(reorderingbuf_reuse_error);
//             VLOG_WARN_RL(&rl, "attempt to reuse buffer %08"PRIx32, id);
//             error = OFPERR_OFPBRC_BUFFER_EMPTY;
//         }
//     } else if (id >> PKTBUF_BITS != COOKIE_MAX) {
//         COVERAGE_INC(reorderingbuf_buffer_unknown);
//         VLOG_WARN_RL(&rl, "cookie mismatch: %08"PRIx32" != %08"PRIx32,
//                      id, (id & PKTBUF_MASK) | (p->cookie << PKTBUF_BITS));
//         error = OFPERR_OFPBRC_BUFFER_UNKNOWN;
//     } else {
//         COVERAGE_INC(reorderingbuf_null_cookie);
//         VLOG_INFO_RL(&rl, "Received null cookie %08"PRIx32" (this is normal "
//                      "if the switch was recently in fail-open mode)", id);
//         error = 0;
//     }
// error:
//     *bufferp = NULL;
//     if (in_port) {
//         *in_port = OFPP_NONE;
//     }
//     return error;
// }

// void
// reorderingbuf_discard(struct reorderingbuf *pb, uint32_t id)
// {
//     struct packet *p = &pb->packets[id & PKTBUF_MASK];
//     if (p->cookie == id >> PKTBUF_BITS) {
//         ofpbuf_delete(p->buffer);
//         p->buffer = NULL;
//     }
// }

// unsigned int
// reorderingbuf_count_reordering_queues(const struct reorderingbuf *pb)
// {
//     return RDRBUF_CNT;
// }
