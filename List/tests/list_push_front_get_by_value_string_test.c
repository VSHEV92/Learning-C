#include "tests.h"
 
static void printer_string(void* value){
    printf("%s ", *( (char**)value ));
}

static int comparer_string(void* lhs, void* rhs){
    return strcmp( *( (char**)lhs ), *( (char**)rhs ));
}

void list_push_front_get_by_value_string_test() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Push front, then get indexs by value, then clean for list of strings\n");

    char* array[] = {"foo", "bar", "pupa", "lupa"};
    size_t array_size = sizeof(array)/sizeof(char*);

    size_t list_size;

    
    puts("Create list");
    List* list = List_create();
    assert(list);
    puts("");

    
    puts("Push front data to list");
    for (size_t i = 0; i < array_size; i++){
        printf("%lu: %s\n", i, array[i]);
        List_push_front_typed(list, array[i], char*);
    }
    puts("");

    
    list_size = List_get_size(list);
    printf("List size: %lu\n", list_size);
    assert(list_size == array_size);
    puts("");


    puts("Print list");
    List_set_printer(list, printer_string);
    List_print(list);
    puts("\n");


    puts("Get list index by value");
    List_set_comparer(list, comparer_string);
    for (size_t i = 0; i < array_size; i++){
        ssize_t temp = List_get_index_by_value_typed(list, array[i], char*);
        printf("%lu: %ld\n", i, temp);
        assert(temp == array_size - 1 - i);
    }
    
    char* value = "foobar";
    ssize_t temp = List_get_index_by_value_typed(list, value, char*);
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
    
}
