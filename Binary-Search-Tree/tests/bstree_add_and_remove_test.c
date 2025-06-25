#include "tests.h"


static int compare_ints(const void *lhs, const void *rhs) {
    int lhs_ = *(const int*)lhs;
    int rhs_ = *(const int*)rhs;
    return lhs_ - rhs_;
}

static void check_tree_after_node_remove(BSTree* tree, int* gold, size_t size) {
    int* values = BSTree_get_values(tree);
    qsort(gold, size, sizeof(int), compare_ints);
    for (size_t i = 0; i < size; i++){
        assert(gold[i] == values[i]);
    }
    free(values);
}

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Add number to tree and remove them\n");
    
    int array[] = {3, 5, 1, 2, 11, 7, 67, 33, 85};
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


    puts("Print tree after value 33 removed");
    BSTree_remove(tree, 33);
    BSTree_print_nodes(tree);
    check_tree_after_node_remove(tree, (int[]){3, 5, 1, 2, 11, 7, 67, 85}, --array_size);
    puts("");


    puts("Print tree after value 11 removed");
    BSTree_remove(tree, 11);
    BSTree_print_nodes(tree);
    check_tree_after_node_remove(tree, (int[]){3, 5, 1, 2, 7, 67, 85}, --array_size);
    puts("");


    puts("Print tree after value 3 removed");
    BSTree_remove(tree, 3);
    BSTree_print_nodes(tree);
    check_tree_after_node_remove(tree, (int[]){5, 1, 2, 7, 67, 85}, --array_size);
    puts("");


    puts("Print tree after value 1 removed");
    BSTree_remove(tree, 1);
    BSTree_print_nodes(tree);
    check_tree_after_node_remove(tree, (int[]){5, 2, 7, 67, 85}, --array_size);
    puts("");


    puts("Check tree size\n");
    assert( BSTree_get_size(tree) == 5 );


    puts("Print tree after remove not existed value");
    BSTree_remove(tree, 100);
    BSTree_print_nodes(tree);
    check_tree_after_node_remove(tree, (int[]){5, 2, 7, 67, 85}, --array_size);
    puts("");


    puts("Check tree size\n");
    assert( BSTree_get_size(tree) == 5 );


    puts("Remove all existed values");
    BSTree_remove(tree, 2);
    BSTree_remove(tree, 5);
    BSTree_remove(tree, 7);
    BSTree_remove(tree, 67);
    BSTree_remove(tree, 85);
    BSTree_print_nodes(tree);
    puts("");
    

    puts("Check tree size\n");
    assert( BSTree_get_size(tree) == 0 );

    free(tree);

    return 0;
}
