/* Kernel timer with IOCTL control */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define DEVICE_NAME "ktimer_ioctl"
#define CLASS_NAME  "ktimer_class"

#define START_TIMER _IO('T', 1)
#define STOP_TIMER  _IO('T', 2)

/* -------------------------------------------------- */
/* Timer data (from your tested program)              */
/* -------------------------------------------------- */
static struct timer_list my_timer;
static int count;
static bool timer_running;

/* -------------------------------------------------- */
/* Character device data                              */
/* -------------------------------------------------- */
static dev_t dev_num;
static struct cdev ktimer_cdev;
static struct class *ktimer_class;

/* -------------------------------------------------- */
/* Timer callback (same logic as your program)        */
/* -------------------------------------------------- */
static void my_timer_callback(struct timer_list *t)
{
    pr_info("Timer fired: count = %d\n", ++count);

    /* Re-arm timer for 1 second */
    mod_timer(&my_timer, jiffies + HZ);
}

/* -------------------------------------------------- */
/* IOCTL handler                                      */
/* -------------------------------------------------- */
static long ktimer_ioctl(struct file *file,
                         unsigned int cmd,
                         unsigned long arg)
{
    switch (cmd) {

    case START_TIMER:
        if (!timer_running) {
            pr_info("Starting kernel timer\n");
            count = 0;
            timer_setup(&my_timer, my_timer_callback, 0);
            mod_timer(&my_timer, jiffies + HZ);
            timer_running = true;
        }
        break;

    case STOP_TIMER:
        if (timer_running) {
            pr_info("Stopping kernel timer\n");
            del_timer_sync(&my_timer);
            timer_running = false;
        }
        break;

    default:
        return -EINVAL;
    }

    return 0;
}

/* -------------------------------------------------- */
/* File operations                                    */
/* -------------------------------------------------- */
static struct file_operations ktimer_fops = {
    .owner          = THIS_MODULE,
    .unlocked_ioctl = ktimer_ioctl,
};

/* -------------------------------------------------- */
/* Module init                                        */
/* -------------------------------------------------- */
static int __init my_mod_init(void)
{
    int ret;

    pr_info("Initializing kernel timer module\n");

    /* Allocate character device */
    ret = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
    if (ret)
        return ret;

    cdev_init(&ktimer_cdev, &ktimer_fops);
    ret = cdev_add(&ktimer_cdev, dev_num, 1);
    if (ret)
        goto err_unregister;

    ktimer_class = class_create(THIS_MODULE, CLASS_NAME);
    if (IS_ERR(ktimer_class)) {
        ret = PTR_ERR(ktimer_class);
        goto err_cdev;
    }

    device_create(ktimer_class, NULL, dev_num, NULL, DEVICE_NAME);

    pr_info("Module loaded successfully\n");
    return 0;

err_cdev:
    cdev_del(&ktimer_cdev);
err_unregister:
    unregister_chrdev_region(dev_num, 1);
    return ret;
}

/* -------------------------------------------------- */
/* Module exit (same cleanup philosophy as yours)     */
/* -------------------------------------------------- */
static void __exit my_mod_exit(void)
{
    if (timer_running) {
        del_timer_sync(&my_timer);
        pr_info("Deleted kernel timer\n");
    }

    device_destroy(ktimer_class, dev_num);
    class_destroy(ktimer_class);
    cdev_del(&ktimer_cdev);
    unregister_chrdev_region(dev_num, 1);

    pr_info("Goodbye world from %s\n", KBUILD_MODNAME);
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Kernel timer controlled via IOCTL");

