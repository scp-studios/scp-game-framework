target_sources(
    scp-game-framework-utils PRIVATE
    
    file-utils.hpp
    pch.hpp
)

target_precompile_headers(scp-game-framework-utils PRIVATE pch.hpp)