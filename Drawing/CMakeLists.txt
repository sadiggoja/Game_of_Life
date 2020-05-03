cmake_minimum_required(VERSION 2.8.9)

project(Drawing)

set(CMAKE_BUILD_TYPE Release)



add_library(draw)


target_sources(draw PRIVATE game.c game.h)
target_include_directories(draw INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(draw PUBLIC game)

#coverage

target_compile_options(draw PUBLIC "--coverage")
target_link_options(draw PUBLIC "--coverage")
