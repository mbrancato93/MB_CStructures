#include "main.h"
#include "hashmap.h"

//TODO: hashmap_removeNode
//TODO: hashmap_destroyInd
//TODO: hashmap_destroy

struct HASHMAP_HEAD *hashmap_init(size_t s, int (*_f)(char *, size_t)) {
    if(s < 0) return NULL;

    struct HASHMAP_HEAD *tmp = malloc(sizeof(*tmp) + sizeof(struct SLL_NODE) * s);
    if(tmp == NULL) return NULL;
    memset(tmp, 0x0, sizeof(*tmp) + sizeof(struct SLL_NODE) * s);

    if(_f == NULL) {
        tmp->f = std_hashmap_func;
    } else {
        tmp->f = _f;
    }
    tmp->usize = s;

    return tmp;
}

int hashmap_add(struct HASHMAP_HEAD *h, const char *str, const char *_val) {
    if(str == NULL || h == NULL || _val == NULL) return 0;

    size_t hash_ind = h->f(str, h->usize);
    if(hash_ind < 0) return 0;

    struct KEYVAL_PAIR pD = {str, _val};

    size_t len = sizeof(pD) + strlen(str) + strlen(_val) + 2;

    if(h->a[hash_ind].d == NULL) {
        h->a[hash_ind].d = malloc(len);
        memcpy(h->a[hash_ind].d, &pD, len);
        ((struct KEYVAL_PAIR *)h->a[hash_ind].d)->key = strdup(str);
        ((struct KEYVAL_PAIR *)h->a[hash_ind].d)->val = strdup(_val);
        h->a[hash_ind].d_size = len;
        h->a[hash_ind].next = NULL;
    } else {
        struct SLL_NODE *tmp = malloc(sizeof(struct SLL_NODE));
        tmp->d = malloc(len);
        memcpy(tmp->d, &pD, len);
        ((struct KEYVAL_PAIR *)tmp->d)->key = strdup(str);
        ((struct KEYVAL_PAIR *)tmp->d)->val = strdup(_val);
        tmp->d_size = len;
        tmp->next = NULL;

        return sll_push_node(&h->a[hash_ind], tmp);
    }

    return 1;
}

struct KEYVAL_PAIR *hashmap_locate(struct HASHMAP_HEAD *h, const char *key) {
    if(h == NULL || key == NULL) return NULL;

    struct KEYVAL_PAIR *o = malloc(sizeof(*o)); //to be reallocated later with the correct size of the strings key and val
    size_t hash_ind = h->f(key, h->usize);
    if(hash_ind < 0) return NULL;

    struct SLL_NODE *tmp = &h->a[hash_ind];
    while(tmp != NULL) {
        if(tmp->d != NULL && tmp->d_size != 0) {
            if(strcmp(key, ((struct KEYVAL_PAIR *)tmp->d)->key) == 0) {
                const char *val = ((struct KEYVAL_PAIR *)tmp->d)->val;
                size_t len = sizeof(struct KEYVAL_PAIR) + strlen(key) + strlen(val) + 2;

                o = realloc(o, len);
                memcpy(o, tmp->d, len);
                return o;
            }
        }
        tmp = tmp->next;
    }
    return NULL;
}

int std_hashmap_func(char *str, size_t num) {
    return 1;
}

int str_hash(char *str, size_t num) {
    int hash = 0;
    int R = 31; //small prime #
    for (int i = 0; i < strlen(str); i++)
        hash = (R * hash + str[i]) % num;
    
    return hash % num;
}

void hashmap_print(struct HASHMAP_HEAD *h) {
    if(h != NULL) {
        for(int i = 0; i < h->usize; i++) {
            printf("[IND %d]\n", i);
            struct SLL_NODE *tmp = &h->a[i];
            while(tmp != NULL) {
                if(tmp->d == NULL || tmp->d_size < 1) break;
                const char *key = ((struct KEYVAL_PAIR *)tmp->d)->key;
                const char *val = ((struct KEYVAL_PAIR *)tmp->d)->val;

                printf("< KEY: %s || VAL: %s >\n", key, val);

                tmp = tmp->next;
            }
        }
    }
}

