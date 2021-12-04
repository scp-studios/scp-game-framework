cmake_minimum_required(VERSION 3.13)

project(scp-game-framework)

if (WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
else()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Whether or not to build DLLs/shared objects instead of static libraries" ON)

if (MSVC)
    add_compile_options(/Wall)
else()
    # The project might have a hard time compiling on Intel's compiler.
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# I'll add these later
#find_package(GLFW)
#find_package(OpenGL)

add_library(scp-game-framework-core)

add_subdirectory(src)
add_subdirectory(tests)