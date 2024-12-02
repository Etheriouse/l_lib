#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_sorted(int *arr, int size);
void shuffle(int *arr, int size);

int *bogo_sort(int *arr, int size)
{
    while (!is_sorted(arr, size))
    {
        shuffle(arr, size);
    }
    return arr;
}

int is_sorted(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void shuffle(int *arr, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        int random_index = rand() % size;
        int temp = arr[i];
        arr[i] = arr[random_index];
        arr[random_index] = temp;
    }
}