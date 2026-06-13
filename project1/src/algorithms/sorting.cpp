#include "sorting.h"
#include <iostream>

// sorting.cpp - private helpers
static void quickSortHelper(int arr[], int low, int high, int& comparisons);
static void mergeSortHelper(int arr[], int size, int& comparisons);
static void merge(int arr[], int left[], int leftSize, int right[], int rightSize, int& comparisons);
static void heapify(int arr[], int size, int index, int&comparisons);
/**
 * @brief swaps 2 elements in an array
 * 
 * @param arr the array for elemets to be swapped in
 * @param a index 1
 * @param b index 2
 */
static void swapElements(int arr[], int a, int b);

int mergeSort(int arr[], int n)
{
    int comparisons = 0;
    mergeSortHelper(arr, n, comparisons);
    return comparisons;
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


int quickSort(int arr[], int n)
{
    int comparisons = 0;
    quickSortHelper(arr, 0, n-1, comparisons);
    return comparisons;
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


int heapSort(int arr[], int n)
{
    int comparisons = 0;
    int mid = n/2;
    for (int i = mid; i >= 0; i--) {heapify(arr, n, i, comparisons);}

    for (int i = n-1; i > 0; i--)
    {
        swapElements(arr, 0, i);
        heapify(arr, i, 0, comparisons);
    }
    return comparisons;
}
void heapify(int arr[], int size, int index, int&comparisons)
{
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < size && arr[left] > arr[largest]) {largest = left; comparisons++;}
    if (right < size && arr[right] > arr[largest]) {largest = right; comparisons++;}

    if (largest != index)
    {
        swapElements(arr, index, largest);
        heapify(arr, size, largest, comparisons);
    }
}

int shakerSort(int arr[], int n)
{
    int comparisons = 0;
    int left = 0;
    int right = n-1;

    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            comparisons++;
            if(arr[i] > arr[i+1]){swapElements(arr, i, i+1);}
        }
        right--;

        for (int i = right; i > left; i--)
        {
            comparisons++;
            if (arr[i] < arr[i-1]){swapElements(arr, i, i-1);}
        }
        left++;
    }
    return comparisons;
}




void swapElements(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}