//TODO: add option for **out to be NULL so taht ther eis no return if not required.
struct SLL_NODE *hashmap_removeNode(struct HASHMAP_HEAD *h, const char *key, struct KEYVAL_PAIR **out) {
    if(h == NULL || key == NULL) return NULL;

    int hash_ind = h->f(key, h->usize);
    if(hash_ind < 0 || hash_ind > h->usize - 1) return NULL;

    struct SLL_NODE *tmp = &h->a[hash_ind];
    if(tmp == NULL) return NULL;

    //find node to remove
    if(strcmp(((struct KEYVAL_PAIR *)tmp->d)->key, key) == 0) {
        //tmp is the target node
    } else {
        while(tmp != NULL) {
            if(strcmp(((struct KEYVAL_PAIR *)tmp->d)->key, key) == 0) {
                break;
            }
            tmp = tmp->next;
        }
    }

    struct SLL_NODE *oTmp = NULL;

    struct SLL_NODE *new_head = sll_remove_node(&h->a[hash_ind], tmp, &oTmp);

    *out = malloc(sizeof(struct KEYVAL_PAIR *) + oTmp->d_size);

    (*out)->key = malloc(strlen(((struct KEYVAL_PAIR *)oTmp->d)->key) + 1);
    (*out)->val = malloc(strlen(((struct KEYVAL_PAIR *)oTmp->d)->val) + 1);
    strcpy((*out)->key, ((struct KEYVAL_PAIR *)oTmp->d)->key);
    strcpy((*out)->val, ((struct KEYVAL_PAIR *)oTmp->d)->val);

    

    free(((struct KEYVAL_PAIR *)h->a[hash_ind].d)->key);
    free(((struct KEYVAL_PAIR *)h->a[hash_ind].d)->val);
    ((struct KEYVAL_PAIR *)h->a[hash_ind].d)->key = NULL;
    ((struct KEYVAL_PAIR *)h->a[hash_ind].d)->val = NULL;
    free(h->a[hash_ind].d);
    h->a[hash_ind].d = NULL;


    if(new_head != NULL) {
        h->a[hash_ind].d = malloc(new_head->d_size);
        ((struct KEYVAL_PAIR *)h->a[hash_ind].d)->key = malloc(strlen(((struct KEYVAL_PAIR *)new_head->d)->key) + 1);
        ((struct KEYVAL_PAIR *)h->a[hash_ind].d)->val = malloc(strlen(((struct KEYVAL_PAIR *)new_head->d)->val) + 1);
        strcpy(((struct KEYVAL_PAIR *)h->a[hash_ind].d)->key, ((struct KEYVAL_PAIR *)new_head->d)->key);
        strcpy(((struct KEYVAL_PAIR *)h->a[hash_ind].d)->val, ((struct KEYVAL_PAIR *)new_head->d)->val);
        h->a[hash_ind].d_size = new_head->d_size;
        h->a[hash_ind].next = new_head->next;


        free(((struct KEYVAL_PAIR *)new_head->d)->val);
        free(((struct KEYVAL_PAIR *)new_head->d)->key);
        free(new_head->d);
        new_head->d = NULL;
        new_head->d_size = 0;
        new_head->next = NULL;
        free(new_head);
        new_head = NULL;

    }

    return &h->a[hash_ind];
}

int hashmap_destroyInd(struct HASHMAP_HEAD *h, size_t ind) {
    if(h == NULL || ind < 0 || ind > h->usize) return 0;

    struct SLL_NODE *tmp = &h->a[ind];

    while(tmp != NULL && tmp->d != NULL) {
        struct KEYVAL_PAIR *o = NULL;
        tmp = hashmap_removeNode(h, ((struct KEYVAL_PAIR *)tmp->d)->key, &o);
    }

    return 1;
}

int hashmap_destroy(struct HASHMAP_HEAD *h) {
    if(h == NULL) return 0;

    int sum = 0;
    for(int i = 0; i < h->usize; i++) {
        sum += hashmap_destroyInd(h, i);
    }

    return sum;
}

int hashmap_size(struct HASHMAP_HEAD *h) {
    if(h == NULL) return 0;

    int sum = 0;
    for(int i = 0; i < h->usize; i++) {
        struct SLL_NODE *tmp = &h->a[i];
        sum += sll_size(tmp);
    }

    return sum;
}