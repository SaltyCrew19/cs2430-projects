cmake_minimum_required(VERSION 3.10.0)
project(SortingAlgorithms VERSION 0.1.0 LANGUAGES C CXX)

add_executable(SortingAlgorithms
    src/main.cpp
    src/algorithms/sorting.cpp
    src/algorithms/generator.cpp
)
target_include_directories(SortingAlgorithms PRIVATE src/include)

