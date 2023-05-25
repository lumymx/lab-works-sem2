#include "sort.h"

void swap(double* a, double* b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortArray(double* array, int size)
{
    double tmp;
    double a;
    double b;
    for (int i = 0; i < size; i++)
        for(int j = 0; j < size - 1; j++)
            if(array[j] > array[j + 1])
                swap(array + j, array + j + 1);
}


