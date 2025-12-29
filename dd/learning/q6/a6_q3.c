#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/list.h>
#include <linux/slab.h>
#include "prime_ioctl.h"

#define DEVICE_NAME "prime_device"
#define CLASS_NAME  "prime_class"

static int major;
static struct class *prime_class;
static struct device *prime_device;

/* Kernel linked list */
struct prime_node {
    int value;
    struct list_head list;
};

static LIST_HEAD(prime_list);

/* Prime check */
static int is_prime(int n) {
    int i;
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;

    return 1;
}

static long prime_ioctl(struct file *file,
                        unsigned int cmd,
                        unsigned long arg) {
    int num;
    struct prime_node *node;
    int __user *user_buf = (int __user *)arg;

    switch (cmd) {
    case SEND_NUMBER:
        if (copy_from_user(&num, user_buf, sizeof(int)))
            return -EFAULT;

        if (is_prime(num)) {
            node = kmalloc(sizeof(*node), GFP_KERNEL);
            node->value = num;
            list_add(&node->list, &prime_list);
        }
        break;

    case GET_PRIMES:
        list_for_each_entry(node, &prime_list, list) {
            if (copy_to_user(user_buf++, &node->value, sizeof(int)))
                return -EFAULT;
        }
        break;

    default:
        return -EINVAL;
    }
    return 0;
}

static struct file_operations fops = {
    .owner          = THIS_MODULE,
    .unlocked_ioctl = prime_ioctl,
};

static int __init prime_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    prime_class = class_create(THIS_MODULE, CLASS_NAME);
    prime_device = device_create(prime_class, NULL,
                                 MKDEV(major, 0), NULL, DEVICE_NAME);
    printk(KERN_INFO "Prime driver loaded\n");
    return 0;
}

static void __exit prime_exit(void) {
    struct prime_node *node, *tmp;

    list_for_each_entry_safe(node, tmp, &prime_list, list) {
        list_del(&node->list);
        kfree(node);
    }

    device_destroy(prime_class, MKDEV(major, 0));
    class_destroy(prime_class);
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Prime driver unloaded\n");
}

module_init(prime_init);
module_exit(prime_exit);

MODULE_LICENSE("GPL");

