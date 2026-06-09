#include "generator.h"
#include <random>
int* generateArr(int n)
{
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<> range(1, 100);
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = range(engine);
    }
    return arr;
}