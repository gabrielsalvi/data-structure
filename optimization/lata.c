#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct lata
{
    double volume;
    double raio;
    double altura;
    double area_lateral;
    double area_base;
    double area_total;
} Lata;

double raio(double volume)
{
    return pow((volume / (2 * PI)), (1.0 / 3.0));
}

double altura(double volume)
{
    return pow((4 * (volume / PI)), (1.0 / 3.0));
}

double area_lateral(Lata lata)
{
    return 2 * PI * lata.raio * lata.altura;
}

double area_base(Lata lata)
{
    return PI * pow(lata.raio, 2);
}

double area_total(Lata lata)
{
    return 2 * lata.area_base + lata.area_lateral;
}

double custo_total(Lata lata, double custo_base, double custo_lados)
{
   return custo_base * lata.area_base * 2 + custo_lados * lata.area_lateral;
}

void printLataInfo(Lata lata)
{
    printf("\nRaio: %.2lfcm\n", lata.raio);
    printf("Altura: %.2lfcm\n", lata.altura);
    printf("Altura: %.2lfcm\n", lata.altura);
    printf("Volume (pi * r² * h): %lf\n", PI * pow(lata.raio, 2) * lata.altura);
    printf("Volume (area base * h): %lf\n", lata.area_base * lata.altura);
}

Lata initializeLata(Lata lata)
{
    printf("Capacidade da lata (em cm³) -> ");
    scanf("%lf", &lata.volume);

    lata.raio = raio(lata.volume);
    lata.altura = altura(lata.volume);
    lata.area_lateral = area_lateral(lata);
    lata.area_base = area_base(lata);
    lata.area_total = area_total(lata);

    return lata;
}

int main()
{
    Lata lata = initializeLata(lata);

    double custo_t, custo_base, custo_lados;
    
    printf("Custo do material do topo e da base da lata (por m²) -> ");
    scanf("%lf", &custo_base);

    printf("Custo do material dos lados da lata (por m²) -> ");
    scanf("%lf", &custo_lados);

    custo_t = custo_total(lata, custo_base, custo_lados);

    printLataInfo(lata);
    printf("Custo Total: R$%.2lf\n", custo_t);

    return 0;
}