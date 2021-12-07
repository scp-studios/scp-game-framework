cmake_minimum_required(VERSION 3.13)

project(scp-game-framework)

if (WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
else()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_CXX_STANDARD 17)

if (UNIX AND NOT APPLE)
    set(CMAKE_EXECUTABLE_SUFFIX .out)
endif()

option(BUILD_SHARED_LIBS "Whether or not to build DLLs/shared objects instead of static libraries" OFF)

if (MSVC)
    add_compile_options(/Wall)
else()
    # The project might have a hard time compiling on Intel's compiler.
    add_compile_options(-Wall -Wextra -pedantic)
endif()

find_package(GLFW)
find_package(OpenGL)

add_library(glad deps/GLAD/src/glad.c)

if (UNIX AND NOT APPLE)
    target_link_libraries(glad dl)
endif()

include_directories(${CMAKE_SOURCE_DIR}/include ${GLFW_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/deps/GLAD/include)

add_library(scp-game-framework-core)
add_library(scp-game-framework-graphics)

target_link_libraries(scp-game-framework-core GLFW::GLFW glad)

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(tests)