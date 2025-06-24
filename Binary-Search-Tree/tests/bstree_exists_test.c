#include "tests.h"

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Add number to tree and check that they exist in tree \n");
    
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


    puts("Check that added nodes exist");
    for (size_t i = 0; i < array_size; i++){
        bool result = BSTree_exists(tree, array[i]);
        assert(result == true);
    }


    puts("Check that no other exist");
    assert( BSTree_exists(tree, 4) == false );
    assert( BSTree_exists(tree, 22) == false );
    assert( BSTree_exists(tree, 101) == false );


    puts("Delete binary search tree\n");
    BSTree_delete(tree);


    return 0;
}
