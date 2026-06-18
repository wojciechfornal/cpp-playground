cmake_minimum_required(VERSION 3.20)
project(GameOfLife VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL3 REQUIRED)
# /opt/homebrew/lib/cmake/SDL3/SDL3Config.cmake
# /opt/homebrew/share/SDL3/
# CMAKE_PREFIX_PATH
# etc.

add_executable(GameOfLife 
    src/main.cpp
    src/Game.cpp
    src/Grid.cpp
)

target_link_libraries(GameOfLife PRIVATE SDL3::SDL3)