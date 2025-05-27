#include "List.h"


List* List_create() {
    List* list = malloc( sizeof(List) );
    
    if (list == NULL) {
        LIST_MALLOC_ERR;
    }

    list->size = 0;
    list->printer = NULL;
    list->head = NULL;
    list->tail = NULL;

    return list;
}


void List_clean(List* list) {
    while ( List_get_size(list) > 0) {
        List_pop_front(list);
    } 
}


void List_delete(List* list) {
    List_clean(list);
    free(list);
}


void List_push_front(List* list, void* value) {
    List_node* node = malloc( sizeof(List_node) );

    if (node == NULL) {
        LIST_MALLOC_ERR;
    }

    node->value = value;
    node->next = list->head;
    node->prev = NULL;
    
    list->head = node;
    list->size++;
}


void* List_pop_front(List* list) {

    if (list->size == 0) {
        LIST_POP_ERR;
    }

    void* value = list->head->value;
    
    List_node* to_remove = list->head;

    // If it is not last node set new head and change pointer 
    // to previous node. 
    // Else simply set head to NULL
    if (list->size != 1) { 
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    else {
        list->head = NULL;
    }
    
    list->size--;
    
    free(to_remove);

    return value;
}


void List_push_back(List* list, void* value) {
    List_node* node = malloc( sizeof(List_node) );

    if (node == NULL) {
        LIST_MALLOC_ERR;
    }

    node->value = value;
    node->next = NULL;
    node->prev = list->tail;
    
    list->tail = node;
    list->size++;
}


void* List_pop_back(List* list) {

    if (list->size == 0) {
        LIST_POP_ERR;
    }

    void* value = list->tail->value;
    
    List_node* to_remove = list->tail;

    // If it is not last node set new tail and change pointer 
    // to previous node. 
    // Else simply set tail to NULL
    if (list->size != 1) { 
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    else {
        list->tail = NULL;
    }
    
    list->size--;
    
    free(to_remove);

    return value;
}


size_t List_get_size(List* list) {
    return list->size;
}


void List_set_printer(List* List, List_printer printer) {

}


void List_print(List* list) {

}
