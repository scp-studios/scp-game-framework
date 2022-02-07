add_executable("axis-aligned-collision-test" "axis-aligned-collision-test.cpp")
target_link_libraries(
    "axis-aligned-collision-test"
    
    "scp-game-framework-core"
    "scp-game-framework-graphics"
    "scp-game-framework-physics"
    "scp-game-framework-utils"
)