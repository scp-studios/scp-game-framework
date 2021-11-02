target_sources(
    "scp-game-framework-core" PRIVATE
    
    "hello.cpp"
    "pch.hpp"
)

target_precompile_headers("scp-game-framework-core" PRIVATE "pch.hpp")