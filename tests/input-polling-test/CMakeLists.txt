add_executable(test-input-polling input-polling-test.cpp)
target_link_libraries(test-input-polling scp-game-framework-core)
define_test_symbols("test-input-polling")