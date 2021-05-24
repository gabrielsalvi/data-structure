#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define e 2.718281828459045235360287

double f(double x)
{
    return pow(e, x) + 2;
}

int main()
{
    int n;
    double a, b, largura, area_r, area_l, area_total, coluna_r, coluna_l;

    while (1)
    {
        printf("\nValor de a: ");
        scanf("%lf", &a);

        printf("Valor de b: ");
        scanf("%lf", &b);

        if (b > a)
        {
            break;
        }
        else
        {
            printf("\nO valor de b deve ser maior que o de a!\n");
        }
    }

    printf("Nº de subintervalos: ");
    scanf("%d", &n);

    largura = (b - a) / n;

    coluna_r = a + largura;
    coluna_l = a;

    for (int i = n; i > 0; i--)
    {
        area_r = largura * f(coluna_r) + area_r;
        coluna_r = coluna_r + largura;

        area_l = largura * f(coluna_l) + area_l;
        coluna_l = coluna_l + largura;
    }

    area_total = (area_r + area_l) / 2;

    printf("\n%lf < A < %lf\n", area_l, area_r);
    printf("Área Total (aproximadamente) = %lf\n", area_total);

    return 0;
}