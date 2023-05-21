cmake_minimum_required(VERSION 3.25)
project(GameSample)

set(CMAKE_CXX_STANDARD 14)

include_directories(GameSample)

add_executable(GameSample
        GameSample/BaseGrid.cpp
        GameSample/BaseGrid.h
        GameSample/Controls.cpp
        GameSample/Controls.h
        GameSample/Engine.cpp
        GameSample/FruitGenerator.cpp
        GameSample/FruitGenerator.h
        GameSample/Fruits.cpp
        GameSample/Fruits.h
        GameSample/GameBase.cpp
        GameSample/GameBase.h
        GameSample/Snake.cpp
        GameSample/Snake.h
        GameSample/SnakeTheGame.cpp
        GameSample/SnakeTheGame.h
        GameSample/SnakeView.cpp
        GameSample/SnakeView.h
        GameSample/View.cpp
        GameSample/View.h)
