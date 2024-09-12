#include <linux/kernel.h>
#include <linux/random.h>
#include "../include/wear_leveling.h"

#define INITIAL_WEAR_THRESHOLD 1000
#define MAX_WEAR_THRESHOLD 10000
#define MIN_WEAR_THRESHOLD 100

static unsigned int wear_threshold = INITIAL_WEAR_THRESHOLD;
static unsigned long total_writes = 0;
static unsigned long total_reads = 0;

int init_wear_leveling(void)
{
    pr_info("Initializing wear leveling\n");
    return 0;
}

void cleanup_wear_leveling(void)
{
    pr_info("Cleaning up wear leveling\n");
}

void update_io_stats(bool is_write, unsigned int size)
{
    if (is_write) {
        total_writes += size;
    } else {
        total_reads += size;
    }

    // Adjust wear threshold based on write/read ratio
    if (total_reads + total_writes > 1000000) {  // Adjust every 1MB of I/O
        unsigned long write_percentage = (total_writes * 100) / (total_reads + total_writes);
        
        if (write_percentage > 60) {
            wear_threshold = (wear_threshold * 11) / 10;  // Increase by 10%
        } else if (write_percentage < 40) {
            wear_threshold = (wear_threshold * 9) / 10;   // Decrease by 10%
        }

        // Ensure wear threshold stays within bounds
        if (wear_threshold > MAX_WEAR_THRESHOLD) {
            wear_threshold = MAX_WEAR_THRESHOLD;
        } else if (wear_threshold < MIN_WEAR_THRESHOLD) {
            wear_threshold = MIN_WEAR_THRESHOLD;
        }

        total_reads = 0;
        total_writes = 0;
    }
}

bool should_redirect_write(void)
{
    unsigned int random_value;
    get_random_bytes(&random_value, sizeof(random_value));
    return (random_value % wear_threshold) == 0;
}

