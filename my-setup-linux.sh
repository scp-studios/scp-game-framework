cmake -S deps/glfw -B deps/glfw/build -G Ninja -D CMAKE_C_COMPILER=clang -D CMAKE_BUILD_TYPE=Debug -D CMAKE_CXX_COMPILER=clang++ -D GLFW_BUILD_TESTS=false -D GLFW_BUILD_EXAMPLES=false
cmake --build deps/glfw/build

cmake -S . -B build -G Ninja -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ -D CMAKE_BUILD_TYPE=Debug
cmake --build build