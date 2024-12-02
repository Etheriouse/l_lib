#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <omp.h>

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

/*
 0 -> 1 000 000 000
 10 000 gap
*/

int main(int argc, char const *argv[])
{
    time_ start, end;

    char line[200];

    int *origin_array;

    long long unsigned int quick_t;
    long long unsigned int merge_t;
    long long unsigned int heap_t;
    long long unsigned int intro_t;

    clear_file("sort_time.csv");
    append("sort_time.csv", "time;quick;merge;heap;intro\n");

    for (int n = 100000; n < 1000000; n += 10000)
    {
        printf("for %d: \n", n);
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                start = get_time_in_ns(); // deja trier pire cas
                origin_array = invert_arr(n);
                printf("tableau cree quick %d: \n", n);
                origin_array = quick_sort(origin_array, n);
                printf("tableau fini quick %d: \n", n);
                free(origin_array);
                end = get_time_in_ns();
                quick_t = gap_ns(start, end);
            }

            #pragma omp section
            {
                start = get_time_in_ns();
                origin_array = invert_arr(n);
                printf("tableau cree merge %d: \n", n);
                origin_array = merge_sort(origin_array, n);
                printf("tableau fini merge %d: \n", n);
                free(origin_array);
                end = get_time_in_ns();
                merge_t = gap_ns(start, end);
            }

            #pragma omp section
            {
                start = get_time_in_ns();
                origin_array = invert_arr(n);
                printf("tableau cree heap %d: \n", n);
                origin_array = heap_sort(origin_array, n);
                printf("tableau fini heap %d: \n", n);
                free(origin_array);
                end = get_time_in_ns();
                heap_t = gap_ns(start, end);
            }

            #pragma omp section
            {
                start = get_time_in_ns();
                origin_array = invert_arr(n);
                printf("tableau cree intro %d: \n", n);
                origin_array = intro_sort(origin_array, n);
                printf("tableau fini intro %d: \n", n);
                free(origin_array);
                end = get_time_in_ns();
                intro_t = gap_ns(start, end);
            }
        }
        sprintf(line, "%d;%llu;%llu;%llu;%llu\n", n, quick_t, merge_t, heap_t, intro_t);
        append("sort_time.csv", line);
    }

    return 0;
}