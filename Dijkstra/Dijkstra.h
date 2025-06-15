#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <Graph.h>
#include <List.h>
#include <Dict.h>

#define BFS_DICT_MAX_HASH_SIZE 5

/**
 *  Dilkstra algorithm 
 *
 *  args:
 *      graph: poiner to Graph
 *      from_node: start graph node name
 *      to_node: destination graph node name
 *      path: List of node names, that needed to visit to get from start node to destination node
 *  
 *  return: (int) distance if path exists, else -1
 */
int Dijkstra (Graph* graph, char* from_node, char* to_node, List** path);


/**
 *  Delete path lsit, created by Dilkstra algorithm
 *
 *  args:
 *      path: List of node names, that needed to visit to get from start node to destination node
 *  
 *  return: void
 */
void dijkstra_delete_path(List** path);

#endif
