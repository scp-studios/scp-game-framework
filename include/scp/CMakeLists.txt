target_sources(
    scp-game-framework-core PRIVATE
    
    core-pch.hpp
    dummy-header.hpp
    Scene.hpp
    Window.hpp
)

target_precompile_headers(scp-game-framework-core PRIVATE core-pch.hpp)

add_subdirectory(graphics)