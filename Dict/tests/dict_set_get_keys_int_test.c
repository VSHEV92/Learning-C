#include "tests.h"


static void list_printer_string(void* value){
    printf("%s ", *( (char**)value ));
}

static int list_comparer_string(void* lhs, void* rhs){
    return strcmp( *( (char**)lhs ), *( (char**)rhs ));
}

static void printer_int(void* node){
    Dict_node* dict_node = (Dict_node*) node;
    printf("%s -> %d, ", dict_node->key, *((int*)dict_node->value) );
}

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Set and then get keys to dict of integers\n");

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
    

    puts("Get keys");
    List* keys = Dict_get_keys(dict);
    List_set_printer(keys, list_printer_string);
    List_set_comparer(keys, list_comparer_string);
    puts("");


    puts("Print keys");
    List_print(keys);
    puts("\n");


    size_t keys_size = List_get_size(keys);
    printf("Keys size: %lu\n", keys_size);
    assert(keys_size == input_size);
    puts("");


    puts("Check keys");
    for (size_t i = 0; i < input_size; i++){
        ssize_t keys_index = List_get_index_by_value_typed(keys, key_array[i], char*);
        printf("%s: %ld\n", key_array[i], keys_index);
        assert(keys_index != -1);
    }
    puts("");


    puts("Delete keys");
    List_delete(keys);
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
