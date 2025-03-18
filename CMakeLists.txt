cmake_minimum_required(VERSION 3.30)
project(Battleships C)

set(CMAKE_C_STANDARD 11)

add_executable(Battleships src/Main.c
        src/Grid.c
        src/header.h
        src/Ship.c
        src/Bot.c
        src/Game.c
        src/Player.c
        src/globals.h
        src/globals.c
        src/Display.c
)
