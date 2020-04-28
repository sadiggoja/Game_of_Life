cmake_minimum_required(VERSION 3.17.1)
project (Drawing)

set(CMAKE_BUILD_TYPE Release)

set ( PROJECT_LINK_LIBS libgame.so )
link_directories(/home/djeks/Desktop/Game_of_Life/Game/build)

include_directories(include)
 

file(GLOB SOURCES "src/*.c")

include_directories(/home/djeks/Desktop/Game_of_Life/Game/include)

add_library(draw SHARED ${SOURCES})
 

install(TARGETS draw DESTINATION /usr/lib)