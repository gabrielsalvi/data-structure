#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10000 // 50000 100000

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

void swap(int *a, int *b)
{
    int aux = *a;
    
    *a = *b;
    *b = aux;
}

void heapify(int array[], int k, int length)
{
    int largest = k;
    int left = 2 * k + 1;
    int right = 2 * k + 2;

    if (left < length && array[left] > array[k])
    {
        largest = left;
    }

    if (right < length && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != k)
    {
        swap(&array[k], &array[largest]);
        heapify(array, largest, length);
    }
}

void heapSort(int array[], int length)
{
    int k;

    for(k = length / 2 - 1; k >= 0; k--) 
    {
        heapify(array, k, length);
    }

    for(k = length-1; k > 0; k--) 
    {
        swap(&array[0], &array[k]);
        heapify(array, 0, k);
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
    heapSort(increasing, LENGTH);
    end = clock();
    increasing_t = ((double)end - start) / CLOCKS_PER_SEC;

    // sorting a decreasing array
    start = clock();
    heapSort(decreasing, LENGTH);
    end = clock();
    decreasing_t = ((double)end - start) / CLOCKS_PER_SEC;

    // sorting a random array
    start = clock();
    heapSort(random, LENGTH);
    end = clock();
    random_t = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Increasing Array: -> s: %lf, ms: %lf\n", increasing_t, increasing_t * 1000);
    printf("Decreasing Array: -> s: %lf, ms: %lf\n", decreasing_t, decreasing_t * 1000);
    printf("Random Array: -> s: %lf, ms: %lf\n", random_t, random_t * 1000);

    return 0;
}