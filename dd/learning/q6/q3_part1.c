#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_COUNT 100000
#define MAX_RANDOM 1000000

struct node {
    int data;
    struct node *next;
};

/* Prime check */
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return 0;

    return 1;
}

/* Insert at head */
void insert(struct node **head, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

/* Sort linked list descending (bubble sort) */
void sort_descending(struct node *head) {
    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (!head) return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data < ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    struct node *prime_list = NULL;
    struct node *non_prime_list = NULL;

    srand(time(NULL));

    for (int i = 0; i < NUM_COUNT; i++) {
        int num = rand() % MAX_RANDOM;
        if (is_prime(num))
            insert(&prime_list, num);
        else
            insert(&non_prime_list, num);
    }

    sort_descending(prime_list);

    printf("Prime numbers sorted (first 20 shown):\n");
    struct node *tmp = prime_list;
    for (int i = 0; i < 20 && tmp; i++) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");

    return 0;
}

