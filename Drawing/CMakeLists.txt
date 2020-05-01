cmake_minimum_required(VERSION 3.17.1)

project(Drawing)
set(CMAKE_BUILD_TYPE Release)



add_library(draw)


target_sources(draw PRIVATE game.c game.h)

target_include_directories(draw INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
 
target_link_libraries(draw INTERFACE m)
target_link_libraries(draw PUBLIC game)
