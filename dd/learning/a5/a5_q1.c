#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>

#define MAX_DEVS 10

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Example");
MODULE_DESCRIPTION("LKM with params: class_name, device_name, num_devs");

/* Module parameters */
static char *class_name = "my_cls";
static char *device_name = "my_dev";
static int num_devs = 1;

module_param(class_name, charp, 0444);
MODULE_PARM_DESC(class_name, "Device class name");

module_param(device_name, charp, 0444);
MODULE_PARM_DESC(device_name, "Base device name");

module_param(num_devs, int, 0444);
MODULE_PARM_DESC(num_devs, "Number of devices (max 10)");

/* Globals */
static dev_t base_dev;
static struct class *dev_class;
static struct cdev *cdevs;

/* Dummy file operations */
static int my_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int my_release(struct inode *inode, struct file *file)
{
    return 0;
}

static struct file_operations fops = {
    .owner   = THIS_MODULE,
    .open    = my_open,
    .release = my_release,
};

static int __init my_module_init(void)
{
    int ret, i;
    char devnode_name[64];

    if (num_devs <= 0 || num_devs > MAX_DEVS) {
        pr_err("num_devs must be between 1 and %d\n", MAX_DEVS);
        return -EINVAL;
    }

    /* Allocate device numbers */
    ret = alloc_chrdev_region(&base_dev, 0, num_devs, device_name);
    if (ret) {
        pr_err("alloc_chrdev_region failed\n");
        return ret;
    }

    /* Allocate cdev array */
    cdevs = kcalloc(num_devs, sizeof(struct cdev), GFP_KERNEL);
    if (!cdevs) {
        ret = -ENOMEM;
        goto err_unregister;
    }

    /* Create class */
    dev_class = class_create(THIS_MODULE, class_name);
    if (IS_ERR(dev_class)) {
        ret = PTR_ERR(dev_class);
        goto err_free_cdevs;
    }

    /* Create devices */
    for (i = 0; i < num_devs; i++) {
        cdev_init(&cdevs[i], &fops);
        cdevs[i].owner = THIS_MODULE;

        ret = cdev_add(&cdevs[i], base_dev + i, 1);
        if (ret)
            goto err_cleanup_devices;

        snprintf(devnode_name, sizeof(devnode_name),
                 "%s%02d", device_name, i + 1);

        device_create(dev_class, NULL,
                      base_dev + i,
                      NULL,
                      "%s", devnode_name);
    }

    pr_info("Module loaded: class=%s devices=%d\n",
            class_name, num_devs);
    return 0;

err_cleanup_devices:
    while (i--) {
        device_destroy(dev_class, base_dev + i);
        cdev_del(&cdevs[i]);
    }
    class_destroy(dev_class);

err_free_cdevs:
    kfree(cdevs);

err_unregister:
    unregister_chrdev_region(base_dev, num_devs);
    return ret;
}

static void __exit my_module_exit(void)
{
    int i;

    for (i = 0; i < num_devs; i++) {
        device_destroy(dev_class, base_dev + i);
        cdev_del(&cdevs[i]);
    }

    class_destroy(dev_class);
    kfree(cdevs);
    unregister_chrdev_region(base_dev, num_devs);

    pr_info("Module unloaded cleanly\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

