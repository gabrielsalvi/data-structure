#include <stdio.h>
#include <stdlib.h>

int binary_search(int *array, int right, int key)
{
    int left = 0, middle = (left + right) / 2;

    while (left <= right)
    {
        if (array[middle] == key)
        {
            return middle;
        }
        else if (array[middle] < key)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }

        middle = (left + right) / 2;
    }

    return -1;
}

int main()
{
    int integers[] = {1, 5, 10, 18, 32, 44, 48, 51, 66, 77, 99}, length = sizeof(integers) / sizeof(integers[0]), key, position;

    printf("What number do you want to search for? - ");
    scanf("%d", &key);

    position = binary_search(integers, length - 1, key);

    if (position == -1)
    {
        printf("The number wasn't found!\n");
    }
    else
    {
        printf("The number was found at position: %d", position);
    }

    return 0;
}