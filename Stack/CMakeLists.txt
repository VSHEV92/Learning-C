cmake_minimum_required(VERSION 3.28)
project(Stack C)

set(PROJECT_NAME Stack)

set(HEADERS ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}.h)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(tests)

