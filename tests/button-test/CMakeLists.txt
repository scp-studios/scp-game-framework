add_executable("test-button" "button-test.cpp")
target_link_libraries(
    "test-button" 
    
    "scp-game-framework-core" 
    "scp-game-framework-graphics" 
    "scp-game-framework-ui"
    "scp-game-framework-utils"
)
define_test_symbols("test-button")
