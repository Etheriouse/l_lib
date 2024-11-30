#include <stdio.h>
#include <stdlib.h>

void print_arr(int *t, int size)
{
    if (size <= 0)
        return;

    printf("[%d", t[0]);

    if (size > 1)
    {
        for (int i = 1; i < size; i++)
        {
            printf(", %d", t[i]);
        }
    }

    printf("]\n");
}

int *clone_arr(int *t, int size)
{
    int *new_arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        new_arr[i] = t[i];
    }

    return new_arr;
}

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
