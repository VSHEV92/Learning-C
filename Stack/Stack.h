#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

#define STACK_MALLOC_ERR {              \
    fprintf( stderr, "Malloc error" );  \
    exit(1);                            \
}

#define STACK_POP_ERR {                         \
    fprintf( stderr, "Pop from empty stack" );  \
    exit(1);                                    \
}

typedef struct Stack_node {
    void* value;
    struct Stack_node* next;
} Stack_node;


typedef struct {
    size_t size;
    void* printer;
    Stack_node* top;
} Stack;

typedef void (*Stack_printer)(void* value);



Stack* Stack_create();

void Stack_clean(Stack* stack);

void Stack_delete(Stack* stack);

void Stack_push(Stack* stack, void* value);

void* Stack_pop();

size_t Stack_get_size(Stack* stack);

void Stack_set_printer(Stack* stack, Stack_printer printer);

void Stack_print(Stack* stack);


#endif
