#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>   
#include <linux/cdev.h>
#include <linux/kthread.h>

#include <linux/string.h>
#include <linux/slab.h>

#include <linux/delay.h>

#define BUFFER_SIZE 100 * 1024

static struct task_struct *leak_thread;

int memory_leak_thread(void *data) {
    int counter = 1;
    while (!kthread_should_stop()) {
        void *ptr = kzalloc(BUFFER_SIZE, GFP_KERNEL);
        if (ptr == NULL) {
            printk(KERN_INFO "DE - Failed to allocate memory. System may be out of memory.\n");
            return -ENOMEM;
        }

        printk(KERN_INFO "DE - Allocated 10Kb (%d).\n", counter);

        counter++;
        msleep(500);
    }
    return 0;
}


static int __init donn_module_init(void){
    printk(KERN_INFO "DE - Loading Donn Eitean module.\n");

    leak_thread = kthread_run(memory_leak_thread, NULL, "memory_leak_thread");
    if (IS_ERR(leak_thread)) {
        printk(KERN_ERR "DE - Failed to create memory leak thread.\n");
        return PTR_ERR(leak_thread);
    }

    return 0;
}

static void __exit donn_module_cleanup(void){
    printk(KERN_INFO "Exiting Donn Eitean module.\n");
    if (leak_thread) {
        kthread_stop(leak_thread);
        printk(KERN_INFO "DE - Memory leak thread stopped.\n");
    }
}

module_init(donn_module_init);
module_exit(donn_module_cleanup);

MODULE_AUTHOR("Duncan");
MODULE_LICENSE("GPL");

