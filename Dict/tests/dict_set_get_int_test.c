#include "tests.h"

static void printer_int(void* value){
    printf("%d ", *( (int*)value ));
}

void dict_set_get_int_test() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Set ad then get value to dict of integers\n");

    size_t max_hash_size = 5;

    //int value_array[] = {1, 2, 3, 4, 5, 6, 7};
    //char* key_array[] = {"foo", "bar", "pupa", "lupa", "one", "two", "three"};
    //size_t input_size = sizeof(key_array)/sizeof(char*);

    //size_t dict_size;

    
    puts("Create dictionary");
    Dict* dict = Dict_create(max_hash_size);
    assert(dict);
    puts("");

    Dict_set_printer(dict, printer_int);

    puts("Delete dictionary");
    Dict_delete(dict);
    assert(dict != NULL);
    puts("");
    
}
