target_sources("basic-window-test" PRIVATE "basic-window-test.cpp")
target_include_directories("basic-window-test" PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_link_libraries("basic-window-test" "scp-game-framework-core")