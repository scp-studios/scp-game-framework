add_executable(opengl-graphics-test opengl-graphics-test.cpp)
target_link_libraries(
    opengl-graphics-test
    
    scp-game-framework-core
    scp-game-framework-graphics
    scp-game-framework-utils
)