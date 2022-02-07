target_sources(
    "scp-game-framework-physics" PRIVATE
    
    "AxisAlignedBoxCollider.hpp"
    "pch.hpp"
)

target_precompile_headers("scp-game-framework-physics" PRIVATE "pch.hpp")