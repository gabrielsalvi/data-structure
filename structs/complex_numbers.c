#include <stdio.h>

typedef struct
{
    double real;
    double imaginario;
} Complexo;

Complexo criaComplexo(double real, double imaginario)
{
    Complexo complexo;
    complexo.real = real;
    complexo.imaginario = imaginario;

    return complexo;
}

Complexo somaComplexo(Complexo a, Complexo b)
{
    Complexo soma;

    soma.real = a.real + b.real;
    soma.imaginario = a.imaginario + b.imaginario;

    return soma;
}

int main()
{
    double num1, num2, num3, num4;
    scanf("%lf %lf", &num1, &num2);
    scanf("%lf %lf", &num3, &num4);

    Complexo a = criaComplexo(num1, num2);
    Complexo b = criaComplexo(num3, num4);

    Complexo soma = somaComplexo(a, b);
    printf("real: %lf\nimaginario: %lfi\n", soma.real, soma.imaginario);

    return 0;
}