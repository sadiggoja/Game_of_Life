cmake_minimum_required(VERSION 2.8.9)

project(Drawing)


set(CMAKE_BUILD_TYPE Release)



add_library(draw)

find_package(SDL2 CONFIG REQUIRED )

target_sources(draw PRIVATE game.c game.h sdl.h)
target_include_directories(draw INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(draw PUBLIC game)
target_link_libraries(draw PUBLIC SDL2::SDL2 SDL2::SDL2main)

#coverage

target_compile_options(draw PUBLIC "--coverage")
target_link_options(draw PUBLIC "--coverage")
