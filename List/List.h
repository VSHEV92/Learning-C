#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>


/**
 *  List node - one element of List
 */
typedef struct List_node {
    void* value;               // pointer to value of node
    struct List_node* next;    // pointer to next list node
    struct List_node* prev;    // pointer to previous list node
} List_node;


/**
 *  List - list data structure
 */
typedef struct {
    size_t size;         // number of list nodes, list size
    void* printer;       // pointer to function, that can print list node value 
    void* comparer;      // pointer to function, that can compare list nodes values
    List_node* head;     // pointer to head of the list
    List_node* tail;     // pointer to tail of the list
} List;


/**
 *  Type of function, that can print list node value 
 */
typedef void (*List_printer)(void* value);


/**
 *  Type of function, that can comparer list node values 
 */
typedef int (*List_comparer)(void* lhs, void* rhs);


/**
 *  Helper macro for check malloc errors
 */
#define LIST_MALLOC_ERR {              \
    fprintf( stderr, "Malloc error" ); \
    exit(1);                           \
}


/**
 *  Helper macro for check pop from empty list errors
 */
#define LIST_POP_ERR {                          \
    fprintf( stderr, "Pop from empty list" );   \
    exit(1);                                    \
}


/**
 *  Helper macro for check print when printer is NULL error
 */
#define LIST_PRINTER_ERR {                          \
    fprintf( stderr, "Print with NULL printer" );   \
    exit(1);                                        \
}


/**
 *  Helper macro for check compare when comparer is NULL error
 */
#define LIST_COMPARER_ERR {                           \
    fprintf( stderr, "Compare with NULL comparer" );  \
    exit(1);                                          \
}


/**
 *  Helper macro for index out of range error
 */
#define LIST_INDEX_ERR {                            \
    fprintf( stderr, "Index is out of range" );     \
    exit(1);                                        \
}


/**
 *  Helper macro for push front data of certain type
 *  
 *  args:
 *      list: pointer to List
 *      value: pushed vlaue
 *      type:  type of pushed value
 *  
 *  return: void
 */
#define List_push_front_typed(list, value, type) {  \
        List_push_front(list, &value);              \
    }                                               \


/**
 *  Helper macro for pop front data of certain type
 *  
 *  args:
 *      list: pointer to List
 *      type:  type of poped value
 *  
 *  return: (type)value
 */
#define List_pop_front_typed(list, type) {(     \
        *( (type*)List_pop_front(list) )        \
    )}                                          \


/**
 *  Helper macro for push back data of certain type
 *  
 *  args:
 *      list: pointer to List
 *      value: pushed vlaue
 *      type:  type of pushed value
 *  
 *  return: void
 */
#define List_push_back_typed(list, value, type) {   \
        List_push_back(list, &value);               \
    }                                               \


/**
 *  Helper macro for pop back data of certain type
 *  
 *  args:
 *      list: pointer to List
 *      type:  type of poped value
 *  
 *  return: (type)value
 */
#define List_pop_back_typed(list, type) {(     \
        *( (type*)List_pop_back(list) )        \
    )}                                         \


/**
 *  Helper macro for get data by index of certain type
 *  
 *  args:
 *      list: pointer to List
 *      index: index in list
 *      type:  type of value
 *  
 *  return: (type)value
 */
#define List_get_value_by_index_typed(list, index, type) {( \
        *( (type*)List_get_value_by_index(list, index) )    \
    )}                                                      \


/**
 *  Helper macro for set data by index of certain type
 *  
 *  args:
 *      list: pointer to List
 *      index: index in list
 *      value: value to set
 *      type:  type of value
 *  
 *  return: (type)value
 */
#define List_set_value_by_index_typed(list, index, value, type) {     \
        List_set_value_by_index(list, index, &value);                 \
    }                                                                 \


/**
 *  Helper macro for get index by value of certain type
 *  
 *  args:
 *      list: pointer to List
 *      value: value in list
 *      type:  type of value value
 *  
 *  return: ssize_t. Index if value in list, -1 otherwise
 */
#define List_get_index_by_value_typed(list, value, type) {( \
        List_get_index_by_value(list, &value)               \
    )}                                                      \


/**
 *  Alloc momery for List pointer and return it 
 *  
 *  return: (List*)list 
 */
List* List_create();


/**
 *  Remove of list nodes and free there memory   
 *
 *  args:
 *      list: poiner to List
 *  
 *  return: void
 */
void List_clean(List* list);


/**
 *  Clean list nodes, then free list pointer memory   
 *
 *  args:
 *      list: poiner to List
 *  
 *  return: void
 */
void List_delete(List* list);


/**
 *  Push value to head of the list 
 *
 *  args:
 *      list: poiner to List
 *      value: poiner pushed value
 *  
 *  return: void
 */
void List_push_front(List* list, void* value);


/**
 *  Pop front value from head of the list 
 *
 *  args:
 *      list: poiner to List
 *  
 *  return: (void*) pointer to poped value
 */
void* List_pop_front(List* list);


/**
 *  Push value to tail of the list 
 *
 *  args:
 *      list: poiner to List
 *      value: poiner pushed value
 *  
 *  return: void
 */
void List_push_back(List* list, void* value);


/**
 *  Pop front value from tail of the list 
 *
 *  args:
 *      list: poiner to List
 *  
 *  return: (void*) pointer to poped value
 */
void* List_pop_back(List* list);


/**
 *  Get current list size  
 *
 *  args:
 *      list: poiner to List
 *  
 *  return: (size_t) list size 
 */
size_t List_get_size(List* list);


/**
 *  Get value by index in list  
 *
 *  args:
 *      list: poiner to List
 *      index: index in list
 *  
 *  return: (void*) pointer to poped value 
 */
void* List_get_value_by_index(List* list, size_t index);


/**
 *  Delete value by index in list  
 *
 *  args:
 *      list: poiner to List
 *      index: index in list
 *  
 *  return: void
 */
void List_delete_value_by_index(List* list, size_t index);


/**
 *  Set value by index in list  
 *
 *  args:
 *      list: poiner to List
 *      index: index in list
 *      value: value to set
 *  
 *  return: void
 */
void List_set_value_by_index(List* list, size_t index, void* value);


/**
 *  Get index by value in list  
 *
 *  args:
 *      list: poiner to List
 *      value: value in list
 *  
 *  return: (ssize_t) Index if value in list, -1 otherwise 
 */
ssize_t List_get_index_by_value(List* list, void* value);


/**
 *  Set function, that can print list node value 
 *
 *  args:
 *      list: poiner to List
 *      printer: poiner to function, that can print list node value
 *  
 *  return: void
 */
void List_set_printer(List* list, List_printer printer);


/**
 *  Print list nodes value (for DEBUG only)
 *
 *  args:
 *      list: poiner to List
 *  
 *  return: void
 */
void List_print(List* list);


/**
 *  Set function, that can compare list node values
 *  Return in value:
 *      lhs > rhs - return > 0
 *      lhs < rhs - return < 0
 *      lhs = rhs - return = 0
 *
 *  args:
 *      list: poiner to List
 *      printer: poiner to function, that can compare list nodes values
 *  
 *  return: int. 
 */
void List_set_comparer(List* list, List_comparer comparer);


#endif
