cmake_minimum_required(VERSION 3.28)
project(Breadth_First_Search C)

add_subdirectory(src)
add_subdirectory(tests EXCLUDE_FROM_ALL)

set(GRAPH_DIR ${PROJECT_SOURCE_DIR}/../Graph)
add_subdirectory(${GRAPH_DIR} ${GRAPH_DIR}/build)

