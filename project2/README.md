# Project 2 - Sets And Multisets Operations
**CS 2430 | Connor | Summer 2026**

## Description
This project Demonstrates set and multiset operations
Set
q NOT(p)
q u p
q n p
q - p
q (+) p
Multi
q u p
q n p
q - p
q + p

## Language
C++ (C++17)

## Build Instructions
From the `/project2` directory:
```bash
cmake -S . -B build
cmake --build build
```

## Run Instructions
```bash
.\build\SetsAndMultisets.exe
```

## File Structure
```
project2/
├── src/
│   ├── main.cpp                 
│   ├── output/  
│       └── ConsoleOutput.cpp
│   ├── sets/  
│   │   ├── multisetOps.cpp         
│   │   └── setOps.cpp        
│   └── include/
│       ├── ConsoleOutput.h            
│       ├── multisetOps.h            
│       └── setOps.h          
├── CMakeLists.txt               - build configuration
└── README.md                    - this file
```