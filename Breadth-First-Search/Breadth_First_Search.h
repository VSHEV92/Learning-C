#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include <Graph.h>
#include <List.h>
#include <Dict.h>

/**
 *  Breadth First Search algorithm 
 *
 *  args:
 *      graph: poiner to Graph
 *      from_node: start graph node name
 *      to_node: destination graph node name
 *      path: List of node names, that needed to visit to get from start node to destination node
 *  
 *  return: (int) distance if path exists, else -1
 */
int Breadth_First_Search (Graph* graph, char* from_node, char* to_node, List** path);

#endif
