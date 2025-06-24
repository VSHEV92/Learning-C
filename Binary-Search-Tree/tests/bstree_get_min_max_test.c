#include "tests.h"

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Add number to tree and get min and max values in tree \n");
    
    int array[] = {3, 5, 1, 2, 11, 7, 67, 3};
    size_t array_size = sizeof(array)/sizeof(int);


    puts("Create binary search tree\n");
    BSTree* tree = BSTree_create();


    puts("Add node to the tree\n");
    for (size_t i = 0; i < array_size; i++){
        BSTree_add(tree, array[i]);
    }


    puts("Print tree after nodes addition");
    BSTree_print_nodes(tree);
    puts("");


    puts("Get max value");
    assert(BSTree_get_max(tree) == 67);


    puts("Get min value");
    assert(BSTree_get_min(tree) == 1);


    puts("Delete binary search tree\n");
    BSTree_delete(tree);

    return 0;
}
