// Sum of the vector values

#include <stdio.h>

int somatorio(int vetor[], int pos)
{
    if (pos == 0)
    {
        return vetor[pos];
    }

    return somatorio(vetor, pos - 1) + vetor[pos];
}

int main()
{
    int vetor[] = {1, 2, 3, 4, 10};

    printf("%d\n", somatorio(vetor, 4));

    return 0;
}