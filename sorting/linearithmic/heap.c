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
    int *aux = *a;
    
    *a = *b;
    *b = aux;
}

void heapify(int array[], int k, int length)
{
    int largest = k;
    int left = 2 * k + 1;
    int right = 2 * k + 2;

    if (left < length && array[left] > array[k])
    {
        largest = left;
    }

    if (right < length && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != k)
    {
        swap(&array[k], &array[largest]);
        heapify(array, largest, length);
    }

}

void heapSort(int array[], int length)
{
    int k;

    for(k = length / 2 - 1; k >= 0; k--) 
    {
        heapify(array, k, length);
    }

    for(k = length-1; k > 0; k--) 
    {
        swap(&array[0], &array[k]);
        heapify(array, 0, k);
    }
}

int main()
{
    int array[] = {6, 12, 4, 10, 8, 31, 7, 3, 5, 11}, length = sizeof(array) / sizeof(array[0]);

    printf("Before Sorting:\n");
    printArray(array, length);

    heapSort(array, length);

    printf("\nAfter Sorting:\n");
    printArray(array, length);
    
    return 0;
}