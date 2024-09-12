#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/blkdev.h>
#include <linux/blk-mq.h>
#include <linux/nvme.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Fayssal CHOKRI");
MODULE_DESCRIPTION("NVMe Adaptive I/O Scheduler");
MODULE_VERSION("0.1");

static int __init nvme_adaptive_io_init(void)
{
    pr_info("NVMe Adaptive I/O Scheduler: Initializing\n");
    // TODO: Implement initialization logic
    return 0;
}

static void __exit nvme_adaptive_io_exit(void)
{
    pr_info("NVMe Adaptive I/O Scheduler: Exiting\n");
    // TODO: Implement cleanup logic
}

module_init(nvme_adaptive_io_init);
module_exit(nvme_adaptive_io_exit);

