#include "main.h"
#include "hashmap.h"
#include "malloc.h"

int main() {
    struct HASHMAP_HEAD *h = hashmap_init(10, NULL);
    if(h == NULL) exit(EXIT_FAILURE);

    char *key = "test1\0";
    char *val = "test2\0";


    // if(!hashmap_add2(h, key, val)) exit(EXIT_FAILURE);
    for(int i = 0; i < 100; i++) {
        if(!hashmap_add(h, key, val)) exit(EXIT_FAILURE);
    }

    if(sll_size(&h->a[1]) != 100) exit(EXIT_FAILURE);

    struct KEYVAL_PAIR *o = hashmap_locate(h, "test1");
    if(o == NULL) exit(EXIT_FAILURE);


    //TODO: special delete function to destroy everything but root of hashmap index list, then clear the first index
    struct SLL_NODE *tmp = h->a[1].next;
    if(!sll_destroy(tmp)) exit(EXIT_FAILURE);

    return 0;
}