#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/blkdev.h>
#include <linux/blk-mq.h>
#include <linux/nvme.h>

#include "../include/ssd_detector.h"
#include "../include/queue_manager.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Fayssal CHOKRI");
MODULE_DESCRIPTION("NVMe Adaptive I/O Scheduler");
MODULE_VERSION("0.1");

static int __init nvme_adaptive_io_init(void)
{
    pr_info("NVMe Adaptive I/O Scheduler: Initializing\n");
    
    if (init_ssd_detector() < 0) {
        pr_err("Failed to initialize SSD detector\n");
        return -EINVAL;
    }

    if (init_queue_manager() < 0) {
        pr_err("Failed to initialize queue manager\n");
        cleanup_ssd_detector();
        return -EINVAL;
    }

    pr_info("NVMe Adaptive I/O Scheduler: Initialized successfully\n");
    return 0;
}

static void __exit nvme_adaptive_io_exit(void)
{
    pr_info("NVMe Adaptive I/O Scheduler: Exiting\n");
    cleanup_queue_manager();
    cleanup_ssd_detector();
}

module_init(nvme_adaptive_io_init);
module_exit(nvme_adaptive_io_exit);

