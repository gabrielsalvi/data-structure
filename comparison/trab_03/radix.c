#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int year;
    char model[30];
} Car;

void generateOutput(FILE *file, Car *cars, int length)
{
    for (int i = 0; i < length; i++)
    {
        // fprintf(file, "%s", cars[i].model);
        fprintf(file, "\n");
    }
}

int getMax(Car *cars, int length)
{
    int i, max = cars[0].year;

    for (i = 1; i < length; i++)
    {
        if (cars[i].year > max)
        {
            max = cars[i].year;
        }
    }

    return max;
}

void countingSort(Car *cars, int length, int pos)
{

    Car *aux = (Car *)malloc(length * sizeof(Car));
    int count[10] = {0}, i, digit;

    for (i = 0; i < length; i++)
    {
        digit = (cars[i].year / pos) % 10;
        count[digit]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = length - 1; i >= 0; i--)
    {
        digit = (cars[i].year / pos) % 10;
        count[digit]--;

        aux[count[digit]] = cars[i];
    }

    for (i = 0; i < length; i++)
    {
        cars[i] = aux[i];
    }
}

void radixSort(Car *cars, int length)
{
    int pos, max = getMax(cars, length);

    for (pos = 1; max / pos > 0; pos *= 10)
    {
        countingSort(cars, length, pos);
    }
}

int main()
{
    int length = 15, i = 1, j = 0;
    Car *cars = (Car*)malloc(15 * sizeof(Car)), aux;

    FILE *input, *output;

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    if (input == NULL)
    {
        fprintf(output, "Não foi possível abrir o arquivo de entrada!");
        fclose(output);

        exit(0);
    }
    
    while (i <= 30)
    {
        if (i % 2 != 0)
        {
            fgets(aux.model, 30, input);
        }
        else
        {
            fscanf(input, "%d%*s", &aux.year);
        }

        cars[j] = aux;
        
        if (j < 15) {
            j++;
        }

        i++;
    }

    generateOutput(output, cars, length);

    // fclose(input);

    // radixSort(cars, length);

    // generateOutput(output, cars, length);

    fclose(output);

    return 0;
}