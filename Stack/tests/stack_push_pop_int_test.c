#include "tests.h"

static void printer_int(void* value){
    printf("%d ", *( (int*)value ));
}

void stack_push_pop_int_test() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Push then pop for stack of integers\n");

    int array[] = {1, 2, 3, 4, 5, 6, 7};
    size_t array_size = sizeof(array)/sizeof(int);

    size_t stack_size;

    
    puts("Create stack");
    Stack* stack = Stack_create();
    assert(stack);
    puts("");

    
    puts("Push data to stack");
    for (size_t i = 0; i < array_size; i++){
        printf("%lu: %d\n", i, array[i]);
        Stack_push_typed(stack, array[i], int);
    }
    puts("");

    
    stack_size = Stack_get_size(stack);
    printf("Stack size: %lu\n", stack_size);
    assert(stack_size == array_size);
    puts("");


    puts("Print stack");
    Stack_set_printer(stack, printer_int);
    Stack_print(stack);
    puts("\n");


    puts("Pop data from stack");
    for (size_t i = 0; i < array_size; i++){
        int temp = Stack_pop_typed(stack, int);
        printf("%lu: %d\n", i, temp);
        assert(temp == array[array_size - 1 - i]);
    }
    puts("");

    
    stack_size = Stack_get_size(stack);
    printf("Stack size: %lu\n", stack_size);
    assert(stack_size == 0);
    puts("");


    puts("Delete stack");
    Stack_delete(stack);
    assert(stack != NULL);
    puts("");
    
}
