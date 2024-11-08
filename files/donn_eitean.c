#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>   
#include <linux/cdev.h>

#include <linux/string.h>
#include <linux/slab.h>

#include <linux/delay.h>

#define BUFFER_SIZE 10 * 1024 * 1024

static int __init donn_module_init(void){
    printk(KERN_INFO "DE - Loading Donn Eitean module.\n");

    while(1){
        void* ptr = kzalloc(BUFFER_SIZE,  GFP_KERNEL);
        if(ptr == NULL){
            printk(KERN_INFO "DE - Failed to allocate memory for Donn Eitean module.\n");
            return -ENOMEM;
        }

        printk(KERN_INFO "DE - Allocated 10mb with kzalloc.\n");

        msleep(500);
    }

    return 0;
}

static void __exit donn_module_cleanup(void){
    printk(KERN_INFO "Exiting Donn Eitean module.\n");
}

module_init(donn_module_init);
module_exit(donn_module_cleanup);

MODULE_AUTHOR("Duncan");
MODULE_LICENSE("GPL");

