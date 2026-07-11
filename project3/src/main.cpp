/*
    Name:       Connor
    Course:     CS 2430, Section 501
    Project:    Programming Project 3 - Knapsack Problem
    File:       main.cpp
    Purpose:    Defines test data and runs set/Knapsack Problem
*/
#include <iostream>
#include <sstream>
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

std::string verify();

int main(int, char**)
{
    ConsoleOutput sys = ConsoleOutput("KnapsackOptimization");
    sys.intro();
    sys.print("Building output Stream");
    std::stringstream output;
    Results rating = selectByRating(experiments);
    Results weight = selectByWeight(experiments);
    Results ratio  = selectByRatio (experiments);
    output << "\n(Greedy Methods)\n";
    output << "select By Rating:\t\t" << "Rating: " << rating.totalRating << "\tweight: " << rating.totalWeight << "\t ratio: " << ((double)rating.totalRating / rating.totalWeight) << "\n";
    output << "select By weight:\t\t" << "Rating: " << weight.totalRating << "\tweight: " << weight.totalWeight << "\t ratio: " << ((double)weight.totalRating / weight.totalWeight) << "\n";
    output << "select By ratio:\t\t"  << "Rating: " << ratio.totalRating << "\tweight: " << ratio.totalWeight << "\t ratio: " << ((double)ratio.totalRating / ratio.totalWeight) << "\n";

    std::vector<Results> brute = bruteForceSearch(experiments);
    output << "\n(Brute Method Top 3)\n";
    output << "Ship 1 (OPTIMAL):\t\t" << "Rating: " << brute[0].totalRating << "\tweight: " << brute[0].totalWeight << "\t ratio: " << ((double)brute[0].totalRating / brute[0].totalWeight) << "\n";
    output << "Ship 2:\t\t\t\t" << "Rating: " << brute[1].totalRating << "\tweight: " << brute[1].totalWeight << "\t ratio: " << ((double)brute[1].totalRating / brute[1].totalWeight) << "\n";
    output << "Ship 3:\t\t\t\t" << "Rating: " << brute[2].totalRating << "\tweight: " << brute[2].totalWeight << "\t ratio: " << ((double)brute[2].totalRating / brute[2].totalWeight) << "\n";
    
    output << "\n\n" << verify();
    sys.print(output);
}

std::string verify()
{
    ConsoleOutput sys = ConsoleOutput("Verification");
    sys.print("Verification Started");
    std::string output;
    Results rating = selectByRating(experiments);
    Results weight = selectByWeight(experiments);
    Results ratio  = selectByRatio(experiments);
    Results brute  = bruteForceSearch(experiments)[0];

    bool rating_matched = (rating.totalRating == brute.totalRating);
    bool weight_matched = (weight.totalRating == brute.totalRating);
    bool ratio_matched  = (ratio.totalRating  == brute.totalRating);

    output.append("Rating-first matched optimal: " + std::string(rating.totalRating == brute.totalRating ? "true" : "false") + " (Greedy: " + std::to_string(rating.totalRating) + " vs Brute: " + std::to_string(brute.totalRating) + ")\n");
    output.append("Weight-first matched optimal: " + std::string(weight.totalRating == brute.totalRating ? "true" : "false") + " (Greedy: " + std::to_string(weight.totalRating) + " vs Brute: " + std::to_string(brute.totalRating) + ")\n");
    output.append("Ratio-first matched optimal:  " + std::string(ratio.totalRating == brute.totalRating  ? "true" : "false") + " (Greedy: " + std::to_string(ratio.totalRating)  + " vs Brute: " + std::to_string(brute.totalRating) + ")\n");
    return output;
}



