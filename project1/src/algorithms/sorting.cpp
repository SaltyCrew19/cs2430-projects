#include "sorting.h"
#include <iostream>

// sorting.cpp - private helpers
static void quickSortHelper(int arr[], int low, int high, int& comparisons);
static void mergeSortHelper(int arr[], int size, int& comparisons);
static void merge(int arr[], int left[], int leftSize, int right[], int rightSize, int& comparisons);
static void swapElements(int arr[], int a, int b);

void mergeSort(int arr[], int n)
{
    int comparisons = 0;
    mergeSortHelper(arr, n, comparisons);
}

static void mergeSortHelper(int arr[], int size, int& comparisons)
{
    if (size <= 1){return;}
    int mid = size/2;
    int* left = new int[mid];
    int* right = new int[size - mid];

    for (int i = 0; i < mid; i++)
    {left[i] = arr[i];}// left

    for (int i = 0; i < size - mid; i++)
    {right[i] = arr[mid + i];}// right

    mergeSortHelper(left, mid, comparisons);
    mergeSortHelper(right, size-mid, comparisons);

    merge(arr, left, mid, right, size-mid, comparisons);

    delete[] left;
    delete[] right;

}
void merge(int arr[], int left[], int leftSize, int right[], int rightSize, int& comparisons)
{
    int i = 0;//left
    int j = 0;//right
    int k = 0;//arr

    while ((i < leftSize) && (j < rightSize))
    {
        if(left[i] < right[j]){arr[k] = left[i]; i++; comparisons++;}
        else{arr[k] = right[j]; j++; comparisons++;}
        k++;
    }

    while (i < leftSize) { arr[k] = left[i]; i++; k++; }
    while (j < rightSize) { arr[k] = right[j]; j++; k++; }
    
}


void quickSort(int arr[], int n)
{
    int comparisons = 0;
    quickSortHelper(arr, 0, n-1, comparisons);
}

static void quickSortHelper(int arr[], int low, int high, int& comparisons)
{
    if(low >= high){return;}
    int pivot = arr[high];
    int i = low -1;
    for(int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {i++; swapElements(arr, i , j);}
        comparisons++;
    }
    swapElements(arr, i+1, high);
    int pivotPos = i + 1;
    quickSortHelper(arr, low, pivotPos - 1, comparisons);
    quickSortHelper(arr, pivotPos + 1, high, comparisons);
}
void swapElements(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void heapSort(int arr[], int n)
{
//TODO: do the next 2 sorting algs
}

void shakerSort(int arr[], int n)
{
    
}