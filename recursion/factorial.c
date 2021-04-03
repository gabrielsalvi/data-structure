#include <stdio.h>

int main() {
    int factorial(int n), number;

    printf("Factorial of:\n");
    scanf("%d", &number);

    printf("\nThe factorial of %d is %d", number, factorial(number));

    return 0;
}

int factorial(int n) {
    if (n == 0)
    {
        return 1;
    }
    
    return n * factorial(n-1);
}