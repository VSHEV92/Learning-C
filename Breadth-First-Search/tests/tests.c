#include "tests.h"

int main() {

    
    puts("Create and fill graph");
    Graph* graph = Graph_create();
    graph_fill(graph);
    Graph_print(graph);

    int result;

    result = Breadth_First_Search(graph, "A", "B", NULL);
    printf("From: %s\n", "A");
    printf("To: %s\n", "B");
    printf("Distance: %d\n", result);
    puts("Path:");

    puts("");


    puts(
        "--------------------\n"
        "--- TESTS PASSED ---\n"
        "--------------------\n"
    );

}
