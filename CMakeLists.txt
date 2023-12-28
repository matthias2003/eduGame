cmake_minimum_required(VERSION 3.27)
project(GameEdu)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameEdu main.cpp
        character.h
        character.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static")