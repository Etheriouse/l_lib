#include <stdio.h>
#include <stdlib.h>

int *insertion_sort(int *arr, int size)
{
    int min = 0, j = 0;

    for (int i = 0; i < size; i++)
    {
        min = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] > min)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = min;
    }

    return arr;
}
