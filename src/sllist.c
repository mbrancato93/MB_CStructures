#include "sllist.h"

int sll_init_node(struct SLL_NODE **n, void *_d, size_t _d_size) {
    //verify node is NULL on entry
    if(*n != NULL || n == NULL) return -1;

    //allocate memory for requested size, return -1 if failure
    *n = malloc(sizeof(struct SLL_NODE));
    if(*n == NULL) return -1;

    //allocate space for the size of entry variable, store
    (*n)->d = malloc(_d_size);
    if((*n)->d == NULL) return -1;
    memcpy((*n)->d, _d, _d_size);

    //record data entry size
    (*n)->d_size = _d_size;

    //set next pointer to NULL
    (*n)->next = NULL;

    return 1;
}

int sll_add_node(struct SLL_NODE *n, struct SLL_NODE *after) {
    //verify node to add and after node exist
    if(n == NULL || after == NULL) return -1;

    struct SLL_NODE *tmp = after->next;
    n->next = tmp;
    after->next = n;

    return 1;
}

int sll_push_node(struct SLL_NODE *h, struct SLL_NODE *n) {
    if(h == NULL) return -1;

    struct SLL_NODE *tmp = h;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    sll_add_node(n, tmp);
    return 1;
}

struct SLL_NODE *sll_remove_node(struct SLL_NODE *head, struct SLL_NODE *rem, struct SLL_NODE **out) {
    //verify head and remove are non-NULL
    if(head == NULL || rem == NULL || *out != NULL || out == NULL) return 0;

    //find index of rem (done in this order so that out is not allocated if its not necessary)
    struct SLL_NODE *tmp = head;
    while(tmp != NULL && tmp->next != rem) {
        tmp = tmp->next;
    }

    //was rem found?
    if(tmp == NULL && rem != head) return 0;

    // *out = malloc(rem->d_size + sizeof(*out));
    // (*out)->d = malloc(rem->d_size);

    //special case if rem is head
    if(rem == head) {
        // if(!sll_init_node(out, head->d, head->d_size)) return 0;

        //hold new head
        tmp = head->next;

        *out = head;
        // memcpy(out, &head, rem->d_size + sizeof(*out));
        // memcpy((*out)->d, head->d, rem->d_size);
        (*out)->next = NULL;
        
        //destroy old head
        // free(head->d);
        // free(head);

        //return new head::must verify that new head is not NULL on the outside of function
        return tmp;
    } else {
        //tmp->next is the node to remove
        struct SLL_NODE *after = tmp->next->next;

        // if(!sll_init_node(out, tmp->next->d, tmp->next->d_size)) return 0;
        (*out) = tmp->next;
        // memcpy(*out, tmp->next, sizeof(struct SLL_NODE *));
        (*out)->next = NULL;
        
        // free(tmp->next->d);
        // free(tmp->next);

        tmp->next = after;

        //return original head because it wasnt affected
        return head;
    }
}

int sll_destroy(struct SLL_NODE *head) {
    if(head == NULL) return 0;

    struct SLL_NODE *out = NULL;

    while(head != NULL) {
        head = sll_remove_node(head, head, &out);
        free(out->d);
        free(out); 
        out = NULL;
    }

    // head->next = NULL;
    head = NULL;

    return 1;
}

int sll_size(struct SLL_NODE *h) {
    if(h == NULL || h->d == 0x0 || h->d_size <= 0) return 0;
    
    struct SLL_NODE *tmp = h;
    if(tmp == NULL) return 0;

    int i = 1;
    while(tmp->next != NULL) {
        i++;
        tmp = tmp->next;
    }
    return i;
}

int sll_combine(struct SLL_NODE *h, struct SLL_NODE *n) {
    if(h == NULL || n == NULL) return 0;

    struct SLL_NODE *tmp = h;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = n;

    return 1;
}