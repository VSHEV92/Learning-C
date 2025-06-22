cmake_minimum_required(VERSION 3.28)
project(Dict C)

add_subdirectory(src)
add_subdirectory(tests EXCLUDE_FROM_ALL)

set(LIST_DIR ${PROJECT_SOURCE_DIR}/../List)
add_subdirectory(${LIST_DIR} ${LIST_DIR}/build)

