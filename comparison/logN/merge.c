#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void merge(int array[], int start, int middle, int end)
{
    int *aux = (int*) malloc((end-start+1) * sizeof(int));
    int i = start, j = middle + 1, k = 0;

    while(i <= middle && j <= end)
    {
        if (array[i] < array[j])
        {
            aux[k] = array[i];
            i++;
        }
        else
        {
            aux[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= middle)
    {
        aux[k] = array[i];
        k++;
        i++;
    }

    while (j <= end)
    {
        aux[k] = array[j];
        k++;
        j++;
    }

    for (k = start; k <= end; k++)
    {
        array[k] = aux[k-start];
    }

    free(aux);
}

void mergeSort(int array[], int start, int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;

        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);
        merge(array, start, middle, end);
    }
}

int main()
{
    int length = 100000; // 50000 100000

    int increasing[length], decreasing[length], random[length];
    double increasing_t, decreasing_t, random_t;
    clock_t start, end;

    generateIncreasingArray(increasing, length);
    generateDecreasingArray(decreasing, length);
    generateRandomArray(random, length);

    // sorting an increasing array
    start = clock();
    mergeSort(increasing, 0, length - 1);
    end = clock();
    increasing_t = ((double)end - start) / CLOCKS_PER_SEC;

    // sorting a decreasing array
    start = clock();
    mergeSort(decreasing, 0, length - 1);
    end = clock();
    decreasing_t = ((double)end - start) / CLOCKS_PER_SEC;

    // sorting a random array
    start = clock();
    mergeSort(random, 0, length - 1);
    end = clock();
    random_t = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Increasing Array: -> s: %lf, ms: %lf\n", increasing_t, increasing_t * 1000);
    printf("Decreasing Array: -> s: %lf, ms: %lf\n", decreasing_t, decreasing_t * 1000);
    printf("Random Array: -> s: %lf, ms: %lf\n", random_t, random_t * 1000);

    // printArray(increasing, length);
    // printArray(decreasing, length);
    // printArray(random, length);
    
    return 0;
}