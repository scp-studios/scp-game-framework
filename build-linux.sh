#!/bin/bash
printf "Starting automatic build process.\n"
printf "Searching for compilers..."

if [ -f "/usr/bin/clang" ]
then
    C_COMPILER="-DCMAKE_C_COMPILER=/usr/bin/clang"
    printf "\nFound Clang and selecting it as the main C compiler."
fi

if [ -f "/usr/bin/clang++" ]
then
    CXX_COMPILER="-DCMAKE_CXX_COMPILER=/usr/bin/clang++"
    printf "\nFound Clang++ and selecting it as the main C++ compiler."
fi

printf "\nBuilding dependencies..."
printf "\n\tGLFW... "
printf "Configuring... "
cmake -Sdependencies/glfw -Bdependencies/glfw/build $C_COMPILER $CXX_COMPILER -DCMAKE_BUILD_TYPE=Release -GNinja >> build.log 2>&1
printf "Compiling... "
ninja -C dependencies/glfw/build all >> build.log 2>&1
printf "Done!"

printf "\nConfiguring project..."
cmake -S. -Bbuild -GNinja $C_COMPILER $CXX_COMPILER -DCMAKE_BUILD_TYPE=Release >> build.log 2>&1

printf "\nCompiling project..."
ninja -C build all >> build.log 2>&1

printf "\n"