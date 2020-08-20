#include "main.h"
#include "sllist.h"

int main() {
    struct SLL_NODE *h = NULL;
    int i = 0;
    if(!sll_init_node(&h, &i, sizeof(i))) exit(EXIT_FAILURE);

    //add 99 + OG node = 100
    i++;
    while( i < 100 ) {
        struct SLL_NODE *n = NULL;
        if(!sll_init_node(&n, &i, sizeof(i)) \
            || !sll_push_node(h, n)) exit(EXIT_FAILURE);
        i++;
    }

    if(sll_size(h) != 100) exit(EXIT_FAILURE);


    if(!sll_destroy(h)) exit(EXIT_FAILURE);

    return 0;
}