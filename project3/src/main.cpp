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

void verify();

int main(int, char**)
{
    ConsoleOutput sys = ConsoleOutput("KnapsackOptimization");
    sys.intro();

    verify();
}

void verify()
{
    ConsoleOutput sys = ConsoleOutput("Verification");
    Results rating = selectByRating(experiments);
    Results weight = selectByWeight(experiments);
    Results ratio  = selectByRatio(experiments);
    Results brute  = bruteForceSearch(experiments)[0];

    bool rating_matched = (rating.totalRating == brute.totalRating);
    bool weight_matched = (weight.totalRating == brute.totalRating);
    bool ratio_matched  = (ratio.totalRating  == brute.totalRating);

    sys.print("Rating-first matched optimal: " + std::string(rating.totalRating == brute.totalRating ? "true" : "false") + " (Greedy: " + std::to_string(rating.totalRating) + " vs Brute: " + std::to_string(brute.totalRating) + ")");
    sys.print("Weight-first matched optimal: " + std::string(weight.totalRating == brute.totalRating ? "true" : "false") + " (Greedy: " + std::to_string(weight.totalRating) + " vs Brute: " + std::to_string(brute.totalRating) + ")");
    sys.print("Ratio-first matched optimal:  " + std::string(ratio.totalRating == brute.totalRating  ? "true" : "false") + " (Greedy: " + std::to_string(ratio.totalRating)  + " vs Brute: " + std::to_string(brute.totalRating) + ")");
}



