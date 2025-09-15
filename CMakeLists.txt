cmake_minimum_required(VERSION 3.16)
project(sdl2_pong)

# Enable C++17 (optional)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)

# Add executable
add_executable(sdl2_pong src/main.cpp)

# Link SDL2 libraries
target_link_libraries(sdl2_pong SDL2::SDL2 SDL2::SDL2main)
