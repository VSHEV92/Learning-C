#include "tests.h"

void graph_add_get_test() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Add and get nodes to graph nodes\n");
    
    size_t graph_size;
    Graph_node* graph_node;
    
    char* siblings_names[] = {"A", "B", "C"};
    int siblings_dist[] = {1, 2, 2};
    size_t siblings_number = sizeof(siblings_names)/sizeof(char*);

    puts("Create graph");
    Graph* graph = Graph_create();
    assert(graph);
    puts("");


    puts("Add node");
    graph_node = Graph_node_create("A");
    for (size_t i = 0; i < siblings_number; i++) {
        Graph_node_add_sibling(graph_node, siblings_names[i], &siblings_dist[i]);
    }
    Graph_add_node(graph, graph_node);
    Graph_node_delete(graph_node);
    puts("");


    graph_size = Graph_get_size(graph);
    printf("Graph size: %lu\n", graph_size);
    assert(graph_size == 1);
    puts("");


    puts("Get node");
    graph_node = Graph_get_node(graph, "A");
    assert(graph_node);
    puts("");


    puts("Check siblings");
    List* siblings = Graph_node_get_siblings(graph_node);
    for (size_t i = 0; i < siblings_number; i++) {
        bool temp = List_value_exists_typed(siblings, siblings_names[i], char*);
        assert(temp == true);
    }
    List_delete(siblings);
    puts("");


    puts("Check distances");
    for (size_t i = 0; i < siblings_number; i++) {
        int distance = Graph_node_get_sibling_distance(graph_node, siblings_names[i]);
        assert(distance == siblings_dist[i]);
    }
    puts("");


    puts("Delete graph node");
    Graph_node_delete(graph_node);
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
    puts("");
}
