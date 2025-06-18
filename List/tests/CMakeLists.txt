
file(GLOB TESTS_SRCs "*.c")

enable_testing()

foreach( test_src ${TESTS_SRCs} )
    get_filename_component( test_name ${test_src} NAME_WE )
    add_executable(${test_name} ${test_src} ${HEADERS} tests.h)
    target_link_libraries(${test_name} PUBLIC ${PROJECT_NAME})
    add_test( NAME ${test_name} COMMAND ./${test_name} )
endforeach( test_src ${TESTS_SRCs} )



