#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "merge.h"
#include "function.h"

#define length 1000

int main(int argc, char const *argv[])
{

    srand(time(0));

    int array_origin[length];

    for(int i = 0; i<length; i++) {
        array_origin[i] = rand()%100;
    }

    int *array = clone_arr(array_origin, length);

    print_arr(array_origin, length);

    array = merge_sort(array, length);

    print_arr(array, length);

    free(array);
    //free(sorted_array);

    return 0;
}