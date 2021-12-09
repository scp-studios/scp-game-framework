target_sources(
    scp-game-framework-core PRIVATE
    
    core-pch.hpp
    events.hpp
    Input.hpp
    Scene.hpp
    Window.hpp
)

target_precompile_headers(scp-game-framework-core PRIVATE core-pch.hpp)

add_subdirectory(graphics)