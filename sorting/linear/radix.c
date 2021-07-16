#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);

        if (i == length - 1)
        {
            printf("\n");
        }
    }
}

int getMax(int array[], int length) 
{
    int i, max = array[0];

    for (i = 1; i < length; i++) 
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

void countingSort(int array[], int length, int pos) 
{

    int *aux = (int*) malloc(length * sizeof(int)), count[10] = { 0 };
    int i, digit;

    for (i = 0; i < length; i++)
    {
        digit = (array[i] / pos) % 10;
        count[digit]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }

    for (i = length - 1; i >= 0; i--) 
    {
        digit = (array[i] / pos) % 10;
        count[digit]--;

        aux[count[digit]] = array[i];
    }

    for (i = 0; i < length; i++) 
    {
        array[i] = aux[i];
    }
}

void radixSort(int array[], int length)
{
    int pos, max = getMax(array, length);

    for (pos = 1; max/pos > 0; pos *= 10)
    {
        countingSort(array, length, pos);
    }
}

int main()
{
    int array[] = {6, 12, 4, 10, 8, 31, 7, 3, 5, 11}, length = sizeof(array) / sizeof(array[0]);

    printf("Before Sorting:\n");
    printArray(array, length);

    radixSort(array, length);

    printf("\nAfter Sorting:\n");
    printArray(array, length);
}