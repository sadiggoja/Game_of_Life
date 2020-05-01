cmake_minimum_required(VERSION 2.8.9)

project(Game)
cmake_policy(SET CMP0076 NEW)
set(CMAKE_BUILD_TYPE Release)

add_library(game )

target_sources(game PRIVATE cell.c cell.h arena.c arena.h)

target_include_directories(game INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
 
target_link_libraries(game INTERFACE m)
