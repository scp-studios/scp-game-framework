add_executable(test-opengl-debug opengl-debug-test.cpp)
target_link_libraries(
    test-opengl-debug
    scp-game-framework-core
    scp-game-framework-graphics
)
define_test_symbols("test-opengl-debug")