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
            } else {
                break;
            }
        }
        
        array[j] = aux;
    }
}

int main()
{
    int array[] = {6, 12, 4, 10, 8, 31, 7, 3, 5, 11}, length = sizeof(array) / sizeof(array[0]);

    printf("Before Sorting:\n");
    printArray(array, length);

    insertionSort(array, length);

    printf("\nAfter Sorting:\n");
    printArray(array, length);
}