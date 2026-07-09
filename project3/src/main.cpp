/*
    Name:       Connor
    Course:     CS 2430, Section 501
    Project:    Programming Project 3 - Knapsack Problem
    File:       main.cpp
    Purpose:    Defines test data and runs set/Knapsack Problem
*/
#include <iostream>
#include "knapsack.h"
#include "ConsoleOutput.h"
std::vector<Experiment> experiments = {
    {1, "Cloud Patterns", 36, 5},
    {2, "Solar Flares", 264, 9},
    {3, "Solar Power", 188, 6},
    {4, "Binary Stars", 203, 8},
    {5, "Relativity", 104, 8},
    {6, "Seed Viability", 7, 4},
    {7, "Sun Spots", 90, 2},
    {8, "Mice Tumors", 65, 8},
    {9, "Microgravity Plant Growth", 75, 5},
    {10, "Micrometeorites", 170, 9},
    {11, "Cosmic Rays", 80, 7},
    {12, "Yeast Fermentation", 27, 4}
};
int main(int, char**)
{
    ConsoleOutput sys = ConsoleOutput("KnapsackOptimization");
    sys.intro();
    
    std::vector<Results> temp = bruteForceSearch(experiments); 
    std::vector<Experiment> temp2; 
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 0; j < temp[i].experiments.size(); j++)
        {
            temp2.push_back(temp[i].experiments[j]);
        }
        temp2.push_back({34,"end of set---------------------------------------------------------",0,0});
    }

    for (int i = 0; i < temp2.size(); i++)
    {
        sys.print(temp2[i].name);
    }
    
    
}



