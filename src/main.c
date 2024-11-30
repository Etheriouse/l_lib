#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"

#include "merge.h"
#include "insertion.h"
#include "selection.h"
#include "bogo.h"
#include "bubble.h"
#include "comb.h"
#include "heap.h"
#include "quick.h"
#include "introsort.h"


#define length 14

int main(int argc, char const *argv[])
{

    srand(time(0));

    int array_origin[length];

    for(int i = 0; i<length; i++) {
        array_origin[i] = rand()%10;
    }

    int *array = clone_arr(array_origin, length);

    print_arr(array_origin, length);

    array = intro_sort(array, length);

    print_arr(array, length);

    free(array);
    return 0;
}