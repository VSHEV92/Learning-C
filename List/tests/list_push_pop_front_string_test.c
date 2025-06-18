#include "tests.h"

static void printer_string(void* value){
    printf("%s ", *( (char**)value ));
}

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Push front then pop front for list of strings\n");

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


    puts("Pop front data from list");
    for (size_t i = 0; i < array_size; i++){
        char* temp = List_pop_front_typed(list, char*);
        printf("%lu: %s\n", i, temp);
        assert( strcmp(temp, array[array_size - 1 - i]) == 0 );
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
    
    return 0;
}
