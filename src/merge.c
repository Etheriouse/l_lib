#include <stdio.h>
#include <stdlib.h>

int *merge_array(int *left, int size_l, int *right, int size_r);

int *merge_sort(int *arr, int size)
{

    if (size <= 1)
    {
        return arr;
    }

    int mid = size / 2;

    int *left = (int *)malloc(sizeof(int) * mid);
    int *right = (int *)malloc(sizeof(int) * (size - mid));

    int i = 0;

    for (i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    for (i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    free(arr);

    left = merge_sort(left, mid);
    right = merge_sort(right, (size - mid));

    int *sort = merge_array(left, mid, right, (size - mid));

    free(left);
    free(right);

    return sort;
}

int *merge_array(int *left, int size_l, int *right, int size_r)
{
    int *arr = (int *)malloc(sizeof(int) * (size_l + size_r));

    int i = 0, j = 0, n = 0;

    while (i < size_l && j < size_r)
    {
        if (left[i] > right[j])
        {
            arr[n] = right[j];
            j++;
        }
        else
        {
            arr[n] = left[i];
            i++;
        }
        n++;
    }

    while (i < size_l)
    {
        arr[n] = left[i];
        i++;
        n++;
    }

    while (j < size_r)
    {
        arr[n] = right[j];
        j++;
        n++;
    }

    return arr;
}
