#include <stdio.h>
#include <stdlib.h>

void heapify(int *arr, int node, int size);

void __swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int *heap_sort(int *arr, int size) {
    for(int i = (size/2)-1; i>=0; i--) {
        heapify(arr, size, i);
    }

    for(int i = size-1; i>0; i--) {
        __swap(arr, 0, i);
        heapify(arr, i, 0);
    }
    return arr;
}

void heapify(int *arr, int size, int root) {
    int l = root;
    int g = 2*root + 1, d = 2*root + 2;

    if(g < size && arr[g] > arr[l]) {
        l = g;
    }

    if(d < size && arr[d] > arr[l]) {
        l = d;
    }

    if(l != root) {
        __swap(arr, root, l);
        heapify(arr, size, l);
    }
}