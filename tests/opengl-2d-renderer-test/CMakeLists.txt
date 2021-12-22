add_executable(opengl-2d-renderer-test opengl-2d-renderer-test.cpp)
target_link_libraries(
    opengl-2d-renderer-test
    
    scp-game-framework-core
    scp-game-framework-graphics
    scp-game-framework-utils
)