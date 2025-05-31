#ifndef DICT_H
#define DICT_H

#include <List.h>

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
    void* printer;       // pointer to function, that can print dictionary node value 
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
 *  Helper macro for check print when printer is NULL error
 */
#define DICT_PRINTER_ERR {                          \
    fprintf( stderr, "Print with NULL printer" );   \
    exit(1);                                        \
}


/**
 *  Helper macro for key out of range error
 */
#define DICT_KEY_ERR {                              \
    fprintf( stderr, "Key is not exists" );         \
    exit(1);                                        \
}


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
 *  Set function, that can print dictionary node
 *
 *  args:
 *      dist: poiner to Dict
 *      printer: poiner to function, that can print dictionary node
 *  
 *  return: void
 */
void Dict_set_printer(Dict* dict, Dict_printer printer);


#endif
