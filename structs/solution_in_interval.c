#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double lower, higher;
} Interval;

Interval setInterval(double a, double b, Interval interval)
{
    if (a >= b)
    {
        interval.lower = b;
        interval.higher = a;
    }
    else
    {
        interval.lower = a;
        interval.higher = b;
    }

    return interval;
}

double f(double x)
{
    double e = 2.718281828459045235360287;
    return pow(e, x) - 3 + (2 * pow(x, 2));
}

void getSolution(Interval interval)
{
    double aux, aux2;

    aux = interval.lower;
    aux2 = interval.lower + 0.01;

    while (aux2 < interval.higher)
    {
        if ((f(aux) > 0 && f(aux2) < 0) || (f(aux) < 0 && f(aux2) > 0))
        {
            interval.lower = aux;
            interval.higher = aux2;

            if (interval.higher - interval.lower <= 0.1)
            {
                printf("\nThe equation has at least one solution in this interval!\n");
                printf("[%.4lf, %.4lf] -> f(%.4lf) = %lf | f(%.4lf) = %lf\n", interval.lower, interval.higher, interval.lower, f(interval.lower), interval.higher, f(interval.higher));
                exit(0);
            }
        }
        aux = aux + 0.01;
        aux2 = aux2 + 0.01;
    }
    printf("\nIt's not possible to assure that exists a solution in this interval. Try other two numbers!\n");
}

int main()
{
    Interval interval;
    double num1, num2;

    printf("Type the values of the interval: \n");
    scanf("%lf %lf", &num1, &num2); 

    interval = setInterval(num1, num2, interval); 

    getSolution(interval);

    return 0;
}