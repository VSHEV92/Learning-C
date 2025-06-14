#include "tests.h"

// helper macro to fill node siblings
#define GRAPH_TEST_FILL_NODE(graph, node_name) \
{\
    Graph_node* graph_node = Graph_node_create(#node_name); \
    size_t siblings_number = sizeof(node_name ## _node_sibling_names)/sizeof(char*); \
    for (size_t i = 0; i < siblings_number; i++) { \
        Graph_node_add_sibling(graph_node, node_name ## _node_sibling_names[i], &node_name ## _node_sibling_dist[i]); \
    }\
    Graph_add_node(graph, graph_node); \
    Graph_node_delete(graph_node); \
}

// Test graph nodes
char* A_node_sibling_names[] = {"B", "C"};
int A_node_sibling_dist[] = {1, 4};

char* B_node_sibling_names[] = {"C", "F"};
int B_node_sibling_dist[] = {2, 9};

char* C_node_sibling_names[] = {"D"};
int C_node_sibling_dist[] = {1};

char* D_node_sibling_names[] = {"E"};
int D_node_sibling_dist[] = {1};

char* E_node_sibling_names[] = {"F", "H"};
int E_node_sibling_dist[] = {1, 3};

char* F_node_sibling_names[] = {"G"};
int F_node_sibling_dist[] = {1};

char* G_node_sibling_names[] = {"B", "H"};
int G_node_sibling_dist[] = {4, 5};

char* H_node_sibling_names[] = {"G"};
int H_node_sibling_dist[] = {2};

void graph_fill(Graph* graph) {

    GRAPH_TEST_FILL_NODE(graph, A);
    GRAPH_TEST_FILL_NODE(graph, B);
    GRAPH_TEST_FILL_NODE(graph, C);
    GRAPH_TEST_FILL_NODE(graph, D);
    GRAPH_TEST_FILL_NODE(graph, E);
    GRAPH_TEST_FILL_NODE(graph, F);
    GRAPH_TEST_FILL_NODE(graph, G);
    GRAPH_TEST_FILL_NODE(graph, H);

}
