#include "tests.h"

static int comparer_string(void* lhs, void* rhs){
    return strcmp( *( (char**)lhs ), *( (char**)rhs ));
}

static void printer_string(void* value){
    printf("%s ", *( (char**)value ));
}

void graph_fill_get_node_names_test() {
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
    List_set_printer(node_names, printer_string);
    List_set_comparer(node_names, comparer_string);
    List_print(node_names);
    puts("\n");


    puts("Check nodes names");
    for (size_t i = 0; i < nodes_number; i++) {
        size_t idx = List_get_index_by_value_typed(node_names, nodes[i], char*);
        assert(idx != -1);
    }
    List_delete(node_names);
    puts("");

    
    puts("Delete graph");
    Graph_delete(graph);
    puts("");
}
