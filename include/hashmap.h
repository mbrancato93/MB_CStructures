#ifndef __H_HASHMAP__
#define __H_HASHMAP__


#include "sllist.h"

struct HASHMAP_HEAD {
    size_t usize;
    int (*f)(char *, size_t);
    struct SLL_NODE a[];
};

struct KEYVAL_PAIR {
    const char *key;
    const char *val;
};

struct HASHMAP_HEAD *hashmap_init(size_t s, int (*_f)(char *, size_t));
int hashmap_add(struct HASHMAP_HEAD *h, const char *str, const char *_val);
int std_hashmap_func(char *str, size_t num);
struct KEYVAL_PAIR *hashmap_locate(struct HASHMAP_HEAD *h, const char *key);
int str_hash(char *str, size_t num);
struct SLL_NODE *hashmap_removeNode(struct HASHMAP_HEAD *h, const char *key, struct KEYVAL_PAIR **out);
int hashmap_size(struct HASHMAP_HEAD *h);
int hashmap_destroyInd(struct HASHMAP_HEAD *h, size_t ind);
int hashmap_destroy(struct HASHMAP_HEAD *h);
void hashmap_print(struct HASHMAP_HEAD *h);


#endif 