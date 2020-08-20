#include "hash.h"
#include "main.h"

int hash_init(struct HASH_HEAD **h, size_t s, int (*_f)(char *)) {
    if(*h != NULL || s <= 0) return 0;
    
    *h = malloc(sizeof(struct HASH_HEAD));
    if(h == NULL) return 0;

    (*h)->a = malloc(s * sizeof(struct SLL_NODE));
    if((*h)->a == NULL) return 0;

    struct SLL_NODE *tmp = NULL;
    for(int i = 0; i < s; i++) {
        tmp = (*h)->a + i * sizeof(struct SLL_NODE);
        
        char in = 0x0;

        tmp->d = malloc(sizeof(in));
        if(tmp->d == NULL) return 0;

        memcpy(tmp->d, &in, sizeof(in));
        int size = sizeof(in);
        memcpy(&(tmp->d_size), &size, sizeof(int));
        tmp->next = NULL;

        tmp = NULL;
    }

    if(_f == NULL) {
        (*h)->f = std_hash_func;
    }
    (*h)->usize = s;
    return 1;
}

int hash_add(struct HASH_HEAD *h, char *str) {
    if(h == NULL || str == NULL) return 0;

    size_t hash_ind = h->f(str);
    if(hash_ind < 0) return 0;

    struct SLL_NODE *tmp = hash_get_ind(h, hash_ind);
    if(tmp == NULL) return 0;

    if(sll_size(h->a) == 1 && strcmp((char *)tmp->d, "") == 0) {
        strcpy(tmp->d, str);
        tmp->d_size = sizeof(char) * (strlen(str) + 1);
        return 1;
    }

    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    struct SLL_NODE *hold = NULL;
    sll_init_node(&hold, str, sizeof(char) * (strlen(str) + 1));
    if(hold == NULL) return 0;

    int res = sll_add_node(hold, tmp);
    tmp = NULL;
    return res;
}

int hash_locate(struct HASH_HEAD *h, char *str) {
    if(h == NULL || str == NULL) return -1;

    // int curr_list_size = 0;
    struct SLL_NODE *tmp = NULL;
    for(int i = 0; i < h->usize; i++) {
        tmp = hash_get_ind(h, i);
        // curr_list_size = sll_size(tmp);

        do {
            if(strcmp(tmp->d, str) == 0) {
                return i;
            }
            tmp = tmp->next;
        } while(tmp != NULL);
    }
    return -1;
}

struct SLL_NODE *hash_get_ind(struct HASH_HEAD *h, size_t ind) {
    if(h == NULL || ind < 0 || ind > h->usize) return 0;

    return h->a + ind * sizeof(struct SLL_NODE);
}

int std_hash_func(char *str) {
    return 1;
}
