#!/bin/bash
cmake -S deps/glfw -B deps/glfw/build -D GLFW_BUILD_TESTS=false -D GLFW_BUILD_EXAMPLES=false
cmake --build deps/glfw/build

cmake -S . -B build
cmake --build build