//knapsack.cpp
/*
    Name:       Connor
    Course:     CS 2430, Section 501
    Project:    Programming Project 3 - Knapsack Problem
    File:       knapsack.cpp
    Purpose:    Defines knapsack methods
*/

/*
    This method demonstrates efficiency: in theory, it reaches the true optimal solution without doing the full exponential work brute force requires.

    FUNCTION solveKnapsackDP(const std::vector<Experiment>& experiments, int maxCapacity)
        // 1. Initialize the 2D table using std::vector of std::vector
        // Rows: 0 to numExperiments (size + 1)
        // Columns: 0 to maxCapacity (maxCapacity + 1)
        // All memory is pre-allocated and zero-initialized
        int numExperiments = experiments.size()
        std::vector<std::vector<int>> dpTable(numExperiments + 1, std::vector<int>(maxCapacity + 1, 0))

        // 2. Outer loop: Iterate through the experiment pool
        FOR i FROM 1 TO numExperiments:
            // Use a constant reference to avoid expensive copying of struct data
            const auto& current = experiments[i-1] 

            // Inner loop: Evaluate every discrete weight capacity capacity
            FOR w FROM 0 TO maxCapacity:
                
                // Option A: Skip the current experiment (Look up one row in the matrix)
                int skipOption = dpTable[i-1][w]

                // Option B: Take the current experiment (Verify it does not exceed current bounds)
                int takeOption = 0
                IF current.weight <= w THEN
                    // O(1) pointer-offset lookup for remaining capacity from the previous subproblem
                    takeOption = current.rating + dpTable[i-1][w - current.weight]
                ENDIF

                // Assign the cell to the maximum value using std::max logic
                dpTable[i][w] = std::max(skipOption, takeOption)
            ENDFOR
        ENDFOR

        // 3. Return the evaluation result stored in the final block of the vector
        RETURN dpTable[numExperiments][maxCapacity]
    ENDFUNCTION
*/
#include "knapsack.h"
#include "ConsoleOutput.h"
#include <vector>
#include <string>
#include <cmath>

static void quickSortHelperRating(std::vector<Experiment> &vec, int low, int high);
static void quickSortHelperWeight(std::vector<Experiment> &vec, int low, int high);
static void quickSortHelperRatio(std::vector<Experiment> &vec, int low, int high);
static Results selectKnap(const std::vector<Experiment> &vecArr);
static void swapElements(std::vector<Experiment> &vec, int a, int b);

static void quickSortHelperResults(std::vector<Results> &vec, int low, int high);
static void swapElements(std::vector<Results> &vec, int a, int b);

