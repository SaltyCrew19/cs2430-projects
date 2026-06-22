//setOps.h
/*
    Name:       Connor
    Course:     CS 2430, Section 501
    Project:    Programming Project 2 - Sets and Multisets
    File:       setOps.h
    Purpose:    Declares ordinary set operations using boolean arrays
*/
namespace Sets
{
    bool* ComplementNOT(bool* set, int size);
    bool* Union(bool* setA, bool* setB, int size);
    bool* Intersection(bool* setA, bool* setB, int size);
    bool* Difference(bool* setA, bool* setB, int size);
    bool* SymmetricDifference(bool* setA, bool* setB, int size);
}
