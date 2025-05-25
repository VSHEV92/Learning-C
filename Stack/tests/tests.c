#include "tests.h"

test_func_t tests[] = {
    stack_push_pop_int_test,
    stack_clean_int_test,

    stack_push_pop_string_test,
    stack_clean_string_test,
};

int main() {

    for (size_t i = 0; i < sizeof(tests)/sizeof(test_func_t); i++){
        tests[i]();
    }

    puts(
        "--------------------\n"
        "--- TESTS PASSED ---\n"
        "--------------------\n"
    );

}
