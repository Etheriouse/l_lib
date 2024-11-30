#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "function.h"

int intro_partition(int *arr, int low, int high);
void intro_heapify(int *arr, int size, int root);
void intro_heap_sort(int *arr, int size);
void intro_insertion_sort(int *arr, int low, int high);
void _intro_sort(int *arr, int low, int high, int deap_max);


int *intro_sort(int *arr, int size) {
    double log_n = log2(size);
    int max_deep = 2 * ((int) log_n);
    _intro_sort(arr, 0, size-1, max_deep);
    return arr;
}

void _intro_sort(int *arr, int low, int high, int deap_max) {
    int size = high - low + 1;

    if (size < 16) {
        intro_insertion_sort(arr, low, high);
        return;
    }

    if (deap_max == 0) {
        intro_heap_sort(arr + low, size);
        return;
    }

    int pivot = intro_partition(arr, low, high);
    _intro_sort(arr, low, pivot - 1, deap_max - 1);
    _intro_sort(arr, pivot + 1, high, deap_max - 1);
}

int intro_partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, high);
    return i + 1;
}

void intro_heapify(int *arr, int size, int root) {
    int l = root;
    int g = 2 * root + 1;
    int d = 2 * root + 2;

    if (g < size && arr[g] > arr[l]) {
        l = g;
    }
    if (d < size && arr[d] > arr[l]) {
        l = d;
    }
    if (l != root) {
        swap(arr, root, l);
        intro_heapify(arr, size, l);
    }
}

void intro_heap_sort(int *arr, int size) {

    for (int i = size / 2 - 1; i >= 0; i--) {
        intro_heapify(arr, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        swap(arr, 0 , i);
        intro_heapify(arr, i, 0);
    }
}

void intro_insertion_sort(int *arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}