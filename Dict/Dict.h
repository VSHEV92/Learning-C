#ifndef DICT_H
#define DICT_H

#include <List.h>
#include <string.h>
#include <stdbool.h>

/**
 *  Dict node - one element of Dict
 */
typedef struct Dist_node {
    void* value;               // pointer to value of node
    char* key;                 // node key, always string
} Dict_node;


/**
 *  Dict - dictionary data structure
 */
typedef struct {
    size_t max_hash;     // maximum value of hash (hash table size) 
    size_t size;         // number of list nodes, dist size
    List** nodes;        // array of pointers to lists of Dict_node
} Dict;


/**
 *  Type of function, that can print dict node value 
 */
typedef void (*Dict_printer)(void* value);


/**
 *  Helper macro for check malloc errors
 */
#define DICT_MALLOC_ERR {              \
    fprintf( stderr, "Malloc error" ); \
    exit(1);                           \
}


/**
 *  Helper macro for key out of range error
 */
#define DICT_KEY_ERR {                              \
    fprintf( stderr, "Key is not exists" );         \
    exit(1);                                        \
}


/**
 *  Helper macro for set data of certain type
 *  
 *  args:
 *      dict: pointer to Dict
 *      key: key for the value
 *      value: value to set
 *      type:  type of pushed value
 *  
 *  return: void
 */
#define Dict_set_typed(list, key, value, type) {  \
        Dict_set(list, key, &value);              \
    }                                             \


/**
 *  Get hash value from key 
 *  
 *  args:
 *      max_hash_value: maximum value of hash, hash table size
 *
 *  return: (size_t) hash value 
 */
size_t Dict_get_hash(char* key, size_t max_hash_value);


/**
 *  Halper function to compare keys
 *  
 *  args:
 *      lhs: first key
 *      rhs: second key
 *
 *  return: (int) 0 if keys are equal, esle non-zero value 
 */
int Dict_key_comparer(void* lhs, void* rhs);


/**
 *  Alloc momery for Dict pointer and return it 
 *  
 *  args:
 *      max_hash_value: maximum value of hash, hash table size
 *
 *  return: (Dict*)list 
 */
Dict* Dict_create(size_t max_hash_value);


/**
 *  Remove of dictionary nodes and free there memory   
 *
 *  args:
 *      dict: poiner to Dict
 *  
 *  return: void
 */
void Dict_clean(Dict* dict);


/**
 *  Clean dictionary nodes, then free Dict pointer memory   
 *
 *  args:
 *      dict: poiner to Dict
 *  
 *  return: void
 */
void Dict_delete(Dict* dict);


/**
 *  Get current dictionary size, number of key/value pairs  
 *
 *  args:
 *      dict: poiner to Dict
 *  
 *  return: (size_t) dict size 
 */
size_t Dict_get_size(Dict* dict);


/**
 *  Check is key exists
 *
 *  args:
 *      dict: poiner to Dict
 *      key: key to check
 *  
 *  return: bool
 */
bool Dict_key_exist(Dict* dict, char* key);


/**
 *  Set value for a given key 
 *
 *  args:
 *      dict: poiner to Dict
 *      key: key for the value
 *      value: poiner value
 *  
 *  return: void
 */
void Dict_set(Dict* dict, char* key, void* value);


/**
 *  Get value for a given key 
 *
 *  args:
 *      dict: poiner to Dict
 *      key: key for the value
 *  
 *  return: (void*) value
 */
void* Dict_get(Dict* dict, char* key);


/**
 *  Set function, that can print dictionary node
 *
 *  args:
 *      dist: poiner to Dict
 *      printer: poiner to function, that can print dictionary node
 *  
 *  return: void
 */
void Dict_set_printer(Dict* dict, Dict_printer printer);


/**
 *  Print dictionary nodes key/value pairs (for DEBUG only)
 *
 *  args:
 *      dict: poiner to Dict
 *  
 *  return: void
 */
void Dict_print(Dict* dict);


#endif
