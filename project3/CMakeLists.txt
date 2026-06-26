cmake_minimum_required(VERSION 3.10.0)
project(KnapsackOptimization VERSION 0.1.0 LANGUAGES C CXX)

add_executable(KnapsackOptimization
    src/main.cpp
    src/knapsack.cpp
    src/output/ConsoleOutput.cpp
)
target_include_directories(KnapsackOptimization PRIVATE src/include)
