#include "main.h"
#include "nodeTree.h"
#include "mArray.h"

int nodeTree_destroy(struct NODE_TREE **nt) {
    //TODO: delete params!!
    if(nt == NULL || *nt == NULL) return 2;

    struct NODE_TREE *tmp = *nt;
    while(tmp != NULL) {

        struct DYN_ARR lvlAddrs;
        lvlAddrs.head = NULL;
        if(arr_init(&lvlAddrs, sizeof(long *)) < 1) return 0;
        struct NODE_TREE *tmp_child = tmp->child;
        while(tmp_child != NULL) {
            //push next peer to current node
            if(tmp_child->next != NULL) {
                if(arr_push(&lvlAddrs, (long *)&tmp_child->next) < 1) return 0;
            }

            struct NODE_TREE *tmp_childHold = tmp_child;

            //now check if there is a child
            if(tmp_child->child != NULL) {
                tmp_child = tmp_child->child;
            } else {
                long *nxtAddr = NULL;
                if(lvlAddrs.curr_ind == -1) break;
                if(arr_pop(&lvlAddrs, &nxtAddr) < 1) return 0;
                tmp_child = *nxtAddr;
                // if(lvlAddrs.curr_ind == -1) return 0; 
            }
            // tmp_child = tmp_child->next;

            if(hashmap_destroy(tmp_childHold->params) < 1) return 0;
            tmp_childHold->params = NULL;
            if(tmp_childHold->data != NULL) free(tmp_childHold->data);
            tmp_childHold->d_size = -1;
            // tmp_child->child = tmp_child->data = tmp_child->next = tmp_child->parent = tmp_child->prev = NULL;
            tmp_childHold->data = NULL;
            free(tmp_childHold);
            tmp_childHold = NULL;
        }

        long *tmpAddr = (long *)&tmp;
        struct NODE_TREE *tmpHold = *tmpAddr;
        tmp = tmp->next;

        

        if(hashmap_destroy(tmpHold->params) < 1) return 0;
        if(tmpHold->data != NULL) free(tmpHold->data);
        // tmpHold->params = tmpHold->parent = tmpHold->data = tmpHold->prev = NULL;
        tmpHold->data = NULL;
        tmpHold->d_size = -1;

        free(tmpHold);
        tmpHold = NULL;
    }

    // free(*nt);
    *nt = NULL;

    return 1;
}

struct NODE_TREE *nodeTree_init(void *_data, size_t _d_size, int (*_f)(char *, size_t)) {
    if(_d_size < 0 || _data == NULL) return 0;

    struct NODE_TREE *tmp = malloc(sizeof(*tmp));
    if(tmp == NULL) return NULL;
    memset(tmp, 0x0, sizeof(*tmp));

    tmp->params = hashmap_init(PARAMS_HASHMAP_SIZE, _f);
    if(tmp->params == NULL) return NULL;

    tmp->data = malloc(_d_size);
    memcpy(tmp->data, _data, _d_size);
    if(tmp->data == NULL) return 0;

    tmp->d_size = _d_size;
    tmp->parent = NULL;
    tmp->child = NULL;
    tmp->prev = NULL;
    tmp->next = NULL;

    return tmp;
}

int nodeTree_add_keyval(struct NODE_TREE *h, const char *key, const char *val) {
    if(h == NULL || key == NULL || val == NULL) return 0;

    return hashmap_add(h->params, key, val);
}

struct KEYVAL_PAIR *nodeTree_locate_keyval(struct NODE_TREE *h, const char *key) {
    if(h == NULL || key == NULL) return NULL;

    return hashmap_locate(h->params, key);
}

int nodeTree_add_peer(struct NODE_TREE *n, struct NODE_TREE *after) {
    if(after == NULL || n == NULL) return 0;

    struct NODE_TREE *tmp = after->next;
    n->next = tmp;
    after->next = n;

    n->prev = after;
    n->parent = after->parent;

    return 1; 
}

int nodeTree_push_peer(struct NODE_TREE *h, struct NODE_TREE *n) {
    if(h == NULL || n == NULL) return 0;

    struct NODE_TREE *tmp = h;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    return nodeTree_add_peer(n, tmp);
}

int nodeTree_lvlSize(struct NODE_TREE *h) {
    if(h == NULL) return 0;

    int sum = 0;

    struct NODE_TREE *tmp = h;
    while(tmp != NULL) {
        sum += 1;
        tmp = tmp->next;
    }

    return sum;
}

int nodeTree_lvl(struct NODE_TREE *h) {
    if(h == NULL) return -1;

    int sum = 0;

    struct NODE_TREE *tmp = h;
    while(tmp != NULL) {
        sum += 1;
        tmp = tmp->parent;
    }

    return sum;
}

int nodeTree_push_child(struct NODE_TREE *h, struct NODE_TREE *n) {
    if(h == NULL || n == NULL) return 0;

    struct NODE_TREE *tmp = h->child;
    if(tmp == NULL) {
        //first of its kind
        n->parent = h;
        h->child = n;
        return 1;
    } else {
        return nodeTree_push_peer(tmp, n);
    }   
}

int nodeTree_print(struct NODE_TREE *h, char params) {
    if(h == NULL) return 0;

    struct NODE_TREE *tmp = h;
    while(tmp != NULL) {

        if((params >> PRINT_PEERS) & 1) {
            printf("{NODE %s}\n", (char *)tmp->data);
        }

        if((params >> PRINT_PARAMS) & 1) {
            printf("<PARAMS>\n");
            hashmap_print(tmp->params);
        }

        if((params >> PRINT_CHILDREN) & 1) {
            struct DYN_ARR lvlAddrs;
            lvlAddrs.head = NULL;
            if(arr_init(&lvlAddrs, sizeof(long *)) < 1) return 0;
            struct NODE_TREE *tmp_child = tmp->child;
            while(tmp_child != NULL) {
                //push next peer to current node
                if(tmp_child->next != NULL) {
                    if(arr_push(&lvlAddrs, (long *)&tmp_child->next) < 1) return 0;
                }

                //count parent for indent
                int indent = 0;
                struct NODE_TREE *parent_count = tmp_child;
                while(parent_count->parent != NULL) {
                    parent_count = parent_count->parent;
                    indent++;
                }

                //print current node
                for(int i = 0; i < indent; i++) {
                    printf("\t");
                }
                printf("[NODE: %s ; PARENT: %s]\n", (char *)tmp_child->data, (char *)tmp_child->parent->data);

                if((params >> PRINT_PARAMS) & 1) {
                    printf("\n<PARAMS>\n");
                    hashmap_print(tmp_child->params);
                }

                //now check if there is a child
                if(tmp_child->child != NULL) {
                    tmp_child = tmp_child->child;
                } else {
                    long *nxtAddr = NULL;
                    if(arr_pop(&lvlAddrs, &nxtAddr) < 1) return 0;
                    tmp_child = *nxtAddr;
                    // if(lvlAddrs.curr_ind == -1) return 0; 
                }
                // tmp_child = tmp_child->next;
            }
        }

        tmp = tmp->next;
    }
    return 1;
}
