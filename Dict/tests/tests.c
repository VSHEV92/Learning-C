#include "tests.h"

test_func_t tests[] = {
    dict_set_get_int_test,
    dict_set_clean_int_test,
    dict_set_exists_int_test,
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
