cmake_minimum_required(VERSION 3.28)
project(textadventure)

set(CMAKE_CXX_STANDARD 17)

add_executable(textadventure main.cpp
        room.cpp
        room.h
        item.cpp
        item.h
        character.cpp
        character.h
        player.cpp
        player.h
        area.cpp
        area.h
        command_interpreter.cpp
        command_interpreter.h
        inventory.cpp
        inventory.h)
