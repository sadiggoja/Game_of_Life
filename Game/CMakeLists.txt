cmake_minimum_required(VERSION 2.8.9)

project(Game)


set(CMAKE_BUILD_TYPE Release)



add_library(game )

target_sources(game PRIVATE cell.c cell.h arena.c arena.h)
target_include_directories(game INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
 


#coverage

target_compile_options(game PUBLIC "--coverage")
target_link_options(game PUBLIC "--coverage")
