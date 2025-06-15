#include "tests.h"

static void path_printer(void* value){
    printf("%s ", *( (char**)value ));
}

void test_path(Graph* graph, char* from, char* to, int gold_distance);

int main() {
    
    puts("Create and fill graph");
    Graph* graph = Graph_create();
    graph_fill(graph);
    Graph_print(graph);

    puts("---- Test paths from A node ----\n");
    test_path(graph, "A", "B", 1);
    test_path(graph, "A", "D", 4);
    test_path(graph, "A", "H", 8);
    puts("");

    puts("---- Test paths from D node ----\n");
    test_path(graph, "D", "D", 0);
    test_path(graph, "D", "G", 3);
    test_path(graph, "D", "A", -1);
    puts("");

    puts("---- Test paths from F node ----\n");
    test_path(graph, "F", "B", 5);
    test_path(graph, "F", "C", 7);
    test_path(graph, "F", "H", 6);
    puts("");

    puts("---- Test paths from H node ----\n");
    test_path(graph, "H", "B", 6);
    test_path(graph, "H", "E", 10);
    test_path(graph, "H", "F", 11);
    puts("");


    puts(
        "--------------------\n"
        "--- TESTS PASSED ---\n"
        "--------------------\n"
    );

    Graph_delete(graph);
}

void test_path(Graph* graph, char* from, char* to, int gold_distance) {
    int result;
    List** path = malloc( sizeof(List*) );

    result = Dijkstra(graph, from, to, path);
    
    printf("From: %s\n", from);
    printf("To: %s\n", to);
    printf("Distance: %d\n", result);
    printf("Path: ");
    if (result != -1) {
        List_set_printer(*path, path_printer);
        List_print(*path);
        dijkstra_delete_path(path);
        puts("");
    }
    puts("");
    
    assert(result == gold_distance);
    
    free(path);
}
