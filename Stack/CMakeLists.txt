cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME Stack)
project(${PROJECT_NAME} C)


set(HEADERS ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}.h)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(tests)

