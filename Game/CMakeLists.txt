cmake_minimum_required(VERSION 3.17.1)

project(Game)
set(CMAKE_BUILD_TYPE Release)


add_library(game )

target_sources(game PRIVATE cell.c cell.h arena.c arena.h)

target_include_directories(game INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
 
target_link_libraries(game INTERFACE m)

