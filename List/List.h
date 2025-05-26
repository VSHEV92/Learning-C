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
    List_node* head;     // pointer to head of the list
    List_node* tail;     // pointer to tail of the list
} List;


/**
 *  Type of function, that can print stack node value 
 */
typedef void (*List_printer)(void* value);


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
 *  Get current list size  
 *
 *  args:
 *      list: poiner to List
 *  
 *  return: (size_t) list size 
 */
size_t List_get_size(List* list);


/**
 *  Set function, that can print list node value 
 *
 *  args:
 *      list: poiner to List
 *      printer: poiner to function, that can print lsit node value
 *  
 *  return: void
 */
void List_set_printer(List* List, List_printer printer);


/**
 *  Print list nodes value (for DEBUG only)
 *
 *  args:
 *      list: poiner to List
 *  
 *  return: void
 */
void List_print(List* list);


#endif
