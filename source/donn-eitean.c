#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>   
#include <linux/cdev.h> 


static dev_t donn_dev;
struct cdev donn_cdev;
static char buffer[64];

struct file_operations donn_fops = {
    .owner = THIS_MODULE,
};

static int __init donn_module_init(void)
{
    printk(KERN_INFO "Loading Donn Eitean module.\n");

    alloc_chrdev_region(&donn_dev, 0, 1, "donn_dev");
    printk(KERN_INFO "%s\n", format_dev_t(buffer, donn_dev));

    cdev_init(&donn_cdev, &donn_fops);
    donn_cdev.owner = THIS_MODULE;
    cdev_add(&donn_cdev, donn_dev, 1);

    return 0;
}

static void __exit donn_module_cleanup(void)
{
    printk(KERN_INFO "Cleaning-up donn_cdev.\n");
    cdev_del(&donn_cdev);
    unregister_chrdev_region(donn_dev, 1);
}

module_init(donn_module_init);
module_exit(donn_module_cleanup);

MODULE_AUTHOR("Duncan");
MODULE_LICENSE("GPL");

