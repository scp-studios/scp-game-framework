target_sources(
    scp-game-framework-utils PRIVATE
    
    "AssetCollection.cpp"
    file-utils.cpp
    string_utils.cpp
    "time-utils.cpp"
)

target_sources(
    "stb" PRIVATE
    
    "stb_image.c"
)