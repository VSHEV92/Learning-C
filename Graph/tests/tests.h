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
void graph_add_print_test();

#endif
