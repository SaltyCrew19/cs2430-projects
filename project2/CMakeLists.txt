cmake_minimum_required(VERSION 3.10.0)
project(SetsAndMultisets VERSION 0.1.0 LANGUAGES C CXX)

add_executable(SetsAndMultisets 
    src/main.cpp
    src/sets/multisetOps.cpp
    src/sets/setOps.cpp
    src/output/ConsoleOutput.cpp
    )

target_include_directories(SetsAndMultisets PRIVATE src/include)