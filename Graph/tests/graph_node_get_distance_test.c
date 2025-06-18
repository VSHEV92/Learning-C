#include "tests.h"

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Add siblings and get there distance\n");
    
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


    puts("Get distances");
    for (size_t i = 0; i < siblings_number; i++) {
        int distance = Graph_node_get_sibling_distance(graph_node, siblings_names[i]);
        assert(distance == siblings_dist[i]);
    }
    puts("");

    
    puts("Delete graph node");
    Graph_node_delete(graph_node);
    puts("");

    return 0;
}
