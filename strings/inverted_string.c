#include <stdio.h>
#include <string.h>

int main()
{
    void string_inverted(char[]);
    char string[100];

    fgets(string, sizeof(string), stdin);
    string_inverted(string);

    return 0;
}

void string_inverted(char *string)
{
    int i = 0;
    int length = strlen(string);
    char inverted[100];
    
    for (; i <= length; i++)
    {
        inverted[i] = string[length - i];
        printf("%c", inverted[i]);
    }
}