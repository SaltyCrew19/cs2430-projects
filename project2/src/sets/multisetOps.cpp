//multisetOps.cpp
#include "multisetOps.h"
#include <algorithm>
namespace Multisets
{
    //MAX
    int* Union(int* setA, int* setB, int size)
    {
        int* result = new int[size];
        for (int i = 0; i < size; i++){result[i] = std::max(setA[i], setB[i]);}
        return result;
    }

    //NIN
    int* Intersection(int* setA, int* setB, int size)
    {
        int* result = new int[size];
        for (int i = 0; i < size; i++){result[i] = std::min(setA[i], setB[i]);}
        return result;
    }

    //Subtract
    int* Difference(int* setA, int* setB, int size)
    {
        int* result = new int[size];
        for (int i = 0; i < size; i++){result[i] = std::max( 0 , setA[i] - setB[i]);}
        return result;
    }

    //add
    int* Sum(int* setA, int* setB, int size)
    {
        int* result = new int[size];
        for (int i = 0; i < size; i++){result[i] = setA[i] + setB[i];}
        return result;
    }

}