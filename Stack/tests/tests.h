#ifndef TESTS_H
#define TESTS_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "Stack.h"


typedef void (*test_func_t)(void);

// tests
void stack_push_pop_int_test();
void stack_clean_int_test();

void stack_push_pop_string_test();
void stack_clean_string_test();
#endif
