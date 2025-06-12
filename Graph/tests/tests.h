#ifndef TESTS_H
#define TESTS_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <Graph.h>


typedef void (*test_func_t)(void);

void graph_fill(Graph* graph);

// tests
void graph_node_create_delete_test();
void graph_node_add_get_siblings_test();
void graph_node_get_distance_test();
void graph_fill_print_test();
void graph_add_get_test();

#endif
