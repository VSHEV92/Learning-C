#include "tests.h"

static void printer_int(void* value){
    printf("%d ", *( (int*)value ));
}

static int comparer_int(void* lhs, void* rhs){
    return *( (int*)lhs ) - *( (int*)rhs );
}

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Push front, then get indexs by value, then clean for list of integers\n");

    int array[] = {1, 2, 3, 4, 5, 6, 7};
    size_t array_size = sizeof(array)/sizeof(int);

    size_t list_size;

    
    puts("Create list");
    List* list = List_create();
    assert(list);
    puts("");

    
    puts("Push front data to list");
    for (size_t i = 0; i < array_size; i++){
        printf("%lu: %d\n", i, array[i]);
        List_push_front_typed(list, array[i], int);
    }
    puts("");

    
    list_size = List_get_size(list);
    printf("List size: %lu\n", list_size);
    assert(list_size == array_size);
    puts("");


    puts("Print list");
    List_set_printer(list, printer_int);
    List_print(list);
    puts("\n");


    puts("Get list index by value");
    List_set_comparer(list, comparer_int);
    for (size_t i = 0; i < array_size; i++){
        ssize_t temp = List_get_index_by_value_typed(list, array[i], int);
        printf("%lu: %ld\n", i, temp);
        assert(temp == array_size - 1 - i);
    }
    
    int value = -1;
    ssize_t temp = List_get_index_by_value_typed(list, value, int);
    printf("%d: %ld\n", -1, temp);
    assert(temp == -1);
    
    puts("");


    puts("Clean list");
    List_clean(list);
    puts("");

    
    list_size = List_get_size(list);
    printf("List size: %lu\n", list_size);
    assert(list_size == 0);
    puts("");


    puts("Delete list");
    List_delete(list);
    assert(list != NULL);
    puts("");
    
    return 0;
}
