#ifndef __HASH_H__
#define __HASH_H__

#include "sllist.h"

struct HASH_HEAD {
    struct SLL_NODE *a;
    size_t usize;
    int (*f)(char *);
};

int hash_init(struct HASH_HEAD **h, size_t s, int (*_f)(char *));
int std_hash_func(char *str);
int hash_add(struct HASH_HEAD *h, char *str);
struct SLL_NODE *hash_get_ind(struct HASH_HEAD *h, size_t ind);
int hash_locate(struct HASH_HEAD *h, char *str);

#endif