const int WEIGHT_LIMIT = 700;
static std::vector<Experiment> experiments = {
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

Results selectByRating(std::vector<Experiment> vecArr)
{
    quickSort(vecArr,1);
    return selectKnap(vecArr);
}
Results selectByWeight(std::vector<Experiment> vecArr)
{

    quickSort(vecArr,2);
    return selectKnap(vecArr);
}
Results selectByRatio(std::vector<Experiment> vecArr)
{

    quickSort(vecArr,3);
    return selectKnap(vecArr);
}
static Results selectKnap(const std::vector<Experiment> &vecArr)
{
    Results results;
    int totalWeight = 0;
    int totalRating = 0;
    for (int i = vecArr.size()-1; i >= 0; i--)
    {
        if((totalWeight + vecArr[i].weight) <= WEIGHT_LIMIT)
        {
            totalRating += vecArr[i].rating;
            totalWeight += vecArr[i].weight;
            results.totalRating = totalRating;
            results.totalWeight = totalWeight;
            results.experiments.push_back(vecArr[i]);
        }
    }
    return results;
}
std::vector<Results> bruteForceSearch (const std::vector<Experiment> &vecArr)
{
    std::vector<Results> results = {};
    int totalWeight;
    int totalRating;
    int maxsize = std::pow(2,vecArr.size());
    for (int i = 0; i < maxsize; i++)
    {
        totalRating = 0;
        totalWeight = 0;
        Results temp;
        for (int n = 0; n < vecArr.size(); n++)
        {
            if (i & (1 << n))
            {
                temp.experiments.push_back(vecArr[n]);
                totalRating += vecArr[n].rating;
                totalWeight += vecArr[n].weight;
            }
        }
        if (totalWeight <= WEIGHT_LIMIT)
        {
            temp.totalRating = totalRating;
            temp.totalWeight = totalWeight;
            results.push_back(temp);
        }
    }
    std::vector<Results> finalResults;
    quickSort(results);
    if (results.size() > 3){for (int i = results.size()-1; i > results.size()-4; i--){finalResults.push_back(results[i]);}}
    else{return results;}
    
    return finalResults;
}
/**
 * @param vector
 * @param choice 1= sort by rating, 2= sort by weight, 3 = sort by ratio
 */
void quickSort(std::vector<Experiment> &vec, int choice)
{
    int comparisons = 0;
    switch (choice)
    {
    case 1:
        quickSortHelperRating(vec, 0, vec.size()-1);
        break;
    case 2:
        quickSortHelperWeight(vec, 0, vec.size()-1);
        break;
    case 3:
        quickSortHelperRatio(vec, 0, vec.size()-1);
        break;
    
    default:
        ConsoleOutput sys = ConsoleOutput("knapsack.cpp");
        sys.print("something went wrong the selector (" + std::to_string(choice) + ") was used in quickSort selection");
        break;
    }
}

static void quickSortHelperRating(std::vector<Experiment> &vec, int low, int high)
{
    if(low >= high){return;}
    Experiment pivot = vec[high];
    int i = low -1;
    for(int j = low; j < high; j++)
    {
        if (vec[j].rating <= pivot.rating)
        {i++; swapElements(vec, i , j);}
    }
    swapElements(vec, i+1, high);
    int pivotPos = i + 1;
    quickSortHelperRating(vec, low, pivotPos - 1);
    quickSortHelperRating(vec, pivotPos + 1, high);
}
static void quickSortHelperWeight(std::vector<Experiment> &vec, int low, int high)
{
    if(low >= high){return;}
    Experiment pivot = vec[high];
    int i = low -1;
    for(int j = low; j < high; j++)
    {
        if (vec[j].weight >= pivot.weight)
        {i++; swapElements(vec, i , j);}
    }
    swapElements(vec, i+1, high);
    int pivotPos = i + 1;
    quickSortHelperWeight(vec, low, pivotPos - 1);
    quickSortHelperWeight(vec, pivotPos + 1, high);
}
static void quickSortHelperRatio(std::vector<Experiment> &vec, int low, int high)
{
    if(low >= high){return;}
    Experiment pivot = vec[high];
    int i = low -1;
    for(int j = low; j < high; j++)
    {
        if ((double)vec[j].rating/vec[j].weight <= (double)pivot.rating/pivot.weight)
        {i++; swapElements(vec, i , j);}
    }
    swapElements(vec, i+1, high);
    int pivotPos = i + 1;
    quickSortHelperRatio(vec, low, pivotPos - 1);
    quickSortHelperRatio(vec, pivotPos + 1, high);
}

static void swapElements(std::vector<Experiment> &vec, int a, int b)
{
    Experiment temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}

void quickSort(std::vector<Results> &vec)
{
    quickSortHelperResults(vec, 0, vec.size()-1);
}

static void quickSortHelperResults(std::vector<Results> &vec, int low, int high)
{
    if(low >= high){return;}
    Results pivot = vec[high];
    int i = low -1;
    for(int j = low; j < high; j++)
    {
        if ((double)vec[j].totalRating <= (double)pivot.totalRating)
        {i++; swapElements(vec, i , j);}
    }
    swapElements(vec, i+1, high);
    int pivotPos = i + 1;
    quickSortHelperResults(vec, low, pivotPos - 1);
    quickSortHelperResults(vec, pivotPos + 1, high);
}
static void swapElements(std::vector<Results> &vec, int a, int b)
{
    Results temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}