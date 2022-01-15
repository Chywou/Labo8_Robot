cmake_minimum_required(VERSION 3.20)
project(Labo8_Robot)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labo8_Robot main.cpp Robot.cpp Robot.h Jeu.cpp Jeu.h Coordonnee.h Coordonnee.cpp)
