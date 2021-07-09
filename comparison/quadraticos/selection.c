#include <stdio.h>
#include <time.h>

#define LENGTH 10000 // 50000 100000

void printArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("array[%d]: %d\n", i, array[i]);
    }
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
        array[i] = length - i;
    }
}

void generateRandomArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % length;
    }
}

void swap(int *array, int i, int min)
{
    int aux = array[i];
    array[i] = array[min];
    array[min] = aux;
}

void selectionSort(int array[], int length)
{
    int i, j, min;

    for (i = 0; i < length - 1; i++)
    {
        min = i;

        for (j = i + 1; j < length; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }

        swap(array, i, min);
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
    selectionSort(increasing, LENGTH);
    end = clock();
    increasing_t = ((double)end - start) / CLOCKS_PER_SEC;

    // sorting a decreasing array
    start = clock();
    selectionSort(decreasing, LENGTH);
    end = clock();
    decreasing_t = ((double)end - start) / CLOCKS_PER_SEC;

    // sorting a random array
    start = clock();
    selectionSort(random, LENGTH);
    end = clock();
    random_t = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Increasing Array: -> s: %lf, ms: %lf\n", increasing_t, increasing_t * 1000);
    printf("Decreasing Array: -> s: %lf, ms: %lf\n", decreasing_t, decreasing_t * 1000);
    printf("Random Array: -> s: %lf, ms: %lf\n", random_t, random_t * 1000);

    return 0;
}