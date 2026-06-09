#include <iostream>
#include <string>
#include "sorting.h"
#include "generator.h"

std::string printArr(int arr[],int size);

int main(int, char**)
{
    std::string welcomeMsg; 
    welcomeMsg.append("Welcome to Connors Sorting Algorithms Project\n");
    std::cout << welcomeMsg;
    // std::cout << "Hello, from SortingAlgorithms!\n";
    /*
    Merge sort
    Quick sort
    Heap sort
    Shaker sort (also called cocktail sort — it's basically bubble sort going both directions)
    */
    int count = 5;
    int* unsortedArr = generateArr(count);
    std::string output;
    output.append("here are all the sorts in action the unsorted array is randomized per sort alg\nMerge Sort:\t");
    mergeSort(unsortedArr, count);
    output.append(printArr(unsortedArr, count) + "\n");

    output.append("Quick Sort:\t");
    unsortedArr = generateArr(count);
    quickSort(unsortedArr,count);
    output.append(printArr(unsortedArr, count) + "\n");

    output.append("Heap Sort:\t");
    unsortedArr = generateArr(count);
    heapSort(unsortedArr,count);
    output.append(printArr(unsortedArr, count) + "\n");

    output.append("Shaker Sort:\t");
    unsortedArr = generateArr(count);
    shakerSort(unsortedArr,count);
    output.append(printArr(unsortedArr, count) + "\n");
    
    std::cout << output;
    return 0;
}


std::string printArr(int arr[], int size)
{
    std::string sarr = "[";
    for (int i = 0; i < size; i++)
    {
        sarr.append(std::to_string(arr[i]));
        if (i < size - 1) sarr.append(", ");
    }
    sarr.append("]");
    return sarr;
}

