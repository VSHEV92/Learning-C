add_library(${PROJECT_NAME} STATIC ${PROJECT_NAME}.c ${PROJECT_NAME}.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} PUBLIC List)

