#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double inferior, superior;
} Intervalo;

Intervalo limite_inferior_superior(double a, double b, Intervalo intervalo)
{
    if (a >= b)
    {
        intervalo.inferior = b;
        intervalo.superior = a;
    }
    else
    {
        intervalo.inferior = a;
        intervalo.superior = b;
    }

    return intervalo;
}

double f(double x)
{
    double e = 2.718281828459045235360287;

    return pow(e, x) - 3 + (2 * pow(x, 2));
}

void solucao_no_intervalo(Intervalo intervalo)
{
    double aux, aux2;

    aux = intervalo.inferior;
    aux2 = intervalo.inferior + 0.01;

    while (aux2 < intervalo.superior)
    {
        if ((f(aux) > 0 && f(aux2) < 0) || (f(aux) < 0 && f(aux2) > 0))
        {
            intervalo.inferior = aux;
            intervalo.superior = aux2;

            if (intervalo.superior - intervalo.inferior <= 0.1)
            {
                printf("\nA  equação  tem  pelo  menos  uma  solução  neste  intervalo!\n");
                printf("[%.4lf, %.4lf] -> S= { %lf, %lf }\n", intervalo.inferior, intervalo.superior, f(intervalo.inferior), f(intervalo.superior));
                exit(0);
            }
        }
        aux = aux + 0.01;
        aux2 = aux2 + 0.01;
    }

    printf("\nNão  é  possível  afirmar  que  existe  solução  neste  intervalo,  tente  outros  dois números!\n");
}

int main()
{
    Intervalo intervalo;
    double num1, num2;

    // lê os valores pelo teclado
    printf("Insira os valores desejados: \n");
    scanf("%lf %lf", &num1, &num2); 

    // atribui o maior valor digitado para o intervalo superior e o menor para o intervalo inferior
    intervalo = limite_inferior_superior(num1, num2, intervalo); 

    // procura uma solução reduzindo o intervalo para no mínimo 1/10 de diferença entre o valor 'a' e 'b'
    solucao_no_intervalo(intervalo);

    return 0;
}