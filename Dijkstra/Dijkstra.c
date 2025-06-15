#include "Dijkstra.h"


static int node_name_comparer(void* lhs, void* rhs);
static void debug_list_printer(void* value);
static void debug_dict_printer(void* node);
static void debug_distance_printer(void* node);

static void dijkstra_set_distance(Dict* distances_dict, char* node_name, int distance);
static char** dijkstra_get_next_node(Dict* distances_dict, List* processed_nodes);
static void dijkstra_create_path(Dict* from_to_node_names, char* from_node, char* to_node, List** path);


int Dijkstra (Graph* graph, char* from_node, char* to_node, List** path) {

    List* nodes_already_processed = List_create();
    List_set_comparer(nodes_already_processed, node_name_comparer);
    List_set_printer(nodes_already_processed, debug_list_printer);

    // Dictionary that collect Dijkstra algorithm distances
    Dict* distances_dict = Dict_create(BFS_DICT_MAX_HASH_SIZE);
    Dict_set_printer(distances_dict, debug_distance_printer);

    // Disctionary that collect from/to node names relationships.
    // Used to create BFS path.
    Dict* from_to_node_names = Dict_create(BFS_DICT_MAX_HASH_SIZE);
    Dict_set_printer(from_to_node_names, debug_dict_printer);

    // distanation node is reached
    bool to_node_reached = false;

    // add start node to dictionary of distances and process it
    dijkstra_set_distance(distances_dict, from_node, 0);
    char** processed_node = dijkstra_get_next_node(distances_dict, nodes_already_processed);
    
    // node process loop
    while ( *processed_node != NULL ) {

        // get current distance and set node as processed
        int current_distance = Dict_get_typed(distances_dict, *processed_node, int);
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
            int new_distance = current_distance + Graph_get_distance(graph, *processed_node, *sibling_name);

            if ( !Dict_key_exist(distances_dict, *sibling_name) ) {
                dijkstra_set_distance(distances_dict, *sibling_name, new_distance);
                Dict_set_typed(from_to_node_names, *sibling_name, *processed_node, char*);
            } 
            else {
                int old_distance = Dict_get_typed(distances_dict, *sibling_name, int);
                if (old_distance > new_distance) {
                    dijkstra_set_distance(distances_dict, *sibling_name, new_distance);
                    Dict_set_typed(from_to_node_names, *sibling_name, *processed_node, char*);
                }
            }

        }

        Dict_print(from_to_node_names);
        puts("");
        List_delete(siblings);
        processed_node = dijkstra_get_next_node(distances_dict, nodes_already_processed);
        
    }

    // find path and calculate distance
    int distance;
    if (!to_node_reached) {
        *path = NULL;
        distance = -1;
    }
    else {
        dijkstra_create_path(from_to_node_names, from_node, to_node, path);
        distance = Dict_get_typed(distances_dict, to_node, int);
    }

    // clean up
    List_delete(nodes_already_processed);
    Dict_delete(from_to_node_names);

    return distance;
}


void dijkstra_delete_path(List** path) {
    size_t path_size = List_get_size(*path);
    for (int i = 0; i < path_size; i++) {
        char** node_name = List_pop_front(*path);
        free(node_name);
    }
    List_delete(*path);
}


static void dijkstra_set_distance(Dict* distances_dict, char* node_name, int distance) {
    int* distance_ptr;

    if ( Dict_key_exist(distances_dict, node_name) ) {
        distance_ptr = Dict_get(distances_dict, node_name);
    }
    else {
        distance_ptr = malloc( sizeof(int) );
    }

    *distance_ptr = distance;
    Dict_set(distances_dict, node_name, distance_ptr);
}


static char** dijkstra_get_next_node(Dict* distances_dict, List* processed_nodes) {
    List* nodes = Dict_get_keys(distances_dict);
    size_t nodes_number = List_get_size(nodes);

    int min_distance;
    char** next_node = malloc( sizeof(char*) );
    *next_node = NULL;

    for (size_t i = 0; i < nodes_number; i++) {
        char* node_name = List_pop_front_typed(nodes, char*);

        bool is_already_processed = List_value_exists_typed(processed_nodes, node_name, char*);
        if (is_already_processed) {
            continue;
        }

        int distance = Dict_get_typed(distances_dict, node_name, int);

        if (min_distance > distance || *next_node == NULL) {
            min_distance = distance;
            *next_node = node_name;
        }
    }
    return next_node;
}

// halper function, used to create path from start to destination node and calculate distance
// we need to use malloc, so that pointer not destroyed after function return 
static void dijkstra_create_path(Dict* from_to_node_names, char* from_node, char* to_node, List** path) {
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
    }
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


static void debug_distance_printer(void* node){
    Dict_node* dict_node = (Dict_node*) node;
    printf("%s -> %d, ", dict_node->key, *( (int*)(dict_node->value) ) );
}
