#include <stdio.h>

int sum(int array[], int length)
{
    if (length == 0)
    {
        return array[length];
    }

    return sum(array, length - 1) + array[length];
}

int main()
{
    int array[6], length = (sizeof(array) / sizeof(array[0])) - 1;

    printf("Type integer values:\n");

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\nSum of the array values: %d\n", sum(array, length));

    return 0;
}