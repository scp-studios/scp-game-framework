add_executable(test-opengl-element-buffer opengl-element-buffer-test.cpp)
target_link_libraries(
    test-opengl-element-buffer
    
    scp-game-framework-core
    scp-game-framework-graphics
    scp-game-framework-utils
)
define_test_symbols("test-opengl-element-buffer")