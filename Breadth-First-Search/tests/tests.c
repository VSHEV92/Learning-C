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
    test_path(graph, "A", "D", 2);
    test_path(graph, "A", "H", 4);
    test_path(graph, "A", "I", -1);
    puts("");


    puts(
        "--------------------\n"
        "--- TESTS PASSED ---\n"
        "--------------------\n"
    );

}

void test_path(Graph* graph, char* from, char* to, int gold_distance) {
    int result;
    List** path = malloc( sizeof(List*) );

    result = Breadth_First_Search(graph, from, to, path);
    printf("From: %s\n", from);
    printf("To: %s\n", to);
    printf("Distance: %d\n", result);
    printf("Path: ");
    if (result != -1) {
        List_set_printer(*path, path_printer);
        List_print(*path);
        puts("");
    }
    puts("");
    assert(result == gold_distance);
}
