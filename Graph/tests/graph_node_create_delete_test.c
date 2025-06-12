#include "tests.h"

void graph_node_create_delete_test() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Create then delete graph node\n");
    
    Graph_node* graph_node;

    puts("Create graph node");
    graph_node = Graph_node_create("A");
    assert(graph_node != NULL);
    puts("");


    puts("Check node name");
    char* node_name = Graph_node_get_name(graph_node);
    assert(strcmp(node_name, "A") == 0);
    puts("");

    
    puts("Delete graph node");
    Graph_node_delete(graph_node);
    puts("");
}
