cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME List)
project(${PROJECT_NAME} C)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(tests EXCLUDE_FROM_ALL)

