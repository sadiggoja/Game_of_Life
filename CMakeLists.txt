cmake_minimum_required(VERSION 2.8.9)
project (Gol)


set ( PROJECT_LINK_LIBS libdraw.so libgame.so )

link_directories( /home/djeks/Desktop/Game_of_Life/Drawing/build)
link_directories( /home/djeks/Desktop/Game_of_Life/Game/build)



include_directories(/home/djeks/Desktop/Game_of_Life/Drawing/include)
include_directories(/home/djeks/Desktop/Game_of_Life/Game/include)

add_executable(Gol main.c)
target_link_libraries(Gol ${PROJECT_LINK_LIBS} )