cmake_minimum_required(VERSION "3.17.1")

project(GOL)

set(SOURCES cell.c game.c arena.c main.c)
set(HEADERS cell.h game.h arena.h)

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES} ${HEADERS})