cmake_minimum_required(VERSION 3.10.0)
project(MonopolySimulation VERSION 0.1.0 LANGUAGES C CXX)

add_executable(MonopolySimulation
    src/main.cpp
    src/Board.cpp
    src/Deck.cpp
    src/Player.cpp
    src/Simulation.cpp
    src/Stats.cpp
    src/Console.cpp
)

target_include_directories(MonopolySimulation PRIVATE src/header)
target_include_directories(MonopolySimulation PRIVATE src/header/square)
