#include "tests.h"

void graph_add_get_test() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Add and get nodes to graph nodes\n");
    
    size_t graph_size;
    
    puts("Create graph");
    Graph* graph = Graph_create();
    assert(graph);
    puts("");

    Graph_node* graph_node;

    puts("Add node A nad B");
    graph_node = Graph_node_create("A");
    Graph_add_node(graph, graph_node);
    Graph_node_delete(graph_node);

    graph_node = Graph_node_create("B");
    Graph_add_node(graph, graph_node);
    Graph_node_delete(graph_node);
    puts("");


    graph_size = Graph_get_size(graph);
    printf("Graph size: %lu\n", graph_size);
    assert(graph_size == 2);
    puts("");


    Graph_print(graph);


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
