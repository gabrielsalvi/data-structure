#include <stdio.h>
#include <stdlib.h>

typedef struct student 
{
    char name[51];
    float g1, g2;
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
    FILE *input = fopen("../input.txt", "r"), *output;
    Student *students, student;

    int length, i = 0;

    checkFile(input);

    fscanf(input, "%d", &length);

    students = (Student *)malloc(sizeof(Student) * length);

    fseek(input, sizeof(int) - 1, SEEK_SET);

    while (!feof(input) && i < length) 
    {
        fscanf(input, "%[A-Z ]\n", student.name);
        fscanf(input, "%f\n", &student.g1);
        fscanf(input, "%f\n", &student.g2);

        students[i] = student;

        i++;
    }

    fclose(input);

    output = fopen("output.dat", "wb");

    checkFile(input);

    fwrite(students, sizeof(Student), length, output);
    fclose(output);

    output = fopen("output.dat", "rb");

    checkFile(output);

    fread(students, sizeof(Student), length, output);

    for (int i = 0; i < length; i++) 
    {
        printf("%s\n", students[i].name);
    }

    free(students);
    fclose(output);

    return 0;
}