#include <stdio.h>
#include <stdlib.h>

#include "function.h"

int *selection_sort(int *arr, int size)
{
    int i = 0, j, index_min;

    for (; i < size; i++)
    {
        index_min = i;
        j = i;

        while (j < size)
        {
            if (arr[index_min] > arr[j])
            {
                index_min = j;
            }
            j++;
        }

        int temp = arr[index_min];
        arr[index_min] = arr[i];
        arr[i] = temp;
    }
    return arr;
}
