//sets.cpp
#include "setOps.h"
#include <string>
namespace Sets
{
    //not
    bool* ComplementNOT(bool* set, int size)
    {
        bool* result = new bool[size];
        for (int i = 0; i < size; i++){result[i] = !set[i];}
        return result;
    }

    //or
    bool* Union(bool* setA, bool* setB, int size)
    {
        return setA;
    }

    //and
    bool* Intersection(bool* setA, bool* setB, int size)
    {
        return setA;
    }

    //and not
    bool* Difference(bool* setA, bool* setB, int size)
    {
        return setA;
    }

    //xor
    bool* SymmetricDifference(bool* setA, bool* setB, int size)
    {
        return setA;
    }
}