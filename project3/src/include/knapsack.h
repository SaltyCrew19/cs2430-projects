//knapsack.h
#pragma once
#include <string>
#include <vector>

struct Experiment
{
    int id;
    std::string name;
    int weight;
    int rating;
};

struct Results
{
    std::vector<Experiment> experiments; //holds the experiments on the ship
    int totalWeight;
    int totalRating;
};

Results selectByRating(std::vector<Experiment> vecArr);
Results selectByWeight(std::vector<Experiment> vecArr);
Results selectByRatio(std::vector<Experiment> vecArr);
std::vector<Results> bruteForceSearch (const std::vector<Experiment> &vecArr);

void quickSort(std::vector<Experiment> &vec, int choice);
void quickSort(std::vector<Results> &vec);

void test();