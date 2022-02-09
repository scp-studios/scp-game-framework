add_executable(test-opengl-math opengl-math-test.cpp)
target_link_libraries(
    test-opengl-math
    
    scp-game-framework-core
    scp-game-framework-graphics
)