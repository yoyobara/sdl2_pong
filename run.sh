#!/bin/bash
set -e

# 1. Create build folder if it doesn't exist
mkdir -p build
cd build

# 2. Run CMake (generate build system & compile_commands.json)
cmake .. -DCMAKE_BUILD_TYPE=Debug

# 3. Build project
cmake --build .

# 4. Run executable
./sdl2_pong
