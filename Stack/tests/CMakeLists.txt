
file(GLOB STACK_TESTS "*.c")

enable_testing()

foreach( test_src ${STACK_TESTS} )
    get_filename_component( test_name ${test_src} NAME_WE )
    add_executable(${test_name} ${test_src} ${PROJECT_SOURCE_DIR}/src/Stack.h tests.h)
    target_include_directories(${test_name} PUBLIC ${PROJECT_SOURCE_DIR}/src)
    target_link_libraries(${test_name} PUBLIC Stack)
    add_test( NAME ${test_name} COMMAND ./${test_name} )
endforeach( test_src ${STACK_TESTS} )



