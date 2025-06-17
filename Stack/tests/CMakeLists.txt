project(Stack_tests C)
enable_testing()

file(GLOB test_src "*.h" "*.c")

add_executable(StackTests ${test_src} ../Stack.h)

target_include_directories(StackTests PUBLIC ${PROJECT_SOURCE_DIR}/..)
target_link_libraries(StackTests PUBLIC Stack)

add_test(
    NAME StackTests
    COMMAND ./StackTests
)
