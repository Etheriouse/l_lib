#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "function.h"

#define length 1000
#define exemple 6

#define size length

/**
 * return index of small element of each array
 * @note do not forget to free xy
 */
int *find_small(int **arr)
{
    int *xy = (int *)malloc(sizeof(int) * 2);
    xy[0] = 0;
    xy[1] = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i][0] < arr[xy[0]][0])
        {
            xy[0] = i;
        }

        if (arr[i][1] < arr[xy[1]][1])
        {
            xy[1] = i;
        }
    }

    return xy;
}

int n_time_right(int **arr, int k) {
    int n = 0;
    for(int i = 0; i<size; i++) {
        if(arr[i][1] == k) {
            n++;
        }
    }
    return n;
}

void similarity_score(int **arr) {
    for(int i = 0; i<size; i++) {
        arr[i][0] = arr[i][0]*n_time_right(arr, arr[i][0]);
    }
}

int main(int argc, char const *argv[])
{
    FILE *file = fopen("assets/HistorianHysteria.csv", "r");
    int **arr = (int **)malloc(sizeof(int *) * size);
    char line[20], l1[10], l2[10];
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * 2);
        fgets(line, sizeof(line), file);
        substring(line, l1, 0, 5);
        substring(line, l2, 6, 11);
        arr[i][0] = atoi(l1);
        arr[i][1] = atoi(l2);
    }

    for (int i = 0; i < size; i++)
    {
        print_arr(arr[i], 2);
    }
    int *xy;

    similarity_score(arr);

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        xy = find_small(arr);
        sum += abs(arr[xy[0]][0] );//- arr[xy[1]][1]);
        arr[xy[0]][0] = INT_MAX;
        arr[xy[1]][1] = INT_MAX;
        free(xy);
    }

    printf("result: %d\n", sum);

    fclose(file);
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
