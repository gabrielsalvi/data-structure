#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char name[50];
    float first_grade;
    float second_grade;
} Student;

void checkFile(FILE *file) 
{
    if (!file) 
    {
        printf("Unable to open or create the file!\n");
        exit(1);
    }
}

int main () 
{
    FILE *input = fopen("../input.txt", "r");
    Student student;

    float average;
    
    checkFile(input);
    
    fseek(input, sizeof(int) - 1, SEEK_SET);

    while (!feof(input)) 
    {
        fscanf(input, "%[A-Z ]\n", student.name);
        fscanf(input, "%f\n", &student.first_grade);
        fscanf(input, "%f\n", &student.second_grade);

        average = (student.first_grade + student.second_grade) / 2;

        if (average < 7.0)
        {
            printf("%s\n", student.name);
        }
    }

    fclose(input);

    return 0;
}