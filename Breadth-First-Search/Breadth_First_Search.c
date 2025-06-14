#include "Breadth_First_Search.h"


static int node_name_comparer(void* lhs, void* rhs);
static void debug_list_printer(void* value);
static void debug_dict_printer(void* node);

static int bfs_create_path(Dict* from_to_node_names, char* from_node, char* to_node, List** path);


int Breadth_First_Search (Graph* graph, char* from_node, char* to_node, List** path) {

    // list of processed and not processed node names
    List* nodes_needed_to_process = List_create();
    List_set_printer(nodes_needed_to_process, debug_list_printer);

    List* nodes_already_processed = List_create();
    List_set_comparer(nodes_already_processed, node_name_comparer);
    List_set_printer(nodes_already_processed, debug_list_printer);

    // Disctionary that collect from/to node names relationships.
    // Used to create BFS path.
    Dict* from_to_node_names = Dict_create(BFS_DICT_MAX_HASH_SIZE);
    Dict_set_printer(from_to_node_names, debug_dict_printer);

    // distanation node is reached
    bool to_node_reached = false;

    // add start node to need to process list
    List_push_back_typed(nodes_needed_to_process, from_node, char*);

    // node process loop
    while ( List_get_size(nodes_needed_to_process) > 0 ) {
        
        // get next node name and set it as processed
        char** processed_node = List_pop_front(nodes_needed_to_process);
        List_push_back_typed(nodes_already_processed, *processed_node, char*);

        // distanation node is found
        if ( strcmp(to_node, *processed_node) == 0 ){
            to_node_reached = true;
            break;
        }

        // add siblings nodes to need to process list
        List* siblings = Graph_get_node_siblings(graph, *processed_node);
        size_t siblings_number = List_get_size(siblings);

        for (size_t i = 0; i < siblings_number; i++) {
            char** sibling_name = List_pop_front(siblings);
            bool is_already_processed = List_value_exists_typed(nodes_already_processed, *sibling_name, char*);
           
            if ( !is_already_processed ) {
                List_push_back_typed(nodes_needed_to_process, *sibling_name, char*);

                // fill from/to node name relationship
                Dict_set_typed(from_to_node_names, *sibling_name, *processed_node, char*);
            }
        }
    }

    // if path to distination node not found, return from function
    if (!to_node_reached) {
        *path = NULL;
        return -1;
    }

    // create path from start to destination node and calculate distance
    return bfs_create_path(from_to_node_names, from_node, to_node, path);
}


void bfs_delete_path(List** path) {

}


// halper function, used to create path from start to destination node and calculate distance
// we need to use malloc, so that pointer not destroyed after function return 
static int bfs_create_path(Dict* from_to_node_names, char* from_node, char* to_node, List** path) {
    int bfs_distance = 0;
    *path = List_create();
    
    // add distanation node to path    
    char** current_node = malloc( sizeof(char*) );
    *current_node = to_node;
    List_push_front_typed(*path, *current_node, char*);

    // move backwared and add other nodes to path
    while( strcmp(*current_node, from_node) != 0 ) {
        char** previous_node = Dict_get(from_to_node_names, *current_node);
        
        current_node = malloc( sizeof(char*) );
        *current_node = *previous_node;
        
        List_push_front_typed(*path, *current_node, char*);
        bfs_distance++;
    }

    return bfs_distance;
}


static int node_name_comparer(void* lhs, void* rhs){
    return strcmp( *( (char**)lhs ), *( (char**)rhs ));
}


static void debug_list_printer(void* value){
    printf("%s ", *( (char**)value ));
}


static void debug_dict_printer(void* node){
    Dict_node* dict_node = (Dict_node*) node;
    printf("%s -> %s, ", dict_node->key, *( (char**)(dict_node->value) ) );
}
