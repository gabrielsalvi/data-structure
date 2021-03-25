#include <stdio.h>

int main() {

    int fibonacci(int x);

    printf("%d\n", fibonacci(0));

    return 0;
}

int fibonacci(int x) {

    if (x == 0) {
        return 0;
    }
    
    if (x == 1) {
        return 1;
    }

    return fibonacci(x-2) + fibonacci(x-1);
}
