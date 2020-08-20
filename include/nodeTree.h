#ifndef __NODETREE_H__
#define __NODETREE_H__

#include "main.h"
#include "sllist.h"
#include "hashmap.h"

#define PARAMS_HASHMAP_SIZE 10
#define PRINT_PEERS 0
#define PRINT_CHILDREN 1
#define PRINT_PARAMS 2

struct NODE_TREE {
    struct HASHMAP_HEAD *params;

    struct NODE_TREE *parent;
    struct NODE_TREE *child;

    char *URI;

    void *data;
    size_t d_size;

    struct NODE_TREE *prev;
    struct NODE_TREE *next;
};

struct NODE_TREE *nodeTree_init(void *_data, size_t _d_size, int (*_f)(char *, size_t));
int nodeTree_add_keyval(struct NODE_TREE *h, const char *key, const char *val);
struct KEYVAL_PAIR *nodeTree_locate_keyval(struct NODE_TREE *h, const char *key);
int nodeTree_add_peer(struct NODE_TREE *n, struct NODE_TREE *after);
int nodeTree_push_peer(struct NODE_TREE *h, struct NODE_TREE *n);
int nodeTree_print(struct NODE_TREE *h, char params);
int nodeTree_lvlSize(struct NODE_TREE *h);
int nodeTree_push_child(struct NODE_TREE *h, struct NODE_TREE *n);
int nodeTree_destroy(struct NODE_TREE **nt);
int nodeTree_lvl(struct NODE_TREE *h);

#endif