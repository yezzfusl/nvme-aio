#ifndef WEAR_LEVELING_H
#define WEAR_LEVELING_H

#include <linux/types.h>

int init_wear_leveling(void);
void cleanup_wear_leveling(void);
void update_io_stats(bool is_write, unsigned int size);
bool should_redirect_write(void);

#endif // WEAR_LEVELING_H

