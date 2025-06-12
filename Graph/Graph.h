#ifndef GRAPH_H
#define GRAPH_H

#include <Graph.h>
#include <Dict.h>
#include <List.h>
#include <string.h>
#include <stdbool.h>

/**
 *  Graph node - one element of Graph
 */
typedef struct Graph_node {
    char* name;         // graph node name
    Dict* distances;    // distances to sibling nodes
} Graph_node;


/**
 *  Graph - graph data structure
 */
typedef struct {
    size_t size;  // number of graph nodes
    Dict* nodes;  // dictionary of nodes. Key - node, value - dictionary of siblings
} Graph;


/**
 *  Max hash value for internal dictionaries
 */
#ifndef GRAPH_DICT_MAX_HASH
#define GRAPH_DICT_MAX_HASH 5
#endif


/**
 *  Helper macro for check malloc errors
 */
#define GRAPH_MALLOC_ERR {             \
    fprintf( stderr, "Malloc error" ); \
    exit(1);                           \
}


/**
 *  Helper macro for node name out of range error
 */
#define GRAPH_NODE_NAME_ERR {                       \
    fprintf( stderr, "Node name is not exists" );   \
    exit(1);                                        \
}


/**
 *  Alloc momery for Graph pointer and return it 
 *
 *  return: (Graph*)graph 
 */
Graph* Graph_create();


/**
 *  Remove all graph nodes and free there memory   
 *
 *  args:
 *      graph: poiner to Graph
 *  
 *  return: void
 */
void Graph_clean(Graph* graph);


/**
 *  Clean graph nodes, then free graph pointer memory   
 *
 *  args:
 *      graph: poiner to Graph
 *  
 *  return: void
 */
void Graph_delete(Graph* graph);


/**
 *  Add graph node to graph   
 *
 *  args:
 *      graph: poiner to Graph
 *      graph_node: poiner to Graph node
 *  
 *  return: void
 */
void Graph_add_node(Graph* graph, Graph_node* graph_node);


/**
 *  Get graph node from graph   
 *
 *  args:
 *      graph: poiner to Graph
 *      node_name: graph node name
 *  
 *  return: (Graph_node*)graph_node
 */
Graph_node* Graph_get_node(Graph* graph, char* node_name);


/**
 *  Get number of graph nodes  
 *
 *  args:
 *      graph: poiner to Graph
 *  
 *  return: (size_t) nodes number 
 */
size_t Graph_get_size(Graph* graph);


/**
 *  Get a List of exits node names
 *
 *  args:
 *      graph: poiner to Graph
 *  
 *  return: (List*) node_names
 */
List* Graph_get_node_names(Graph* graph);


/**
 *  Alloc momery for Graph node pointer and return it 
 *
 *  args:
 *      name: Graph node name
 *
 *  return: (Graph_node*)graph_node 
 */
Graph_node* Graph_node_create(char* name);


/**
 *  Clean graph node siblings, then free graph node pointer memory   
 *
 *  args:
 *      graph_node: poiner to Graph node
 *  
 *  return: void
 */
void Graph_node_delete(Graph_node* graph_node);


/**
 *  Get graph node name  
 *
 *  args:
 *      graph_node: poiner to Graph node
 *  
 *  return: (char*) graph node name
 */
char* Graph_node_get_name(Graph_node* graph_node);


/**
 *  Add sibling to graph node   
 *
 *  args:
 *      graph_node: poiner to Graph node
 *      sibling_name: name of sibling node
 *      sibling_distance: distance to sibling node
 *  
 *  return: void
 */
void Graph_node_add_sibling(Graph_node* graph_node, char* sibling_name, int* sibling_distance);


/**
 *  Get siblings names
 *
 *  args:
 *      graph_node: poiner to Graph node
 *  
 *  return: (List*) List of siblings names
 */
List* Graph_node_get_siblings(Graph_node* graph_node);


/**
 *  Get distance to sibling
 *
 *  args:
 *      graph_node: poiner to Graph node
 *      sibling_name: name of sibling node
 *  
 *  return: (int) distance to sibling
 */
int Graph_node_get_sibling_distance(Graph_node* graph_node, char* sibling_name);


/**
 *  Print graph (for DEBUG only)
 *
 *  args:
 *      graph: poiner to Graph
 *  
 *  return: void
 */
void Graph_print(Graph* graph);


/**
 *  Print graph node (for DEBUG only)
 *
 *  args:
 *      graph_node: poiner to Graph_node
 *  
 *  return: void
 */
void Graph_node_print(Graph_node* graph_node);

#endif
