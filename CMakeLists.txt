cmake_minimum_required(VERSION 3.30)
project(Battleships C)

set(CMAKE_C_STANDARD 11)

add_executable(Battleships main.c
        Grid.c
        header.h
        ship.c
        Bot.c
        Game.c
        Player.c
)
