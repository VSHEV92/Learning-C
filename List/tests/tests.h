#ifndef TESTS_H
#define TESTS_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "List.h"


typedef void (*test_func_t)(void);

// tests
void list_push_pop_front_int_test();
void list_push_pop_back_int_test();
void list_push_back_pop_front_int_test();

void list_push_back_clean_int_test();
void list_push_front_clean_int_test();

void list_push_front_get_by_index_int_test();
void list_push_front_set_by_index_int_test();
void list_push_front_get_by_value_int_test();

void list_push_pop_front_string_test();
void list_push_pop_back_string_test();
void list_push_back_pop_front_string_test();

void list_push_back_clean_string_test();
void list_push_front_clean_string_test();

void list_push_front_get_by_index_string_test();
void list_push_front_set_by_index_string_test();
void list_push_front_set_by_index_string_test();
void list_push_front_get_by_value_string_test();

void list_push_front_delete_head_by_index_int_test();
void list_push_front_delete_tail_by_index_int_test();
void list_push_front_delete_middle_by_index_int_test();

#endif
