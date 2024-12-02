#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "function.h"

time_ get_time_in_ns()
{
    struct timespec ts;
    time_ t;
    t.time = -1;

    if (clock_gettime(CLOCK_REALTIME, &ts) == -1)
    {
        perror("clock_gettime");
        return t;
    }
    t.time = (unsigned long long int)ts.tv_sec * 1000000000 + ts.tv_nsec;
    return t;
}

void print_arr(int *t, int size)
{
    if (size <= 0)
        return;

    printf("[%d", t[0]);

    if (size > 1)
    {
        for (int i = 1; i < size; i++)
        {
            printf(", %d", t[i]);
        }
    }

    printf("]\n");
}

int *clone_arr(int *t, int size)
{
    int *new_arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        new_arr[i] = t[i];
    }

    return new_arr;
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int *random_arr(int lenght)
{
    srand(time(0));
    int *arr = (int *)malloc(sizeof(int) * lenght);
    if (arr == NULL)
    {
        perror("Échec de l'allocation de mémoire");
        exit(1);
    }
    for (int i = 0; i < lenght; i++)
    {
        arr[i] = rand() % lenght;
    }
    return arr;
}

int *invert_arr(int lenght)
{
    srand(time(0));
    int *arr = (int *)malloc(sizeof(int) * lenght);
    if (arr == NULL)
    {
        perror("Échec de l'allocation de mémoire");
        exit(1);
    }
    for (int i = 0; i < lenght; i++)
    {
        arr[i] = lenght - i;
    }
    return arr;
}

long long unsigned int gap_ns(time_ start, time_ end) {
    return end.time-start.time;
}


long double gap(time_ start, time_ end) {
    long long unsigned int result = end.time-start.time;
    return (long double ) result / (long double) (1000000000.0);
}

void append(char *filename, char *line) {
    FILE *file = fopen(filename, "a");
    fputs(line, file);
    fclose(file);
}

void clear_file(char *filename) {
    FILE *file = fopen(filename, "w");
    fputs("", file);
    fclose(file);
}

void substring(char *src, char *dest, int start, int end) {
    if(end < start) {
        printf("lenght do not negative :c\n");
        return;
    }
    if(src == NULL || dest == NULL) {
        printf("src or dest do not NULL :c\n");
        return;
    }
    if(end > strlen(src)) {
        printf("end do not superior to lenght of src :c\n");
        return;
    }
    int j = 0;
    for(int i = start; i<end; i++, j++) {
        dest[j] = src[i];
    }
}

