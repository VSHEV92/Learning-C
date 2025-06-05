#include "Graph.h"

// printer function for Graph node siblings dictionary
static void Graph_node_sibling_printer(void* node){
    Dict_node* dict_node = (Dict_node*) node;
    printf("%s -> %d, ", dict_node->key, *((int*)dict_node->value) );
}

// helper function for copy Graph node siblings dictionary
static void Graph_copy_distances(Dict* dict_to, Dict* dict_from) {
    List* node_siblings = Dict_get_keys(dict_from);

    for (size_t i = 0; i < List_get_size(node_siblings); i++) {
        char* sibling_name = List_get_value_by_index_typed(node_siblings, i, char*);
        int* sibling_distance = Dict_get(dict_from, sibling_name);

        Dict_set(dict_to, sibling_name, sibling_distance);
    }
}

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
    // TODO: delete sub dictionaries
    Dict_clean(graph->nodes);
}


void Graph_delete(Graph* graph) {
    Dict_delete(graph->nodes);
    free(graph);
}


size_t Graph_get_size(Graph* graph) {
    return graph->size;
}


Graph_node* Graph_node_create(char* name) {

    Graph_node* graph_node = malloc( sizeof(Graph_node) );
    
    if (graph_node == NULL) {
        GRAPH_MALLOC_ERR;
    }

    graph_node->name = name;
    graph_node->distances = Dict_create(GRAPH_DICT_MAX_HASH);
    Dict_set_printer(graph_node->distances, Graph_node_sibling_printer);

    return graph_node;
}


void Graph_node_delete(Graph_node* graph_node) {
    Dict_delete(graph_node->distances);
    free(graph_node);
}


void Graph_add_node(Graph* graph, Graph_node* graph_node) {
    Dict* distances = Dict_create(GRAPH_DICT_MAX_HASH);

    Graph_copy_distances(distances, graph_node->distances);
    
    Dict_set_typed(graph->nodes, graph_node->name, distances, Dict*);
    graph->size++;
}


Graph_node* Graph_get_node(Graph* graph, char* node_name) {
    if ( !Dict_key_exist(graph->nodes, node_name) ) {
        GRAPH_NODE_NAME_ERR;
    }

    Dict* distances = Dict_get_typed(graph->nodes, node_name, Dict*);
    Graph_node* graph_node = Graph_node_create(node_name);

    Graph_copy_distances(graph_node->distances, distances);

    return graph_node;
}


void Graph_node_add_sibling(Graph_node* graph_node, char* sibling_name, int* sibling_distance) {
    Dict_set(graph_node->distances, sibling_name, sibling_distance);
}


void Graph_node_print(Graph_node* graph_node) {
    printf("\nNode name: %s\n", graph_node->name);
    Dict_print(graph_node->distances);
    puts("");
}
