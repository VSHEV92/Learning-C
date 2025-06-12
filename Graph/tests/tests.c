#include "tests.h"

test_func_t tests[] = {
    graph_node_create_delete_test,
    graph_node_add_get_siblings_test,
    graph_node_get_distance_test,
    graph_fill_print_test,
    graph_add_get_test,
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
