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

void bubbleSort(int array[], int length)
{
    int aux, swaps;

    for (int i = length; i >= 1; i--)
    {
        swaps = 0;

        for (int j = 0; j < i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;

                swaps = 1;
            }
        }

        if (swaps == 0)
        {
            break;
        }
    }
}

int main()
{
    int array[] = {6, 12, 4, 10, 8, 31, 7, 3, 5, 11}, length = 10;

    printArray(array, length);

    bubbleSort(array, length);

    printArray(array, length);
}