#ifndef BSTREE_H
#define BSTREE_H

#include <stdlib.h>
#include <stdio.h>


/**
 *  Binary Search Tree node - one element of a tree
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
 *  Alloc momery for Stack pointer and return in 
 *  
 *  return: (Stack*)stack 
 */
//Stack* Stack_create();


/**
 *  Remove of stack nodes and free there memory   
 *
 *  args:
 *      stack: poiner to Stack
 *  
 *  return: void
 */
//void Stack_clean(Stack* stack);


/**
 *  Clean stack nodes, then free stack pointer memory   
 *
 *  args:
 *      stack: poiner to Stack
 *  
 *  return: void
 */
//void Stack_delete(Stack* stack);


/**
 *  Push value to stack 
 *
 *  args:
 *      stack: poiner to Stack
 *      value: poiner pushed value
 *  
 *  return: void
 */
//void Stack_push(Stack* stack, void* value);


#endif
