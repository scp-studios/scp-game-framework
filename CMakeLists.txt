cmake_minimum_required(VERSION "3.13")

project("scp-game-framework")

if (UNIX)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
elseif(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
endif()

if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-pedantic")
endif()

# GLAD
add_library("glad" "dependencies/glad/src/glad.c")
target_include_directories("glad" PRIVATE "dependencies/glad/include")

add_library("scp-game-framework-core")

target_include_directories("scp-game-framework-core" PRIVATE "${CMAKE_SOURCE_DIR}/includes")

add_subdirectory("sources")