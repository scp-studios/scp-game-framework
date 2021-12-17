target_sources(
    scp-game-framework-utils PRIVATE
    
    file-utils.hpp
    pch.hpp
    string_utils.hpp
)

target_precompile_headers(scp-game-framework-utils PRIVATE pch.hpp)