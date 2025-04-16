cmake_minimum_required(VERSION 3.23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#this needs to be set before the project is built and files are linked etc.

project(game)

add_executable(game src/main.cpp src/game.cpp src/texmanager.cpp src/gameObject.cpp src/map.cpp)

#these commands allow the lsp to use autofill for external frameworks
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_IMAGE CONFIG REQUIRED)
find_package(SDL2_MIXER CONFIG REQUIRED)

target_link_libraries(game PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer)
