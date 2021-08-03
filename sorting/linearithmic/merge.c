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
    int array[] = {6, 12, 4, 10, 8, 31, 7, 3, 5, 11}, length = sizeof(array) / sizeof(array[0]);

    printf("Given array :\n");
    printArray(array, length);

    mergeSort(array, 0, length - 1);

    printf("\nSorted array:\n");
    printArray(array, length);

    return 0;
}