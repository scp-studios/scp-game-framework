target_sources(
    scp-game-framework-core PRIVATE
    
    core-pch.hpp
    events.hpp
    Input.hpp
    math.hpp
    Scene.hpp
    Window.hpp
)

target_precompile_headers(scp-game-framework-core PRIVATE core-pch.hpp)

add_subdirectory(graphics)
add_subdirectory(math)
add_subdirectory(physics)
add_subdirectory(ui)
add_subdirectory(utils)