#include "tests.h"

test_func_t tests[] = {
    list_push_pop_front_int_test,
    list_push_pop_back_int_test,
    list_push_back_pop_front_int_test,

    list_push_back_clean_int_test,
    list_push_front_clean_int_test,

    list_push_front_get_by_index_int_test,
    list_push_front_set_by_index_int_test,
    list_push_front_get_by_value_int_test,


    list_push_pop_front_string_test,
    list_push_pop_back_string_test,
    list_push_back_pop_front_string_test,

    list_push_back_clean_string_test,
    list_push_front_clean_string_test,

    list_push_front_get_by_index_string_test,
    list_push_front_set_by_index_string_test,
    list_push_front_get_by_value_string_test,

    list_push_front_delete_head_by_index_int_test,
    list_push_front_delete_tail_by_index_int_test,
    list_push_front_delete_middle_by_index_int_test,
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
