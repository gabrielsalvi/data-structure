#include <stdio.h>
#include <stdlib.h>

void checkFile(FILE *file) 
{
    if (!file) 
    {
        printf("Unable to open or create the file!");
        exit(1);
    }
}

int main () 
{
    FILE *input = fopen("input.txt", "r");
    
    int characters = 0, spaces = 0, line_breaks = 0;
    char c;

    checkFile(input);

    while (!feof(input)) 
    {
        char c = fgetc(input);

        if (c == 32) 
        {
            spaces++;
        } 
        else if (c == 10 || c == 13)
        {
            line_breaks++;
        }
        else 
        {
            characters++;
        }
    }

    fclose(input);

    printf("characters: %d\n", characters);
    printf("spaces: %d\n", spaces);
    printf("line breaks: %d\n", line_breaks);

    return 0;
}