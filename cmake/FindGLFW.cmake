# Locate the include directory
find_path(
    GLFW_INCLUDE_DIR
    NAMES GLFW/glfw3.h
    PATHS ${CMAKE_SOURCE_DIR}/deps/glfw/include
    DOC "Path to the directory containing GLFW's headers."
)

# Locate the binaries
if (WIN32)
    if (MSVC)
        find_library(
            GLFW_LIBRARY
            NAMES glfw3.lib glfw3dll.lib
            PATHS ${CMAKE_SOURCE_DIR}/deps/glfw/build/src/Debug
                  ${CMAKE_SOURCE_DIR}/deps/glfw/build/src/Release
        )
    else()
        find_library(
            GLFW_LIBRARY
            NAMES libglfw3.a libglfw3dll.a
            PATHS ${CMAKE_SOURCE_DIR}/deps/glfw/build/src
                  ${CMAKE_SOURCE_DIR}/deps/glfw/build/src
        )
    endif()
else()
    if (APPLE)
        find_library(
            GLFW_LIBRARY
            NAMES libglfw3.a libglfw.3.dylib
            PATHS ${CMAKE_SOURCE_DIR}/deps/glfw/build/src
                  ${CMAKE_SOURCE_DIR}/deps/glfw/build/src
                  /usr/lib/x86_64-linux-gnu
        )
    else()
        find_library(
            GLFW_LIBRARY
            NAMES libglfw.so.3 libglfw3.a
            PATHS /usr/lib/x86_64-linux-gnu
                  ${CMAKE_SOURCE_DIR}/deps/glfw/build/src
                  ${CMAKE_SOURCE_DIR}/deps/glfw/build/src
        )
    endif()
endif()

# Find the type of the library and add it as an imported target
if (WIN32)
    if (MSVC)
        if (GLFW_LIBRARY MATCHES ".*dll.lib$")
            add_library(GLFW::GLFW SHARED IMPORTED)
        else()
            add_library(GLFW::GLFW STATIC IMPORTED)
        endif()
    else()
        if (GLFW_LIBRARY MATCHES ".*dll.a$")
            add_library(GLFW::GLFW SHARED IMPORTED)
        else()
            add_library(GLFW::GLFW STATIC IMPORTED)
        endif()
    endif()
else()
    if (APPLE)
        if (GLFW_LIBRARY MATCHES ".*.dylib$")
            add_library(GLFW::GLFW SHARED IMPORTED)
        else()
            add_library(GLFW::GLFW STATIC IMPORTED)
        endif()
    else()
        if (GLFW_LIBRARY MATCHES ".*.so$")
            add_library(GLFW::GLFW SHARED IMPORTED)
        else()
            add_library(GLFW::GLFW STATIC IMPORTED)
        endif()
    endif()
endif()

set_property(TARGET GLFW::GLFW PROPERTY IMPORTED_LOCATION ${GLFW_LIBRARY})

# Mark the package as found
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GLFW DEFAULT_MSG GLFW_LIBRARY GLFW_INCLUDE_DIR)