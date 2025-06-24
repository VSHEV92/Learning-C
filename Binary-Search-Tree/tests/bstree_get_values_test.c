#include "tests.h"

static int compare_ints(const void *lhs, const void *rhs) {
    int lhs_ = *(const int*)lhs;
    int rhs_ = *(const int*)rhs;
    return lhs_ - rhs_;
}


int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Add number to tree and get values in tree as sorted array \n");
    
    int array[] = {3, 5, 1, 2, 11, 7, 67, 33};
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


    puts("Get and print tree value");
    int* values = BSTree_get_values(tree);
    for (size_t i = 0; i < BSTree_get_size(tree); i++) {
        printf("%d ", values[i]);
    }
    puts("\n");


    puts("Check tree value is sorted array\n");
    qsort(array, array_size, sizeof(int), compare_ints);
    for (size_t i = 0; i < array_size; i++){
        assert(array[i] == values[i]);
    }

    puts("Delete binary search tree\n");
    BSTree_delete(tree);

    free(values);

    return 0;
}
