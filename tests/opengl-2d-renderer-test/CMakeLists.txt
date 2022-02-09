add_executable(test-opengl-2d-renderer opengl-2d-renderer-test.cpp)
target_link_libraries(
    test-opengl-2d-renderer
    
    scp-game-framework-core
    scp-game-framework-graphics
    scp-game-framework-utils
)