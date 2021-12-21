add_executable(opengl-element-buffer-test opengl-element-buffer-test.cpp)
target_link_libraries(
    opengl-element-buffer-test
    
    scp-game-framework-core
    scp-game-framework-graphics
    scp-game-framework-utils
)