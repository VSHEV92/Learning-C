#ifndef TESTS_H
#define TESTS_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <Dict.h>


typedef void (*test_func_t)(void);

// tests
void dict_set_get_int_test();

#endif
