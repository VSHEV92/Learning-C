#ifndef GRAPH_H
#define GRAPH_H

#include <Graph.h>
#include <Dict.h>
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
 *  Get number of graph nodes  
 *
 *  args:
 *      graph: poiner to Graph
 *  
 *  return: (size_t) nodes number 
 */
size_t Graph_get_size(Graph* graph);



#endif
