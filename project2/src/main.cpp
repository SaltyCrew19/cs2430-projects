/*
    Name:       Connor
    Course:     CS 2430, Section 501
    Project:    Programming Project 2 - Sets and Multisets
    File:       main.cpp
    Purpose:    Defines test data and runs set/multiset operations
*/
#include <iostream>
#include "consoleOutput.h"
#include "setOps.h"
#include "multisetOps.h"

//declarations
std::string boolSetToElements(int size, bool* set);
std::string boolSetsTostring(int size, bool* set);
std::string multiSetsToString(int size, int* set);
std::string multiSetToElements(int size, int* set);
//

std::string store[10] = {
    "Apple",    // index 0
    "Banana",   // index 1
    "Mango",    // index 2
    "Orange",   // index 3
    "Grape",    // index 4
    "Peach",    // index 5
    "Plum",     // index 6
    "Pear",     // index 7
    "Kiwi",     // index 8
    "Lemon"     // index 9
};
int setSize = 10;

int main(int, char**)
{
    ConsoleOutput* sys = new ConsoleOutput("SetsAndMultisets");
    sys->intro();    

    bool setA[10] = {1, 0, 1, 0, 1, 0, 0, 0, 1, 1};// Store A carries apples, mangos, grapes, kiwis, lemons
    bool setB[10] = {0, 1, 1, 1, 0, 1, 0, 1, 0, 0};// Store B carries bananas, mangos, oranges, peaches, pears
    bool setC[10] = {1, 1, 0, 0, 0, 0, 1, 1, 0, 1};// Store C carries apples, bananas, plums, pears, lemons (edge case)


    int multisetA[10] = {3, 0, 5, 0, 2, 0, 0, 0, 4, 1};// Stock counts for Store A
    int multisetB[10] = {0, 2, 3, 4, 0, 6, 0, 2, 0, 0};// Stock counts for Store B
    int multisetC[10] = {1, 4, 0, 0, 0, 0, 3, 2, 0, 5};// Stock counts for Store C
    std::string sets;
    
    // --- Set Operations ---
    sets.append("\nSet Operations\n");
    sets.append("Store A\t\t" + boolSetToElements(setSize, setA) + "\nBit String:\t" + boolSetsTostring(setSize, setA) + "\n\n");
    sets.append("Store B\t\t" + boolSetToElements(setSize, setB) + "\nBit String:\t" + boolSetsTostring(setSize, setB) + "\n\n");
    sets.append("Store C\t\t" + boolSetToElements(setSize, setC) + "\nBit String:\t" + boolSetsTostring(setSize, setC) + "\n\n");

    bool* boolResult = nullptr;

    // -- Test Case 1: Store A and Store B --
    sets.append("-- Test Case 1: Store A and Store B --\n");

    boolResult = Sets::ComplementNOT(setA, setSize);
    sets.append("NOT(A):\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::Union(setA, setB, setSize);
    sets.append("A u B:\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::Intersection(setA, setB, setSize);
    sets.append("A n B:\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::Difference(setA, setB, setSize);
    sets.append("A - B:\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::SymmetricDifference(setA, setB, setSize);
    sets.append("A (+) B:\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n\n");
    delete[] boolResult;


    // -- Test Case 2: Store A and Store C --
    sets.append("-- Test Case 2: Store A and Store C --\n");

    boolResult = Sets::ComplementNOT(setA, setSize);
    sets.append("NOT(A):\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::Union(setA, setC, setSize);
    sets.append("A u C:\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::Intersection(setA, setC, setSize);
    sets.append("A n C:\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::Difference(setA, setC, setSize);
    sets.append("A - C:\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::SymmetricDifference(setA, setC, setSize);
    sets.append("A (+) C:\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n\n");
    delete[] boolResult;


    // -- Test Case 3 (Edge): Store B and Store C --
    sets.append("-- Test Case 3 (Edge): Store B and Store C --\n");

    boolResult = Sets::ComplementNOT(setB, setSize);
    sets.append("NOT(B):\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::Union(setB, setC, setSize);
    sets.append("B u C:\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::Intersection(setB, setC, setSize);
    sets.append("B n C:\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::Difference(setB, setC, setSize);
    sets.append("B - C:\t\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n");
    delete[] boolResult;

    boolResult = Sets::SymmetricDifference(setB, setC, setSize);
    sets.append("B (+) C:\t" + boolSetsTostring(setSize, boolResult) + "  ->  " + boolSetToElements(setSize, boolResult) + "\n\n");
    delete[] boolResult;


    // --- Multiset Operations ---
    sets.append("\nMultiset Operations\n");
    sets.append("Store A\t\t" + multiSetToElements(setSize, multisetA) + "\nCounts:\t\t" + multiSetsToString(setSize, multisetA) + "\n\n");
    sets.append("Store B\t\t" + multiSetToElements(setSize, multisetB) + "\nCounts:\t\t" + multiSetsToString(setSize, multisetB) + "\n\n");
    sets.append("Store C\t\t" + multiSetToElements(setSize, multisetC) + "\nCounts:\t\t" + multiSetsToString(setSize, multisetC) + "\n\n");

    int* multiResult = nullptr; // Assuming your multiset functions return int* arrays

    // -- Test Case 1: Store A and Store B --
    sets.append("-- Test Case 1: Store A and Store B --\n");

    multiResult = Multisets::Union(multisetA, multisetB, setSize);
    sets.append("A u B (max):\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n");
    delete[] multiResult;

    multiResult = Multisets::Intersection(multisetA, multisetB, setSize);
    sets.append("A n B (min):\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n");
    delete[] multiResult;

    multiResult = Multisets::Difference(multisetA, multisetB, setSize);
    sets.append("A - B:\t\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n");
    delete[] multiResult;

    multiResult = Multisets::Sum(multisetA, multisetB, setSize);
    sets.append("A + B:\t\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n\n");
    delete[] multiResult;


    // -- Test Case 2: Store A and Store C --
    sets.append("-- Test Case 2: Store A and Store C --\n");

    multiResult = Multisets::Union(multisetA, multisetC, setSize);
    sets.append("A u C (max):\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n");
    delete[] multiResult;

    multiResult = Multisets::Intersection(multisetA, multisetC, setSize);
    sets.append("A n C (min):\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n");
    delete[] multiResult;

    multiResult = Multisets::Difference(multisetA, multisetC, setSize);
    sets.append("A - C:\t\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n");
    delete[] multiResult;

    multiResult = Multisets::Sum(multisetA, multisetC, setSize);
    sets.append("A + C:\t\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n\n");
    delete[] multiResult;


    // -- Test Case 3 (Edge): Store B and Store C --
    sets.append("-- Test Case 3 (Edge): Store B and Store C --\n");

    multiResult = Multisets::Union(multisetB, multisetC, setSize);
    sets.append("B u C (max):\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n");
    delete[] multiResult;

    multiResult = Multisets::Intersection(multisetB, multisetC, setSize);
    sets.append("B n C (min):\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n");
    delete[] multiResult;

    multiResult = Multisets::Difference(multisetB, multisetC, setSize);
    sets.append("B - C:\t\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n");
    delete[] multiResult;

    multiResult = Multisets::Sum(multisetB, multisetC, setSize);
    sets.append("B + C:\t\t" + multiSetsToString(setSize, multiResult) + "  ->  " + multiSetToElements(setSize, multiResult) + "\n");
    delete[] multiResult;

    sys->print(sets);
    delete sys;
    return 0;
}

std::string boolSetToElements(int size, bool* set)
{
    std::string output;
    output.append("[");
    bool first = true;
    for (int i = 0; i < size; i++)
    {
        if (set[i])
        {
            if (!first) output.append(", ");
            output.append(store[i]);
            first = false;
        }
    }
    output.append("]");
    return output;
}


std::string boolSetsTostring(int size, bool* set)
{
    std::string output;
    output.append("[");
    for(int i = 0; i < size; i++)
    {
        output.append(set[i] ? "1" : "0");
        if(i < size - 1) output.append(", ");
    }
    output.append("]");
    return output;
}

std::string multiSetsToString(int size, int* set)
{
    std::string output;
    output.append("[");
    for(int i = 0; i < size; i++)
    {
        output.append(std::to_string(set[i]));
        if(i < size - 1) output.append(", ");
    }
    output.append("]");
    return output;
}

std::string multiSetToElements(int size, int* set)
{
    std::string output;
    output.append("[");
    bool first = true;
    for(int i = 0; i < size; i++)
    {
        if(set[i] > 0)
        {
            if(!first) output.append(", ");
            output.append(store[i] + "x" + std::to_string(set[i]));
            first = false;
        }
    }
    output.append("]");
    return output;
}
