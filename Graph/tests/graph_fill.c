#include "tests.h"

// helper macro to fill node siblings
#define GRAPH_TEST_FILL_NODE(node_name) \
{\
    Graph_node* graph_node = Graph_node_create(#node_name); \
    size_t siblings_number = sizeof(node_name ## _node_sibling_names)/sizeof(char*); \
    for (size_t i = 0; i < siblings_number; i++) { \
        Graph_node_add_sibling(graph_node, node_name ## _node_sibling_names[i], &node_name ## _node_sibling_dist[i]); \
    }\
    Graph_node_print(graph_node); \
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

    GRAPH_TEST_FILL_NODE(A);
    GRAPH_TEST_FILL_NODE(B);
    GRAPH_TEST_FILL_NODE(C);
    GRAPH_TEST_FILL_NODE(D);
    GRAPH_TEST_FILL_NODE(E);
    GRAPH_TEST_FILL_NODE(F);
    GRAPH_TEST_FILL_NODE(G);
    GRAPH_TEST_FILL_NODE(H);

}
