add_executable(test-opengl-graphics opengl-graphics-test.cpp)
target_link_libraries(
    test-opengl-graphics
    
    scp-game-framework-core
    scp-game-framework-graphics
    scp-game-framework-utils
)