#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int year;
    char model[30];
} Vehicle;


Vehicle createVehicle(int year, char *model)
{
    Vehicle vehicle;
    
    vehicle.year = year;
    strcpy(vehicle.model, model);

    return vehicle;
}

void addVehicles(Vehicle *vehicles) 
{
    vehicles[0] = createVehicle(2007, "Jeep Compass");
    vehicles[1] = createVehicle(2016, "Fiat Toro");
    vehicles[2] = createVehicle(2001, "Honda Fit");
    vehicles[3] = createVehicle(2014, "Jeep Renegade");
    vehicles[4] = createVehicle(1994, "Audi A4");
    vehicles[5] = createVehicle(2021, "Volkswagen Nivus");
    vehicles[6] = createVehicle(1998, "Fiat Strada");
    vehicles[7] = createVehicle(2016, "Honda SH 300i");
    vehicles[8] = createVehicle(2020, "BMW R 1250 RT");
    vehicles[9] = createVehicle(2003, "Ford Ecosport");
    vehicles[10] = createVehicle(2014, "Hyundai Creta");
    vehicles[11] = createVehicle(1998, "Ford Focus");
    vehicles[12] = createVehicle(2013, "Chevrolet Onix");
    vehicles[13] = createVehicle(2007, "Renault Sandero");
    vehicles[14] = createVehicle(1979, "Volkswagen Jetta");
}

void printfVehicles(Vehicle *vehicles, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d - %s\n", vehicles[i].year, vehicles[i].model);
    }
}

int getMax(Vehicle *vehicles, int length)
{
    int i, max = vehicles[0].year;

    for (i = 1; i < length; i++)
    {
        if (vehicles[i].year > max)
        {
            max = vehicles[i].year;
        }
    }

    return max;
}

void countingSort(Vehicle *vehicles, int length, int pos)
{

    Vehicle *aux = (Vehicle *)malloc(length * sizeof(Vehicle));
    int count[10] = {0}, i, digit;

    for (i = 0; i < length; i++)
    {
        digit = (vehicles[i].year / pos) % 10;
        count[digit]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = length - 1; i >= 0; i--)
    {
        digit = (vehicles[i].year / pos) % 10;
        count[digit]--;

        aux[count[digit]] = vehicles[i];
    }

    for (i = 0; i < length; i++)
    {
        vehicles[i] = aux[i];
    }
}

void radixSort(Vehicle *vehicles, int length)
{
    int pos, max = getMax(vehicles, length);

    for (pos = 1; max / pos > 0; pos *= 10)
    {
        countingSort(vehicles, length, pos);
    }
}

int main()
{
    Vehicle vehicles[15];
    int length = 15;

    addVehicles(vehicles);

    printf("Lista de Veículos:\n\n");
    printfVehicles(vehicles, length);

    radixSort(vehicles, length);

    printf("\nLista de Veículos Ordenados pelo Ano:\n\n");
    printfVehicles(vehicles, length);

    return 0;
}