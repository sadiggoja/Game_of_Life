cmake_minimum_required(VERSION 3.17.1)

project(Game)
set(CMAKE_BUILD_TYPE Release)
 

include_directories(include)
 

file(GLOB SOURCES "src/*.c")
 

add_library(game SHARED ${SOURCES})
 

install(TARGETS game DESTINATION /usr/lib)