target_sources("input-test" PRIVATE "input-test.cpp")
target_include_directories("input-test" PRIVATE "${CMAKE_SOURCE_DIR}/include" "${GLFW_INCLUDE_DIR}")
target_link_libraries("input-test" "scp-game-framework-core")