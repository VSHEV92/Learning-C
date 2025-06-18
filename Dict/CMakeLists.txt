cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME Dict)
project(${PROJECT_NAME} C)

set(LIST_DIR ${PROJECT_SOURCE_DIR}/../List)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${LIST_DIR}/src)

add_subdirectory(src)
add_subdirectory(tests)

add_subdirectory(${LIST_DIR} ${LIST_DIR}/build)

