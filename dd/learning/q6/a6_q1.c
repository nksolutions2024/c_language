#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Kernel module using linked lists with module parameters");
MODULE_VERSION("1.0");

/* Module parameters */
static unsigned int num_nodes = 10;
static int start_value = 0;
static int step_size = 1;

module_param(num_nodes, uint, 0444);
MODULE_PARM_DESC(num_nodes, "Number of nodes in the linked list");

module_param(start_value, int, 0444);
MODULE_PARM_DESC(start_value, "Starting value for the linked list");

module_param(step_size, int, 0444);
MODULE_PARM_DESC(step_size, "Step size between node values");

/* Linked list node structure */
struct list_node {
    int value;
    struct list_head list;
};

/* Head of the linked list */
static LIST_HEAD(my_list);

/* Module initialization */
static int __init list_module_init(void)
{
    struct list_node *node;
    unsigned int i;
    int current_value = start_value;

    pr_info("Linked list module loaded\n");
    pr_info("num_nodes=%u start_value=%d step_size=%d\n",
            num_nodes, start_value, step_size);

    /* Create the linked list */
    for (i = 0; i < num_nodes; i++) {
        node = kmalloc(sizeof(*node), GFP_KERNEL);
        if (!node) {
            pr_err("Memory allocation failed\n");
            return -ENOMEM;
        }

        node->value = current_value;
        INIT_LIST_HEAD(&node->list);
        list_add_tail(&node->list, &my_list);

        current_value += step_size;
    }

    /* Print the list */
    pr_info("Linked list values:\n");
    list_for_each_entry(node, &my_list, list) {
        pr_info("%d\n", node->value);
    }

    return 0;
}

/* Module cleanup */
static void __exit list_module_exit(void)
{
    struct list_node *node, *tmp;

    pr_info("Cleaning up linked list module\n");

    /* Safely delete all nodes */
    list_for_each_entry_safe(node, tmp, &my_list, list) {
        list_del(&node->list);
        kfree(node);
    }

    pr_info("Linked list module unloaded\n");
}

module_init(list_module_init);
module_exit(list_module_exit);

