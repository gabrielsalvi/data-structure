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

void insertionSort(int array[], int length)
{
    int i, j, aux;

    for (i = 1; i < length; i++)
    {
        aux = array[i];

        for (j = i; j > 0; j--)
        {
            if (aux < array[j - 1])
            {
                array[j] = array[j - 1];
            }
            else
            {
                break;
            }
        }

        array[j] = aux;
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
    insertionSort(increasing, LENGTH);
    end = clock();
    increasing_t = ((double)end - start) / CLOCKS_PER_SEC;

    // sorting a decreasing array
    start = clock();
    insertionSort(decreasing, LENGTH);
    end = clock();
    decreasing_t = ((double)end - start) / CLOCKS_PER_SEC;

    // sorting a random array
    start = clock();
    insertionSort(random, LENGTH);
    end = clock();
    random_t = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Increasing Array: -> s: %lf, ms: %lf\n", increasing_t, increasing_t * 1000);
    printf("Decreasing Array: -> s: %lf, ms: %lf\n", decreasing_t, decreasing_t * 1000);
    printf("Random Array: -> s: %lf, ms: %lf\n", random_t, random_t * 1000);

    return 0;
}