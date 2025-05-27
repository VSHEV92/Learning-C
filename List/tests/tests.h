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

#endif
