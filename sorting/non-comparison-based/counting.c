#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int getLargest(int array[], int lenght)
{
    int largest = array[0];

    for (int i = 0; i < lenght; i++)
    {
        if (array[i] > largest)
        {
            largest = array[i];
        }
    }

    return largest;
}

void countingSort(int array[], int length)
{
    int i, k = getLargest(array, length);

    int *count = (int*) malloc((k+1) * sizeof(int));
    int *aux = (int*) malloc(length * sizeof(int));

    for (i = 0; i <= k; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < length; i++)
    {
        count[array[i]]++;
    }

    for (i = 1; i <= k; i++)
    {
        count[i] += count[i-1];
    }

    for (i = length - 1; i >= 0; i--)
    {
        count[array[i]] = count[array[i]] - 1;
        aux[count[array[i]]] = array[i];
    }

    for (i = 0; i < length; i++)
    {
        array[i] = aux[i];
    }

    free(count);
    free(aux);
}

int main()
{
    int array[] = {6, 12, 4, 10, 8, 31, 7, 3, 5, 11}, length = sizeof(array) / sizeof(array[0]);

    printf("Before Sorting:\n");
    printArray(array, length);

    countingSort(array, length);

    printf("\nAfter Sorting:\n");
    printArray(array, length);

    return 0;
}