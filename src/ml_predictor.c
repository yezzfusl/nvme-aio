#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/random.h>
#include "../include/ml_predictor.h"

#define HISTORY_SIZE 1000
#define FEATURE_SIZE 5

static int32_t *io_history;
static int history_index;

int init_ml_predictor(void)
{
    pr_info("Initializing ML predictor\n");
    io_history = kmalloc(HISTORY_SIZE * sizeof(int32_t), GFP_KERNEL);
    if (!io_history) {
        pr_err("Failed to allocate memory for I/O history\n");
        return -ENOMEM;
    }
    history_index = 0;
    return 0;
}

void cleanup_ml_predictor(void)
{
    pr_info("Cleaning up ML predictor\n");
    kfree(io_history);
}

void record_io_event(int32_t io_size)
{
    io_history[history_index] = io_size;
    history_index = (history_index + 1) % HISTORY_SIZE;
}

int32_t predict_next_io_size(void)
{
    // This is a very basic prediction model
    int32_t sum = 0;
    int count = 0;
    for (int i = 0; i < FEATURE_SIZE; i++) {
        int index = (history_index - i - 1 + HISTORY_SIZE) % HISTORY_SIZE;
        if (io_history[index] != 0) {
            sum += io_history[index];
            count++;
        }
    }
    return count > 0 ? sum / count : 4096; // Default to 4KB if no history
}

