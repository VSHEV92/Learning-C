#include "Graph.h"


Graph* Graph_create() {
    Graph* graph = malloc( sizeof(Graph) );
    
    if (graph == NULL) {
        GRAPH_MALLOC_ERR;
    }

    graph->size = 0;
    graph->nodes = Dict_create(GRAPH_DICT_MAX_HASH);

    return graph;
}


void Graph_clean(Graph* graph) {
    graph->size = 0;
    Dict_clean(graph->nodes);
}


void Graph_delete(Graph* graph) {
    Dict_delete(graph->nodes);
    free(graph);
}


size_t Graph_get_size(Graph* graph) {
    return graph->size;
}
