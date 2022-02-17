add_executable(test-event event-test.cpp)
target_link_libraries(test-event scp-game-framework-core)
define_test_symbols("test-event")