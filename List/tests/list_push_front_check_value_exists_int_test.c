#include "tests.h"

static void printer_int(void* value){
    printf("%d ", *( (int*)value ));
}

static int comparer_int(void* lhs, void* rhs){
    return *( (int*)lhs ) - *( (int*)rhs );
}

void list_push_front_check_value_exists_int_test() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Push front, then check that values exist in list, then clean for list of integers\n");

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


    puts("Check that value in list");
    List_set_comparer(list, comparer_int);
    for (size_t i = 0; i < array_size; i++){
        bool temp = List_value_exists_typed(list, array[i], int);
        assert(temp == true);
    }
    
    int value = -1;
    bool temp = List_value_exists_typed(list, value, int);
    assert(temp == false);
    
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
    
}
