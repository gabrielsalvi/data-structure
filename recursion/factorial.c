#include <stdio.h>

int main() {
    int fatorial(int n);

    printf("%d\n", fatorial(10));

    return 0;
}

int fatorial(int n) {
    if (n == 0)
    {
        return 1;
    }
    
    return n * fatorial(n-1);
}