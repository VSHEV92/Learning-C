cmake_minimum_required(VERSION 3.28)
project(Graph C)

add_subdirectory(src)
add_subdirectory(tests EXCLUDE_FROM_ALL)

set(DICT_DIR ${PROJECT_SOURCE_DIR}/../Dict)
add_subdirectory(${DICT_DIR} ${DICT_DIR}/build)

