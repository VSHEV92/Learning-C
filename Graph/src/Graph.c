#include "Graph.h"

 
static void node_names_printer(void* value){
    printf("%s ", *( (char**)value ));
}

static int node_names_comparer(void* lhs, void* rhs){
    return strcmp( *( (char**)lhs ), *( (char**)rhs ));
}

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
    List_delete(node_siblings);
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
    List* node_names = Graph_get_node_names(graph);

    for (size_t i = 0; i < graph->size; i++) {
        char* name = List_pop_front_typed(node_names, char*);
        Dict** distances = Dict_get(graph->nodes, name);
        Dict_delete(*distances);
        free(distances);
    }
    List_delete(node_names);

    graph->size = 0;
    Dict_clean(graph->nodes);
}


void Graph_delete(Graph* graph) {
    Graph_clean(graph);
    Dict_delete(graph->nodes);
    free(graph);
}


void Graph_add_node(Graph* graph, Graph_node* graph_node) {
    Dict** distances_ptr = malloc( sizeof(Dict*) );
    *distances_ptr = Dict_create(GRAPH_DICT_MAX_HASH);

    Graph_copy_distances(*distances_ptr, graph_node->distances);
    
    Dict_set_typed(graph->nodes, graph_node->name, *distances_ptr, Dict*);
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


size_t Graph_get_size(Graph* graph) {
    return graph->size;
}


List* Graph_get_node_names(Graph* graph) {
    List* list = Dict_get_keys(graph->nodes);
    List_set_printer(list, node_names_printer);
    List_set_comparer(list, node_names_comparer);
    return list;
}


List* Graph_get_node_siblings(Graph* graph, char* node_name) {
    Dict* node_dict = Dict_get_typed(graph->nodes, node_name, Dict*);
    List* siblings = Dict_get_keys(node_dict);
    List_set_printer(siblings, node_names_printer);
    List_set_comparer(siblings, node_names_comparer);
    return siblings;

}


int Graph_get_distance(Graph* graph, char* from_node, char* to_node) {
    Dict* node = Dict_get_typed(graph->nodes, from_node, Dict*);
    int distance = Dict_get_typed(node, to_node, int);
    return distance;
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


char* Graph_node_get_name(Graph_node* graph_node) {
    return graph_node->name; 
}


List* Graph_node_get_siblings(Graph_node* graph_node) {
    List* list = Dict_get_keys(graph_node->distances);
    List_set_printer(list, node_names_printer);
    List_set_comparer(list, node_names_comparer);
    return list;
}


void Graph_node_add_sibling(Graph_node* graph_node, char* sibling_name, int* sibling_distance) {
    Dict_set(graph_node->distances, sibling_name, sibling_distance);
}


int Graph_node_get_sibling_distance(Graph_node* graph_node, char* sibling_name) {
    int distance = Dict_get_typed(graph_node->distances, sibling_name, int);
    return distance;
}


void Graph_print(Graph* graph) {
    List* node_names = Graph_get_node_names(graph);
    size_t names_number = List_get_size(node_names);

    for (size_t i = 0; i < names_number; i++) {
        char* name = List_pop_front_typed(node_names, char*);
        Graph_node* node = Graph_get_node(graph, name);
        Graph_node_print(node);
        Graph_node_delete(node);
    }
    puts("");

    List_delete(node_names);
}


void Graph_node_print(Graph_node* graph_node) {
    printf("Node %s: ", graph_node->name);
    List* sibling_names = Dict_get_keys(graph_node->distances);
    size_t names_number = List_get_size(sibling_names);

    for (size_t i = 0; i < names_number; i++) {
        char* name = List_pop_front_typed(sibling_names, char*);
        int distance = Dict_get_typed(graph_node->distances, name, int);
        printf("%s -> %d, ", name, distance);
    }
    puts("");
    
    List_delete(sibling_names);
}
