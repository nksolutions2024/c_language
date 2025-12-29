#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/mutex.h>

#include "employee_ioctl.h"

#define DEVICE_NAME "cdac_dev"
#define CLASS_NAME  "cdac"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");
MODULE_DESCRIPTION("Employee Linked List Device Driver");
MODULE_VERSION("1.0");

static dev_t dev_num;
static struct cdev cdac_cdev;
static struct class *cdac_class;

static DEFINE_MUTEX(list_mutex);

/* Employee node */
struct employee_node {
    employee_t emp;
    struct list_head list;
};

static LIST_HEAD(employee_list);
static int emp_count = 0;

/* File operations */
static int cdac_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int cdac_release(struct inode *inode, struct file *file)
{
    return 0;
}

/* IOCTL handler */
static long cdac_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    struct employee_node *node;
    employee_t temp;
    int size;
    struct employee_node *entry;

    switch (cmd) {

    case SEND_EMPLOYEE_DATA:
        if (copy_from_user(&temp, (employee_t *)arg, sizeof(employee_t)))
            return -EFAULT;

        node = kmalloc(sizeof(*node), GFP_KERNEL);
        if (!node)
            return -ENOMEM;

        node->emp = temp;

        mutex_lock(&list_mutex);
        list_add_tail(&node->list, &employee_list);
        emp_count++;
        mutex_unlock(&list_mutex);

        break;

    case GET_LIST_SIZE:
        size = emp_count;
        if (copy_to_user((int *)arg, &size, sizeof(int)))
            return -EFAULT;
        break;

    case PRINT_LIST:
        mutex_lock(&list_mutex);
        list_for_each_entry(entry, &employee_list, list) {
            printk(KERN_INFO "EMP: Name=%s ID=%d Gender=%c\n",
                   entry->emp.name,
                   entry->emp.id,
                   entry->emp.gender);
        }
        mutex_unlock(&list_mutex);
        break;

    default:
        return -EINVAL;
    }
    return 0;
}

static struct file_operations fops = {
    .owner          = THIS_MODULE,
    .open           = cdac_open,
    .release        = cdac_release,
    .unlocked_ioctl = cdac_ioctl,
};

/* Module init */
static int __init cdac_init(void)
{
    alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);

    cdev_init(&cdac_cdev, &fops);
    cdev_add(&cdac_cdev, dev_num, 1);

    cdac_class = class_create(THIS_MODULE, CLASS_NAME);
    device_create(cdac_class, NULL, dev_num, NULL, DEVICE_NAME);

    mutex_init(&list_mutex);

    printk(KERN_INFO "CDAC driver loaded\n");
    return 0;
}

/* Module exit */
static void __exit cdac_exit(void)
{
    struct employee_node *entry, *tmp;

    mutex_lock(&list_mutex);
    list_for_each_entry_safe(entry, tmp, &employee_list, list) {
        list_del(&entry->list);
        kfree(entry);
    }
    mutex_unlock(&list_mutex);

    device_destroy(cdac_class, dev_num);
    class_destroy(cdac_class);
    cdev_del(&cdac_cdev);
    unregister_chrdev_region(dev_num, 1);

    printk(KERN_INFO "CDAC driver unloaded\n");
}

module_init(cdac_init);
module_exit(cdac_exit);

