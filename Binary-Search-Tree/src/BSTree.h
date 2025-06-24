#ifndef BSTREE_H
#define BSTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 *  Helper macro for check malloc errors
 */
#define BSTREE_MALLOC_CHECK(pointer)         \
    if (pointer == NULL) {                   \
        fprintf( stderr, "Malloc error\n" ); \
        exit(1);                             \
    }

/**
 *  Binary Search Tree node - one element of a tree
 */
typedef struct BSTree_node {
    int value;                   // value of node
    struct BSTree_node* left;    // pointer to next left node (lesser values)
    struct BSTree_node* right;   // pointer to next right node (greater values)
} BSTree_node;


/**
 *  Binary Search Tree data structure
 */
typedef struct {
    size_t size;        // number of nodes in BSTree
    BSTree_node* top;   // pointer to root node of the tree
} BSTree;


/**
 *  Alloc momery for BSTree pointer and return in 
 *  
 *  return: (BSTree*)tree 
 */
BSTree* BSTree_create();


/**
 *  Remove all nodes and free there memory   
 *
 *  args:
 *      binary search tree: poiner to BSTree
 *  
 *  return: void
 */
void BSTree_clean(BSTree* tree);


/**
 *  Clean all nodes, then free tree pointer memory   
 *
 *  args:
 *      binary search tree: poiner to BSTree
 *  
 *  return: void
 */
void BSTree_delete(BSTree* tree);


/**
 *  Get current tree size (nodes number)  
 *
 *  args:
 *      binary search tree: poiner to BSTree
 *  
 *  return: (size_t) tree size 
 */
size_t BSTree_get_size(BSTree* tree);


/**
 *  Add node to binary search tree   
 *
 *  args:
 *      binary search tree: poiner to BSTree
 *      value: node value
 *  
 *  return: void
 */
void BSTree_add(BSTree* tree, int value);


/**
 *  Chack that node exists in binary search tree   
 *
 *  args:
 *      binary search tree: poiner to BSTree
 *      value: node value
 *  
 *  return: void
 */
bool BSTree_exists(BSTree* tree, int value);


/**
 *  Get max value in binary search tree   
 *
 *  args:
 *      binary search tree: poiner to BSTree
 *  
 *  return: (int) max value
 */
int BSTree_get_max(BSTree* tree);


/**
 *  Get min value in binary search tree   
 *
 *  args:
 *      binary search tree: poiner to BSTree
 *  
 *  return: (int) min value
 */
int BSTree_get_min(BSTree* tree);


/**
 *  Get all in tree values as a sorted array   
 *
 *  args:
 *      binary search tree: poiner to BSTree
 *  
 *  return: (int*) array of tree values
 */
int* BSTree_get_values(BSTree* tree);


/**
 *  Print all nodes   
 *
 *  args:
 *      binary search tree: poiner to BSTree
 *  
 *  return: void
 */
void BSTree_print_nodes(BSTree* tree);






/**
 *  Alloc momery for BSTree node pointer and return in 
 *  
 *  args:
 *      value: node value
 *
 *  return: (BSTree_node*)tree node 
 */
BSTree_node* BSTree_node_create(int value);


/**
 *  Free node pointer memory   
 *
 *  args:
 *      tree node: poiner to BSTree_node
 *  
 *  return: void
 */
void BSTree_node_delete(BSTree_node* node);


/**
 *  Print single node   
 *
 *  args:
 *      tree node: poiner to BSTree_node
 *  
 *  return: void
 */
void BSTree_node_print(BSTree_node* node);


#endif
