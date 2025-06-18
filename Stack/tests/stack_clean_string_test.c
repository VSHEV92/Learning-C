#include "tests.h"

static void printer_string(void* value){
    printf("%s ", *( (char**)value ));
}

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Push then clean for stack of strings\n");

    char* array[] = {"foo", "bar", "one", "two"};
    size_t array_size = sizeof(array)/sizeof(char*);

    size_t stack_size;

    
    puts("Create stack");
    Stack* stack = Stack_create();
    assert(stack);
    puts("");

    
    puts("Push data to stack");
    for (size_t i = 0; i < array_size; i++){
        printf("%lu: %s\n", i, array[i]);
        Stack_push_typed(stack, array[i], char*);
    }
    puts("");

    
    stack_size = Stack_get_size(stack);
    printf("Stack size: %lu\n", stack_size);
    assert(stack_size == array_size);
    puts("");


    puts("Print stack");
    Stack_set_printer(stack, printer_string);
    Stack_print(stack);
    puts("\n");


    puts("Clean stack");
    Stack_clean(stack);
    puts("");

    
    stack_size = Stack_get_size(stack);
    printf("Stack size: %lu\n", stack_size);
    assert(stack_size == 0);
    puts("");


    puts("Delete stack");
    Stack_delete(stack);
    assert(stack != NULL);
    puts("");
    
    return 0;
}
