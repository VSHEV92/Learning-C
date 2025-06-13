#include "tests.h"

void graph_node_add_get_siblings_test() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Add and get siblings of graph node\n");
    
    Graph_node* graph_node;

    char* siblings_names[] = {"A", "B", "C"};
    int siblings_dist[] = {1, 2, 2};
    size_t siblings_number = sizeof(siblings_names)/sizeof(char*);

    puts("Create graph node");
    graph_node = Graph_node_create("A");
    assert(graph_node != NULL);
    puts("");

    
    puts("Add siblings");
    for (size_t i = 0; i < siblings_number; i++) {
        Graph_node_add_sibling(graph_node, siblings_names[i], &siblings_dist[i]);
    }
    puts("");


    puts("Get siblings");
    List* siblings = Graph_node_get_siblings(graph_node);
    for (size_t i = 0; i < siblings_number; i++) {
        bool temp = List_value_exists_typed(siblings, siblings_names[i], char*);
        assert(temp == true);
    }
    List_delete(siblings);
    puts("");

    
    puts("Delete graph node");
    Graph_node_delete(graph_node);
    puts("");
}
