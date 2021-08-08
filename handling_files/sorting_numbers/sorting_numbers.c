#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int aux = *a;

    *a = *b;
    *b = aux;
}

void bubble_sort(int array[], int length) 
{
    int i,j, flag;

    for (i = length; i > 0; i--) 
    {
        flag = 0;

        for (j = 0; j < i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);

                flag = 1;
            }
        }

        if (!flag) 
        {
            break;
        }
    }    
}

void checkFile(FILE *file) 
{
    if (!file) 
    {
        printf("Unable to open or create the file!");
        exit(1);
    }
}

int main () 
{
    FILE *input = fopen("numbers.txt", "r");
    FILE *output = fopen("sorted_numbers.txt", "w");

    int numbers[20], i = 0;

    checkFile(input);
    checkFile(output);

    while (!feof(input) && i <= 20) 
    {
        fscanf(input, "%d,", &numbers[i]);
        i++;
    }

    bubble_sort(numbers, 20);

    for (i = 0; i < 20; i++)
    {
        fprintf(output, "%d\n", numbers[i]);
    }

    fclose(input);
    fclose(output);

    return 0;
}