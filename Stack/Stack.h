#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>


/**
 *  Stack node - one element of Stack
 */
typedef struct Stack_node {
    void* value;                // pointer to value of node
    struct Stack_node* next;    // pointer to next stack node
} Stack_node;


/**
 *  Stack - stack data structure
 */
typedef struct {
    size_t size;        // number of stack nodes, stack size
    void* printer;      // pointer to function, that can print stack node value 
    Stack_node* top;    // pointer to top stack node
} Stack;


/**
 *  Type of function, that can print stack node value 
 */
typedef void (*Stack_printer)(void* value);


/**
 *  Helper macro for check malloc errors
 */
#define STACK_MALLOC_ERR {              \
    fprintf( stderr, "Malloc error" );  \
    exit(1);                            \
}


/**
 *  Helper macro for check pop from empty stack errors
 */
#define STACK_POP_ERR {                         \
    fprintf( stderr, "Pop from empty stack" );  \
    exit(1);                                    \
}


/**
 *  Helper macro for push data of certain type
 *  
 *  args:
 *      stack: pointer to Stack
 *      value: pushed vlaue
 *      type:  type of pushed value
 *  
 *  return: void
 */
#define Stack_push_typed(stack, value, type) {  \
        Stack_push(stack, &value);              \
    }                                           \


/**
 *  Helper macro for pop data of certain type
 *  
 *  args:
 *      stack: pointer to Stack
 *      type:  type of poped value
 *  
 *  return: (type)value
 */
#define Stack_pop_typed(stack, type) {(         \
        *( (type*)Stack_pop(stack) )            \
    )}                                          \


/**
 *  Alloc momery for Stack pointer and return in 
 *  
 *  return: (Stack*)stack 
 */
Stack* Stack_create();


/**
 *  Remove of stack nodes and free there memory   
 *
 *  args:
 *      stack: poiner to Stack
 *  
 *  return: void
 */
void Stack_clean(Stack* stack);


/**
 *  Clean stack nodes, then free stack pointer memory   
 *
 *  args:
 *      stack: poiner to Stack
 *  
 *  return: void
 */
void Stack_delete(Stack* stack);


/**
 *  Push value to stack 
 *
 *  args:
 *      stack: poiner to Stack
 *      value: poiner pushed value
 *  
 *  return: void
 */
void Stack_push(Stack* stack, void* value);


/**
 *  Pop value from stack 
 *
 *  args:
 *      stack: poiner to Stack
 *  
 *  return: (void*) pointer to poped value
 */
void* Stack_pop(Stack* stack);


/**
 *  Get current stack size  
 *
 *  args:
 *      stack: poiner to Stack
 *  
 *  return: (size_t) stack size 
 */
size_t Stack_get_size(Stack* stack);


/**
 *  Set function, that can print stack node value 
 *
 *  args:
 *      stack: poiner to Stack
 *      printer: poiner to function, that can print stack node value
 *  
 *  return: void
 */
void Stack_set_printer(Stack* stack, Stack_printer printer);


/**
 *  Print stack nodes value (for DEBUG only)
 *
 *  args:
 *      stack: poiner to Stack
 *  
 *  return: void
 */
void Stack_print(Stack* stack);


#endif
