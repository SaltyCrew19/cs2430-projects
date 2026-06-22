//multisetOps.h
/*
    Name:       Connor
    Course:     CS 2430, Section 501
    Project:    Programming Project 2 - Sets and Multisets
    File:       multisetOps.h
    Purpose:    Declares multiset operations using integer arrays
*/
namespace Multisets
{
    int* Union(int* setA, int* setB, int size);
    int* Intersection(int* setA, int* setB, int size);
    int* Difference(int* setA, int* setB, int size);
    int* Sum(int* setA, int* setB, int size);
}