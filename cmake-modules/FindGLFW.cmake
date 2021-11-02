find_path(
    GLFW_INCLUDE_DIR
    NAMES "GLFW/glfw3.h"
    PATHS "${CMAKE_SOURCE_DIR}/dependencies/glfw/include"
    DOC "Absolute Path to GLFW's include directory"
)

if (WIN32)
    if (MSVC)
        find_library(
            GLFW_LIBRARY
            NAMES "glfw3.lib" "glfw3dll.lib"
            PATHS "${CMAKE_SOURCE_DIR}/dependencies/glfw/build/Debug/src"
                  "${CMAKE_SOURCE_DIR}/dependencies/glfw/build/Release/src"
        )
    else()
        find_library(
            GLFW_LIBRARY
            NAMES "libglfw3.a" "libglfw3dll.a"
            PATHS "${CMAKE_SOURCE_DIR}/dependencies/glfw/build/src"
        )
    endif()
elseif(UNIX AND NOT APPLE)
    find_library(
        GLFW_LIBRARY
        NAMES "libglfw.so.3" "libglfw3.a" "libglfw.so"
        PATHS "${CMAKE_SOURCE_DIR}/dependencies/glfw/build/src"
              "/usr/lib/x86_64-linux-gnu"
    )
endif()

# Mark them as found
include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("GLFW" DEFAULT_MSG GLFW_LIBRARY GLFW_INCLUDE_DIR)