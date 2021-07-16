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

int main ()
{
    int array[] = {6, 12, 4, 10, 8, 31, 7, 3, 5, 11}, length = sizeof(array) / sizeof(array[0]);

    printf("Before Sorting:\n");
    printArray(array, length);

    quickSort(array, 0, length - 1);

    printf("\nAfter Sorting:\n");
    printArray(array, length);

    return 0;
}