#include "Stack.h"

Stack* Stack_create() {
    Stack* stack = malloc( sizeof(Stack) );
    
    if (stack == NULL) {
        STACK_MALLOC_ERR;
    }

    stack->size = 0;
    stack->printer = NULL;
    stack->top = NULL;

    return stack;
}


void Stack_clean(Stack* stack) {
    while ( Stack_get_size(stack) > 0) {
        Stack_pop(stack);
    } 
}


void Stack_delete(Stack* stack) {
    Stack_clean(stack);
    free(stack);
}


void Stack_push(Stack* stack, void* value) { 
    Stack_node* node = malloc( sizeof(Stack_node) );

    if (node == NULL) {
        STACK_MALLOC_ERR;
    }

    node->value = value;
    node->next = stack->top;
    
    stack->top = node;
    stack->size++;
}


void* Stack_pop(Stack* stack) {

    if (stack->top == NULL) {
        STACK_POP_ERR;
    }

    void* value = stack->top->value;
    
    Stack_node* to_remove = stack->top;

    stack->top = stack->top->next;
    stack->size--;
    
    free(to_remove);

    return value;
}


size_t Stack_get_size(Stack* stack) {
    return stack->size;
}


void Stack_set_printer(Stack* stack, Stack_printer printer) {
    stack->printer = printer;
}


void Stack_print(Stack* stack) {
    Stack* temp_stack = Stack_create();
    Stack_printer printer = (Stack_printer)stack->printer;

    // get value from stack, print and save to temp stacl
    while ( Stack_get_size(stack) > 0) {
        void* value = Stack_pop(stack);
        printer(value);
        Stack_push(temp_stack, value);
    } 

    // copy back from temp stack to stack
    while ( Stack_get_size(temp_stack) > 0) {
        void* value = Stack_pop(temp_stack);
        Stack_push(stack, value);
    } 
    
    Stack_delete(temp_stack);
}
