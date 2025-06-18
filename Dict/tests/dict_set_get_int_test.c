#include "tests.h"

static void printer_int(void* node){
    Dict_node* dict_node = (Dict_node*) node;
    printf("%s -> %d, ", dict_node->key, *((int*)dict_node->value) );
}

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Set and then get value to dict of integers\n");

    size_t max_hash_size = 5;

    int value_array[] = {1, 2, 3, 4, 5, 6, 7};
    char* key_array[] = {"foo", "bar", "pupa", "luma", "one", "two", "loo"};
    size_t input_size = sizeof(key_array)/sizeof(char*);

    size_t dict_size;

    
    puts("Create dictionary");
    Dict* dict = Dict_create(max_hash_size);
    assert(dict);
    puts("");


    puts("Set dictionary printer");
    Dict_set_printer(dict, printer_int);
    puts("");
    

    puts("Set key/value pairs");
    for (size_t i = 0; i < input_size; i++){
        printf("%s: %d\n", key_array[i], value_array[i]);
        Dict_set_typed(dict, key_array[i], value_array[i], int);
    }
    puts("");

    
    dict_size = Dict_get_size(dict);
    printf("Dict size: %lu\n", dict_size);
    assert(dict_size == input_size);
    puts("");


    puts("Print dictionary");
    Dict_print(dict);
    puts("\n");
    

    puts("Get key/value pairs");
    for (size_t i = 0; i < input_size; i++){
        int temp = Dict_get_typed(dict, key_array[i], int);
        printf("%s: %d\n", key_array[i], temp);
        assert(temp == value_array[i]);
    }
    puts("");

    
    dict_size = Dict_get_size(dict);
    printf("Dict size: %lu\n", dict_size);
    assert(dict_size == input_size);
    puts("");


    puts("Clean dictionary");
    Dict_clean(dict);
    puts("");

    
    dict_size = Dict_get_size(dict);
    printf("Dict size: %lu\n", dict_size);
    assert(dict_size == 0);
    puts("");

    
    puts("Delete dictionary");
    Dict_delete(dict);
    assert(dict != NULL);
    puts("");
    
    return 0;
}
