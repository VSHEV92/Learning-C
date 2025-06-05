#include "tests.h"

void graph_add_print_test() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Add nodes to graph and print nodes\n");
    
    size_t graph_size;
    
    puts("Create graph");
    Graph* graph = Graph_create();
    assert(graph);
    puts("");



    puts("Clean graph");
    Graph_clean(graph);
    puts("");

    
    graph_size = Graph_get_size(graph);
    printf("Graph size: %lu\n", graph_size);
    assert(graph_size == 0);
    puts("");

    
    puts("Delete graph");
    Graph_delete(graph);
    assert(graph != NULL);
    puts("");
}
