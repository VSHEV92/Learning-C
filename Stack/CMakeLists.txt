cmake_minimum_required(VERSION 3.28)
project(Stack C)

add_library(Stack STATIC Stack.c Stack.h)
add_subdirectory(tests)

