#include "Dict.h"

size_t Dict_get_hash(char* key, size_t max_hash_value) {
    size_t hash = 0; 
    size_t key_len = strlen(key);

    for (size_t i = 0; i < key_len; i++) {
        hash += (unsigned char)key[i];
    }

    return hash % max_hash_value;
}


int Dict_key_comparer(void* lhs, void* rhs){
    return strcmp( ( (Dict_node*)lhs )->key, (char*)rhs );
}


Dict* Dict_create(size_t max_hash_value) {
    Dict* dict = malloc( sizeof(Dict) );
    
    if (dict == NULL) {
        DICT_MALLOC_ERR;
    }

    dict->size = 0;
    dict->max_hash = max_hash_value;
    dict->nodes = malloc( sizeof(List*) * max_hash_value );
    
    if (dict->nodes == NULL) {
        DICT_MALLOC_ERR;
    }

    for (size_t i = 0; i < max_hash_value; i++) {
        dict->nodes[i] = List_create();
        List_set_comparer(dict->nodes[i], Dict_key_comparer);
    } 

    return dict;
}


void Dict_clean(Dict* dict) {
    for (size_t i = 0; i < dict->max_hash; i++) {
        for (size_t j = 0; dict->nodes[i]->size; j++) {
            Dict_node* node = List_pop_front(dict->nodes[i]);
            free(node);
        }
    }
    dict->size = 0;
}


void Dict_delete(Dict* dict) {
    Dict_clean(dict);

    for (size_t i = 0; i < dict->max_hash; i++) {
        List_delete(dict->nodes[i]);
    }

    free(dict->nodes);
    free(dict);
}


size_t Dict_get_size(Dict* dict) {
    return dict->size;
}


bool Dict_key_exist(Dict* dict, char* key) {
    size_t hash = Dict_get_hash(key, dict->max_hash);
    List* hash_list = dict->nodes[hash];

    ssize_t key_index = List_get_index_by_value(hash_list, key);

    return (key_index == -1) ? 0 : 1;
}


void Dict_set(Dict* dict, char* key, void* value) {
    size_t hash = Dict_get_hash(key, dict->max_hash);
    List* hash_list = dict->nodes[hash];

    int key_index = List_get_index_by_value_typed(hash_list, key, char*);

    if ( key_index == -1) {
        Dict_node* dict_node = malloc( sizeof(Dict_node) );

        if (dict_node == NULL) {
            DICT_MALLOC_ERR;
        }

        dict_node->key = key;
        dict_node->value = value;
        
        List_push_back(hash_list, dict_node);
    }
    else {
        Dict_node* dict_node = List_get_value_by_index(hash_list, key_index);
        dict_node->value = value;
    }
    
    dict->size++;
}


void* Dict_get(Dict* dict, char* key) {
    size_t hash = Dict_get_hash(key, dict->max_hash);
    List* hash_list = dict->nodes[hash];

    ssize_t key_index = List_get_index_by_value(hash_list, key);

    if (key_index == -1) {
        DICT_KEY_ERR;
    }

    Dict_node* dict_node = List_get_value_by_index(hash_list, key_index);
    return dict_node->value;
}


void Dict_set_printer(Dict* dict, Dict_printer printer) {
    for (size_t i = 0; i < dict->max_hash; i++) {
        List_set_printer(dict->nodes[i], printer);
    }
}


void Dict_print(Dict* dict) {
    for (size_t i = 0; i < dict->max_hash; i++) {
        printf("[%lu]: ", i);
        List_print(dict->nodes[i]);
        puts("");
    }
}
