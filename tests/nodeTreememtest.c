#include "main.h"
#include "nodeTree.h"

int main() {
    int i = 1;
    struct NODE_TREE *h = nodeTree_init(&i, sizeof(i), str_hash);
    if(h == NULL) exit(EXIT_FAILURE);

    


    return 0;
}