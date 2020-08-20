#ifndef __SLLIST_H__
#define __SLLIST_H__

#include "main.h"

// #include "stddef.h"
// #include <stdlib.h>
// #include <string.h>

struct SLL_NODE {
    void *d;
    size_t d_size;
    struct SLL_NODE *next;
};

int sll_init_node(struct SLL_NODE **n, void *_d, size_t _d_size);
int sll_add_node(struct SLL_NODE *n, struct SLL_NODE *after);
int sll_size(struct SLL_NODE *h);
struct SLL_NODE *sll_remove_node(struct SLL_NODE *head, struct SLL_NODE *rem, struct SLL_NODE **out);
int sll_destroy(struct SLL_NODE *head);
int sll_push_node(struct SLL_NODE *h, struct SLL_NODE *n);
int sll_combine(struct SLL_NODE *h, struct SLL_NODE *n);

#endif