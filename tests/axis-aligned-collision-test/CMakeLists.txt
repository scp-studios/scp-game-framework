add_executable("test-axis-aligned-collision" "axis-aligned-collision-test.cpp")
target_link_libraries(
    "test-axis-aligned-collision"
    
    "scp-game-framework-core"
    "scp-game-framework-graphics"
    "scp-game-framework-physics"
    "scp-game-framework-utils"
)
define_test_symbols("test-axis-aligned-collision")