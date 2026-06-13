#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "sorting.h"
#include "generator.h"

std::string buildTable(int numOfTimes, int sizeOfArr);
std::string printResultLine(std::string sort, int min, int max, float avg);

std::string printArr(int arr[],int size);

int main(int, char**)
{
    std::string welcomeMsg; 
    welcomeMsg.append("-----------------------------------------------------------------------------------------\nWelcome to Connors Sorting Algorithms Project\n-----------------------------------------------------------------------------------------\n");
    std::cout << welcomeMsg;

    std::cout << buildTable(10, 4) + "\n";
    std::cout << buildTable(10, 6) + "\n";
    std::cout << buildTable(10, 8) + "\n";
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

std::string buildTable(int numOfTimes, int sizeOfArr)
{
    std::string table;
    std::string sort;
    int comparisons[numOfTimes];

    table.append(std::to_string(numOfTimes) + " Runs size = "+ std::to_string(sizeOfArr) +"\nPROCESS\t\t MIN\tMAX\tAVG\n");

    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
            case 0:
                sort = "Merge";
                for (int j = 0; j < numOfTimes; j++){comparisons[j] = mergeSort(generateArr(sizeOfArr),sizeOfArr);}
                break;
            case 1:
                sort = "Quick";
                for (int j = 0; j < numOfTimes; j++){comparisons[j] = quickSort(generateArr(sizeOfArr),sizeOfArr);}
                break;
            case 2:
                sort = "Heap";
                for (int j = 0; j < numOfTimes; j++){comparisons[j] = heapSort(generateArr(sizeOfArr),sizeOfArr);}
                break;
            case 3:
                sort = "Shaker";
                for (int j = 0; j < numOfTimes; j++){comparisons[j] = shakerSort(generateArr(sizeOfArr),sizeOfArr);}
                break;
            default:
                sort = "NA";
                break;
        }
        float avg = 0;
        int min = INT_MAX;
        int max = 0;
        for (int j = 0; j < numOfTimes; j++)
        {
            if(min > comparisons[j]){min = comparisons[j];}
            if(max < comparisons[j]){max = comparisons[j];}
            avg += comparisons[j];
        }
        avg = avg/numOfTimes;
        table.append(printResultLine(sort, min, max, avg));
    }
    table.append("-----------------------------------------------------------------------------------------");
    return table;
}

std::string printResultLine(std::string sort, int min, int max, float avg)
{
    std::ostringstream line;
    line << sort << ":\t\t " << min << "\t" << max << "\t" << std::fixed << std::setprecision(2) << avg << "\n";
    return line.str();
}