target_sources(
    scp-game-framework-utils PRIVATE
    
    "AssetCollection.hpp"
    file-utils.hpp
    pch.hpp
    string_utils.hpp
    "time-utils.hpp"
)

target_precompile_headers(scp-game-framework-utils PRIVATE pch.hpp)