#include <iostream>
#include "consoleOutput.h"
int main(int, char**)
{
    ConsoleOutput* sys = new ConsoleOutput("SetsAndMultisets");
    sys->intro();


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


bool setA[10] = {1, 0, 1, 0, 1, 0, 0, 0, 1, 1};// Store A carries apples, mangos, grapes, kiwis, lemons
bool setB[10] = {0, 1, 1, 1, 0, 1, 0, 1, 0, 0};// Store B carries bananas, mangos, oranges, peaches, pears
bool setC[10] = {1, 1, 0, 0, 0, 0, 1, 1, 0, 1};// Store C carries apples, bananas, plums, pears, lemons (edge case)


int multisetA[10] = {3, 0, 5, 0, 2, 0, 0, 0, 4, 1};// Stock counts for Store A
int multisetB[10] = {0, 2, 3, 4, 0, 6, 0, 2, 0, 0};// Stock counts for Store B
int multisetC[10] = {1, 4, 0, 0, 0, 0, 3, 2, 0, 5};// Stock counts for Store C



    return 0;
}
