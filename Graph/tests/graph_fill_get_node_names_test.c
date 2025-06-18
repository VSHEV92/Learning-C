#include "tests.h"

int main() {
    puts("");
    puts("-----------------------------------------------------");
    puts("TEST: Fill nodes to graph and node names\n");


    char* nodes[] = {"A", "B", "C", "D", "E", "F", "G", "H"};
    size_t nodes_number = sizeof(nodes)/sizeof(char*);
    
    puts("Create graph");
    Graph* graph = Graph_create();
    assert(graph);
    puts("");


    puts("Fill graph");
    graph_fill(graph);
    puts("");


    puts("Get node names");
    List* node_names = Graph_get_node_names(graph);
    assert(node_names);
    puts("");


    puts("Print node names");
    List_print(node_names);
    puts("\n");


    puts("Check nodes names");
    for (size_t i = 0; i < nodes_number; i++) {
        bool temp = List_value_exists_typed(node_names, nodes[i], char*);
        assert(temp == true);
    }
    List_delete(node_names);
    puts("");

    
    puts("Delete graph");
    Graph_delete(graph);
    puts("");

    return 0;
}
