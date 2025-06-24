#include "tests.h"

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Add number to tree and print it\n");
    
    int array[] = {3, 5, 1, 2, 11, 7, 67, 33};
    size_t array_size = sizeof(array)/sizeof(int);

    puts("Create binary search tree\n");
    BSTree* tree = BSTree_create();


    puts("Print empty tree");
    BSTree_print_nodes(tree);
    puts("");


    puts("Check tree size\n");
    assert( BSTree_get_size(tree) == 0 );


    puts("Add node to the tree\n");
    for (size_t i = 0; i < array_size; i++){
        BSTree_add(tree, array[i]);
    }


    puts("Check tree size\n");
    assert( BSTree_get_size(tree) == array_size );


    puts("Print tree after nodes addition");
    BSTree_print_nodes(tree);
    puts("");


    puts("Clean binary search tree\n");
    BSTree_clean(tree);


    puts("Check tree size\n");
    assert( BSTree_get_size(tree) == 0 );


    puts("Print tree after clean");
    BSTree_print_nodes(tree);
    puts("");


    puts("Delete binary search tree\n");
    BSTree_delete(tree);

    return 0;
}
