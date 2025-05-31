#include "List.h"


List* List_create() {
    List* list = malloc( sizeof(List) );
    
    if (list == NULL) {
        LIST_MALLOC_ERR;
    }

    list->size = 0;
    list->printer = NULL;
    list->comparer = NULL;
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

    if (list->size == 0){
        node->next = NULL;
        node->prev = NULL;
        list->head = node;
        list->tail = node;
    }
    else {
        node->next = list->head;
        node->prev = NULL;
        list->head->prev = node;
        list->head = node;
    }

    list->size++;
}


void* List_pop_front(List* list) {

    if (list->size == 0) {
        LIST_POP_ERR;
    }

    List_node* to_remove = list->head;

    void* value = list->head->value;
    
    if (list->size == 1) { 
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->head = list->head->next;
        list->head->prev = NULL;
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

    if (list->size == 0){
        node->next = NULL;
        node->prev = NULL;
        list->head = node;
        list->tail = node;
    }
    else {
        node->prev = list->tail;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;
}


void* List_pop_back(List* list) {

    if (list->size == 0) {
        LIST_POP_ERR;
    }

    List_node* to_remove = list->tail;

    void* value = list->tail->value;
    
    if (list->size == 1) { 
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    
    list->size--;
    
    free(to_remove);

    return value;
}


size_t List_get_size(List* list) {
    return list->size;
}


void* List_get_value_by_index(List* list, size_t index) {
    if (index >= list->size){
        LIST_INDEX_ERR;
    }

    List_node* node = list->head;

    for (size_t i = 0; i < index; i++) {
        node = node->next;
    }
    return node->value;
}


void List_set_value_by_index(List* list, size_t index, void* value) {
    if (index >= list->size){
        LIST_INDEX_ERR;
    }

    List_node* node = list->head;

    for (size_t i = 0; i < index; i++) {
        node = node->next;
    }

    node->value = value;
}


ssize_t List_get_index_by_value(List* list, void* value) {
    if (list->comparer == NULL){
        LIST_COMPARER_ERR;
    }

    List_comparer comparer = (List_comparer)list->comparer;
    List_node* node = list->head;

    for (size_t i = 0; i < list->size; i++) {
        int result = comparer(node->value, value);
        if (result == 0) {
            return i;
        }
        node = node->next;
    }

    return -1;
}


void List_set_printer(List* list, List_printer printer) {
    list->printer = printer;
}


void List_print(List* list) {
    if (list->printer == NULL){
        LIST_PRINTER_ERR;
    }

    List_printer printer = (List_printer)list->printer;

    for (size_t i = 0; i < list->size; i++) {
        void* value = List_get_value_by_index(list, i);
        printer(value);
    }
}


void List_set_comparer(List* list, List_comparer comparer) {
    list->comparer = comparer;
}
