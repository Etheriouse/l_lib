#include <stdio.h>
#include <stdlib.h>

#include "function.h"

int *comb_sort(int *arr, int size) {
    int gap = size;
    int sorted = true;
    const float shrink = 1.3;

    while (gap > 1 || sorted) {
        gap = (int)(gap / shrink);
        if (gap < 1) {
            gap = 1;
        }

        sorted = false;


        for (int i = 0; i + gap < size; i++) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                sorted = true;
            }
        }
    }

    return arr;
}