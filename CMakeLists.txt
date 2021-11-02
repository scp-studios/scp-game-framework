cmake_minimum_required(VERSION "3.13")

project("scp-game-framework")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules")

if (UNIX)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
elseif(WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
endif()

if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-pedantic")
endif()

# GLFW
find_package("GLFW")

# GLAD
add_library("glad" "dependencies/glad/src/glad.c")
target_include_directories("glad" PRIVATE "dependencies/glad/include")

add_library("scp-game-framework-core")

target_include_directories("scp-game-framework-core" PRIVATE "${CMAKE_SOURCE_DIR}/include")

add_subdirectory("sources")
add_subdirectory("include")