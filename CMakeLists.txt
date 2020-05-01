cmake_minimum_required(VERSION 2.8.9)
project (Gol)

add_subdirectory(Game)
add_subdirectory(Drawing)

add_executable(Gol main.c)

target_link_libraries(Gol PUBLIC game draw )
