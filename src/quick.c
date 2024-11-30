#include <stdio.h>
#include <stdlib.h>

#include "function.h"

int partition(int *arr, int low, int high);
void _quick_sort(int *arr, int low, int high);

int *quick_sort(int *arr, int size) {
    _quick_sort(arr, 0, size-1);
    return arr;
}

void _quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        _quick_sort(arr, low, pi - 1);
        _quick_sort(arr, pi + 1, high);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr,i, j);
        }
    }

    swap(arr, i+1, high);
    return i + 1;
}

