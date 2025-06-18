add_library(${PROJECT_NAME} STATIC ${PROJECT_NAME}.c ${PROJECT_NAME}.h)
target_link_libraries(${PROJECT_NAME} PUBLIC Dict)

