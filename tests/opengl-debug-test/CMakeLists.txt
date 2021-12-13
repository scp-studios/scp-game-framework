add_executable(opengl-debug-test opengl-debug-test.cpp)
target_link_libraries(
    opengl-debug-test
    scp-game-framework-core
    scp-game-framework-graphics
)