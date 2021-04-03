#include <stdio.h>

typedef struct
{
    double real;
    double imaginary;
} Complex;

Complex createComplex(double real, double imaginary)
{
    Complex complex = {real, imaginary};

    return complex;
}

Complex sumComplex(Complex a, Complex b)
{
    Complex sum;

    sum.real = a.real + b.real;
    sum.imaginary = a.imaginary + b.imaginary;

    return sum;
}

int main()
{
    double n1, n2, n3, n4;
    scanf("%lf %lf", &n1, &n2);
    scanf("%lf %lf", &n3, &n4);

    Complex a, b, sum;

    a = createComplex(n1, n2);
    b = createComplex(n3, n4);

    sum = sumComplex(a, b);

    printf("%lf + %lfi\n", sum.real, sum.imaginary);

    return 0;
}