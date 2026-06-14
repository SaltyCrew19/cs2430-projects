# Project 1 - Sorting Algorithms
**CS 2430 | Connor | Summer 2026**

## Description
This project implements and compares four sorting algorithms in C++:
- Merge Sort
- Quick Sort
- Heap Sort
- Shaker Sort

Each algorithm tracks the number of comparisons made during sorting.
Results are displayed in a table showing min, max, and average comparisons
over 10 runs for array sizes n = 4, 6, and 8.

## Language
C++ (C++17)

## Build Instructions
From the `/project1` directory:
```bash
cmake -S . -B build
cmake --build build
```

## Run Instructions
```bash
.\build\SortingAlgorithms.exe
```

## File Structure
```
project1/
├── src/
│   ├── main.cpp                 - test driver and output
│   ├── algorithms/
│   │   ├── sorting.cpp          - merge, quick, heap, and shaker sort
│   │   └── generator.cpp        - random array generator
│   └── include/
│       ├── sorting.h            - sorting function declarations
│       └── generator.h          - generator function declaration
├── CMakeLists.txt               - build configuration
└── README.md                    - this file
```