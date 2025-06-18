#include "tests.h"

static void printer_string(void* node){
    Dict_node* dict_node = (Dict_node*) node;
    printf("%s -> %s, ", dict_node->key, *( (char**)(dict_node->value) ) );
}

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Set and then get value to dict of strings\n");

    size_t max_hash_size = 5;

    char* value_array[] = {"a", "b", "c", "d", "e", "f", "end"};
    char* key_array[] = {"foo", "bar", "pupa", "luma", "one", "two", "loo"};
    size_t input_size = sizeof(key_array)/sizeof(char*);

    size_t dict_size;

    
    puts("Create dictionary");
    Dict* dict = Dict_create(max_hash_size);
    assert(dict);
    puts("");


    puts("Set dictionary printer");
    Dict_set_printer(dict, printer_string);
    puts("");
    

    puts("Set key/value pairs");
    for (size_t i = 0; i < input_size; i++){
        printf("%s: %s\n", key_array[i], value_array[i]);
        Dict_set_typed(dict, key_array[i], value_array[i], char*);
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
        char* temp = Dict_get_typed(dict, key_array[i], char*);
        printf("%s: %s\n", key_array[i], temp);
        assert( strcmp(temp, value_array[i]) == 0 );
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
