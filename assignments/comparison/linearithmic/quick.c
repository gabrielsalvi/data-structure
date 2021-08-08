#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10000 //50000 100000

void printArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("array[%d]: %d\n", i, array[i]);
    }

    printf("\n");
}

void generateIncreasingArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = i;
    }
}

void generateDecreasingArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = length - i - 1;
    }
}

void generateRandomArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % length;
    }
}

void swap(int *i, int *k)
{
    int aux = *i;

    *i = *k;
    *k = aux;
}

int partition(int *array, int start, int end)
{
    int k = start, pivot_pos = end;

    for (int i = start; i < end; i++)
    {
        if (array[i] <= array[pivot_pos])
        {
            swap(&array[i], &array[k]);
            k++;
        }
    }

    if (array[k] > array[pivot_pos])
    {
        swap(&array[k], &array[pivot_pos]);
        pivot_pos = k;
    }

    return pivot_pos;
}

void quickSort(int *array, int start, int end)
{
    if (start < end)
    {
        int pivot_pos = partition(array, start, end);

        quickSort(array, start, pivot_pos - 1);
        quickSort(array, pivot_pos + 1, end);
    }
}

int main()
{
    int increasing[LENGTH], decreasing[LENGTH], random[LENGTH];
    double increasing_t, decreasing_t, random_t;
    clock_t start, end;

    generateIncreasingArray(increasing, LENGTH);
    generateDecreasingArray(decreasing, LENGTH);
    generateRandomArray(random, LENGTH);

    // sorting an increasing array
    start = clock();
    quickSort(increasing, 0, LENGTH - 1);
    end = clock();
    increasing_t = ((double)end - start) / CLOCKS_PER_SEC;

    // sorting a decreasing array
    start = clock();
    quickSort(decreasing, 0, LENGTH - 1);
    end = clock();
    decreasing_t = ((double)end - start) / CLOCKS_PER_SEC;

    // sorting a random array
    start = clock();
    quickSort(random, 0, LENGTH - 1);
    end = clock();
    random_t = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Increasing Array: -> s: %lf, ms: %lf\n", increasing_t, increasing_t * 1000);
    printf("Decreasing Array: -> s: %lf, ms: %lf\n", decreasing_t, decreasing_t * 1000);
    printf("Random Array: -> s: %lf, ms: %lf\n", random_t, random_t * 1000);
    
    return 0;
}