#include "tests.h"

static int comparer_string(void* lhs, void* rhs){
    return strcmp( *( (char**)lhs ), *( (char**)rhs ));
}

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
    List_set_comparer(siblings, comparer_string);
    for (size_t i = 0; i < siblings_number; i++) {
        size_t idx = List_get_index_by_value_typed(siblings, siblings_names[i], char*);
        assert(idx != -1);
    }
    List_delete(siblings);
    puts("");

    
    puts("Delete graph node");
    Graph_node_delete(graph_node);
    puts("");
}
