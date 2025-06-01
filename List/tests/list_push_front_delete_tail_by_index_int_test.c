#include "tests.h"

static void printer_int(void* value){
    printf("%d ", *( (int*)value ));
}

void list_push_front_delete_tail_by_index_int_test() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Push front, then delete from tail values by index for list of integers\n");

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


    puts("Delete list values by index");
    for (size_t i = 0; i < array_size; i++){
        List_delete_value_by_index(list, list->size - 1);
        List_print(list);
        puts("");

        size_t list_size = List_get_size(list);
        assert(list_size == array_size - i - 1);

        for (size_t j = 0; j < list_size ; j++){
            int temp = List_get_value_by_index_typed(list, j, int);
            assert(temp == array[array_size - j - 1]);

        }
    }
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
