#include "Breadth_First_Search.h"


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

    // BFS distance
    int bfs_distance = -1;

    // distanation node is reached
    bool to_node_reached = false;

    // add start node to need to process list
    List_push_back_typed(nodes_needed_to_process, from_node, char*);

//    int cnt = 0;


    // node process loop
    while ( List_get_size(nodes_needed_to_process) > 0 ) {
    
 //       if (cnt > 10) {
 //           break;
 //       }
 //       cnt++;

 //       puts("Need to process: ");
 //       List_print(nodes_needed_to_process);
 //       puts("");

 //       puts("Already processed: ");
 //       List_print(nodes_already_processed);
 //       puts("");
        
        // get next node name and set it as processed
        char** processed_node = List_pop_front(nodes_needed_to_process);
        List_push_back_typed(nodes_already_processed, *processed_node, char*);

        // distanation node is found
        if ( strcmp(to_node, *processed_node) == 0 ){
            to_node_reached = true;
            break;
        }

        // add siblings nodes to need to process list
        Graph_node* graph_node = Graph_get_node(graph, *processed_node);
        List* siblings = Graph_node_get_siblings(graph_node);
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

    // prepare output results
    if (to_node_reached) {
        *path = List_create();

        // move back through from/to dictionary to construct bfs path and count distance
        char** path_node = malloc( sizeof(char*) );
        *path_node = to_node;

        char** current_node = &to_node;
        List_push_front_typed(*path, *path_node, char*);

        bfs_distance = 0;
        while( strcmp(*current_node, from_node) != 0 ) {
            current_node = Dict_get(from_to_node_names, *current_node);
            
            char** path_node = malloc( sizeof(char*) );
            *path_node = *current_node;
            
            List_push_front_typed(*path, *path_node, char*);
            bfs_distance++;
        }

        return bfs_distance;
    }
    else {
        *path = NULL;
        return bfs_distance;
    }
    
    return -1;
}
