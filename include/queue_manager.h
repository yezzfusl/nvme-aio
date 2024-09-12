#ifndef QUEUE_MANAGER_H
#define QUEUE_MANAGER_H

#include <linux/types.h>

int init_queue_manager(void);
void cleanup_queue_manager(void);
unsigned int get_current_queue_depth(void);
void set_queue_depth(unsigned int new_depth);
void process_io_request(int32_t io_size);

#endif // QUEUE_MANAGER_H

