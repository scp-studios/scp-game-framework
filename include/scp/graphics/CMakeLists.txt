target_sources(
    scp-game-framework-graphics PRIVATE
    
    API.hpp
    opengl.hpp
    pch.hpp
    VertexLayout.hpp
)

target_precompile_headers(scp-game-framework-graphics PRIVATE pch.hpp)

add_subdirectory(opengl)