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

// #ifndef REORDERINGBUF_H
// #define REORDERINGBUF_H 1

// #include <stddef.h>
// #include <stdint.h>

// #include "ofp-errors.h"

// struct reorderingbuf;
// struct ofpbuf;

// int reorderingbuf_capacity(void);

// struct reorderingbuf *reorderingbuf_create(void);
// void reorderingbuf_destroy(struct reorderingbuf *);
// uint32_t reorderingbuf_save(struct reorderingbuf *, const void *buffer, size_t buffer_size,
//                      ofp_port_t in_port);
// uint32_t reorderingbuf_get_null(void);
// enum ofperr reorderingbuf_retrieve(struct reorderingbuf *, uint32_t id,
//                             struct ofpbuf **bufferp, ofp_port_t *in_port);
// void reorderingbuf_discard(struct reorderingbuf *, uint32_t id);

// unsigned int reorderingbuf_count_packets(const struct reorderingbuf *);

// #endif /* reorderingbuf.h */
