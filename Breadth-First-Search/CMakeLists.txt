cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME Breadth-First-Search)
project(${PROJECT_NAME} C)

set(LIST_DIR ${PROJECT_SOURCE_DIR}/../List)
set(DICT_DIR ${PROJECT_SOURCE_DIR}/../Dict)
set(GRAPH_DIR ${PROJECT_SOURCE_DIR}/../Graph)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${DICT_DIR}/src)
include_directories(${LIST_DIR}/src)
include_directories(${GRAPH_DIR}/src)

add_subdirectory(src)
add_subdirectory(tests EXCLUDE_FROM_ALL)

add_subdirectory(${GRAPH_DIR} ${GRAPH_DIR}/build)

