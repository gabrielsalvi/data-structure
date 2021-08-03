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

        swap(&array[i], &array[min]);
    }
}

int main()
{
    int array[] = {6, 12, 4, 10, 8, 31, 7, 3, 5, 11}, length = sizeof(array) / sizeof(array[0]);

    printf("Before Sorting:\n");
    printArray(array, length);

    selectionSort(array, length);

    printf("\nAfter Sorting:\n");
    printArray(array, length);

    return 0;
}