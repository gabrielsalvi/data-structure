#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REG_LEN 10
#define NAME_LEN 40

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct student
{
    char registration[REG_LEN];
    char name[NAME_LEN];
    Date birth;
    float average;
    struct student *next;
} Student;

Student *getLast(Student *head)
{
    Student *last;
    for (last = head; last->next != NULL; last = last->next);
    return last;
}

Student *registerStudent(Student *head)
{
    Student *student = (Student *)malloc(sizeof(Student));

    scanf("%s", student->registration);
    scanf("%s", student->name);
    scanf("%d/%d/%d", &student->birth.day, &student->birth.month, &student->birth.year);
    scanf("%f", &student->average);
    student->next = NULL;

    if (head == NULL)
    {
        return student;
    }

    Student *last = getLast(head);
    last->next = student;

    return head;
}

Student *deleteStudent(Student *head, char registration[10])
{
    Student *aux = head, *previous = NULL, *next = NULL;

    while (aux)
    {
        if (strcmp(aux->registration, registration) == 0)
        {
            if (previous)
            {
                previous->next = aux->next;
            }
            else
            {
                head = head->next;
            }
            next = aux->next;
            free(aux);
            aux = next;
        }
        else
        {
            previous = aux;
            aux = aux->next;
        }
    }

    return head;
}

void printStudents(Student *head)
{
    for (Student *aux = head; aux != NULL; aux = aux->next)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->registration, aux->name, aux->birth.day, aux->birth.month, aux->birth.year, aux->average);
    }
}

void printStudentsInversely(Student *head)
{
    if (head == NULL)
    {
        return;
    }

    printStudentsInversely(head->next);
    printf("%s, %s, %d/%d/%d, %.2f\n", head->registration, head->name, head->birth.day, head->birth.month, head->birth.year, head->average);
}

int listLength(Student *head)
{
    if (head == NULL)
    {
        return 0;
    }

    return 1 + listLength(head->next);
}

void clear(Student *head)
{
    if (head == NULL)
    {
        return;
    }

    clear(head->next);

    free(head);
    printf("-");
}

int main()
{
    Student *head = NULL;
    char registration[REG_LEN];

    int op = -1;

    while (op != 0)
    {
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            clear(head);
            head = NULL;

            printf("\n\n");
            break;

        case 1:
            head = registerStudent(head);
            break;

        case 2:
            scanf("%s", registration);

            if (head == NULL)
            {
                printf("Lista Vazia!\n");
                break;
            }

            head = deleteStudent(head, registration);
            break;

        case 3:
            if (head == NULL)
            {
                printf("Lista Vazia!\n");
                break;
            }

            printStudents(head);
            break;

        case 4:
            if (head == NULL)
            {
                printf("Lista Vazia!\n");
                break;
            }

            printStudentsInversely(head);
            break;

        case 5:
            printf("%d\n", listLength(head));
            break;
        }
    }

    return 0;
}