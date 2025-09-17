cmake_minimum_required(VERSION 3.16)
project(sdl2_pong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(sdl2_pong ${SRC_FILES})

target_include_directories(sdl2_pong PRIVATE include)

find_package(SDL2 REQUIRED)
target_link_libraries(sdl2_pong SDL2::SDL2 SDL2::SDL2main)

