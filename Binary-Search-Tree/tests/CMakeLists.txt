enable_testing()

file(GLOB TESTS_SRCs "*.c")
foreach( test_src ${TESTS_SRCs} )
    get_filename_component( test_name ${test_src} NAME_WE )
    add_executable(${test_name} ${test_src} tests.h)
    target_link_libraries(${test_name} ${PROJECT_NAME})
    add_test( NAME ${test_name} COMMAND ./${test_name} )
endforeach()



