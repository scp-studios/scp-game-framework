add_executable(test-basic-window basic-window-test.cpp)
target_link_libraries(test-basic-window scp-game-framework-core)
define_test_symbols(test-basic-window)