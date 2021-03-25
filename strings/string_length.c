#include <stdio.h>

int main()
{
    int string_length(char[]);
    char string[100];

    fgets(string, sizeof(string), stdin);
    printf("\nlength: %d\n", string_length(string));

    return 0;
}

int string_length(char *string)
{
    int length = 0, i = 0;

    for (; i <= strlen(string); i++)
    {
        if ((string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122))
        {
            length = length + 1;
        }
    }

    return length;
}