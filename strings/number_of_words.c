#include <stdio.h>

int main()
{
    int getWords(char[]);
    char string[100];

    fgets(string, sizeof(string), stdin);
    printf("\nwords: %d\n", getWords(string));

    return 0;
}

int getWords(char *string)
{
    int words = 1, i = 0;

    for (; i <= strlen(string); i++)
    {
        if ((string[i] == 32))
        {
            words = words + 1;
        }
    }

    return words;
}