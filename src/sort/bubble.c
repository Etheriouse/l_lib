#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int *bubble_sort(int *arr, int size) {
    int sorted = true;
    for(int i = 0; i<size-1; i++) {
        sorted = true;
        for(int j = 0; j< size -i-1; j++) {
            if(arr[j+1] < arr[j]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                sorted = false;
            }
        }
        //print_arr(arr, size);
        if(sorted) {
            return arr;
        }
    }
    return arr;
}
