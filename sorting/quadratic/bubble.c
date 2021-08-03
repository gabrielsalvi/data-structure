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

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort(int array[], int length)
{
    int swaps;

    for (int i = length; i >= 1; i--)
    {
        swaps = 0;

        for (int j = 0; j < i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j+1]);

                swaps = 1;
            }
        }

        if (!swaps)
        {
            break;
        }
    }
}

int main()
{
    int array[] = {6, 12, 4, 10, 8, 31, 7, 3, 5, 11}, length = sizeof(array) / sizeof(array[0]);

    printf("Before Sorting:\n");
    printArray(array, length);

    bubbleSort(array, length);

    printf("\nAfter Sorting:\n");
    printArray(array, length);

    return 0;
}