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

if (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    add_compile_options(-fdiagnostics-absolute-paths)
    add_link_options(-fdiagnostics-absolute-paths)
endif()

find_package(GLFW)
find_package(OpenGL)

add_library(glad deps/glad/src/glad.c)
target_compile_definitions(glad PRIVATE GLAD_GLAPI_EXPORT_BUILD GLAD_GLAPI_EXPORT)

if (UNIX AND NOT APPLE)
    target_link_libraries(glad dl)
endif()

include_directories(
    ${CMAKE_SOURCE_DIR}/include 
    ${GLFW_INCLUDE_DIR} 
    ${CMAKE_SOURCE_DIR}/deps/glad/include
    ${CMAKE_SOURCE_DIR}/deps/stb
)

# For defining the windows export symbols
function("define_symbols" "target")
    if (WIN32 AND BUILD_SHARED_LIBS)
        target_compile_definitions(
            "${target}" PRIVATE 
            
            "SCP_BUILD_WINDOWS_DLL"
            "GLAD_GLAPI_EXPORT"
        )
    endif()
endfunction()

function("define_test_symbols" "target")
    if (WIN32 AND BUILD_SHARED_LIBS)
        target_compile_definitions(
            "${target}" PRIVATE 
            
            "SCP_LINK_WINDOWS_DLL"
            "GLAD_GLAPI_EXPORT"
        )
    endif()
endfunction()

add_library(scp-game-framework-core)
add_library(scp-game-framework-graphics)
add_library(scp-game-framework-utils)
add_library(scp-game-framework-math)
add_library(scp-game-framework-physics)
add_library(scp-game-framework-ui)

add_library("stb" STATIC)

define_symbols(scp-game-framework-core)
define_symbols(scp-game-framework-graphics)
define_symbols(scp-game-framework-utils)
define_symbols(scp-game-framework-math)
define_symbols(scp-game-framework-physics)
define_symbols(scp-game-framework-ui)

target_link_libraries(scp-game-framework-core GLFW::GLFW glad)
target_link_libraries(scp-game-framework-graphics glad stb scp-game-framework-utils scp-game-framework-core)
target_link_libraries("scp-game-framework-utils" "GLFW::GLFW")
target_link_libraries(scp-game-framework-ui scp-game-framework-core)

if (UNIX)
    # Unix stuff
    target_link_libraries(scp-game-framework-core pthread)
elseif(WIN32)
    # WIN32 related stuff
endif()

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(tests)