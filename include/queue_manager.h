#ifndef QUEUE_MANAGER_H
#define QUEUE_MANAGER_H

int init_queue_manager(void);
void cleanup_queue_manager(void);
unsigned int get_current_queue_depth(void);
void set_queue_depth(unsigned int new_depth);

#endif // QUEUE_MANAGER_H

