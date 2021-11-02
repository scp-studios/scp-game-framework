cmake_minimum_required(VERSION "3.13")

project("scp-game-framework")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules")
set(CMAKE_CXX_STANDARD 17)

if (UNIX)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
    if (NOT APPLE)
        set(CMAKE_EXECUTABLE_SUFFIX ".out")
    endif()
elseif(WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
endif()

if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-pedantic")
endif()

# Libraries
find_package("GLFW")
find_package("OpenGL")

# GLAD
add_library("glad" "dependencies/glad/src/glad.c")
target_include_directories("glad" PRIVATE "dependencies/glad/include")
if (UNIX)
    target_link_libraries("glad" "dl")
endif()

add_library("scp-game-framework-core")

target_include_directories(
    "scp-game-framework-core" PRIVATE 
    "${CMAKE_SOURCE_DIR}/include"
    "${GLFW_INCLUDE_DIR}"
    "dependencies/glad/include"
)

target_link_libraries(
    "scp-game-framework-core" PRIVATE
    "${GLFW_LIBRARY}"
    "glad"
)

add_subdirectory("sources")
add_subdirectory("include")
add_subdirectory("tests")