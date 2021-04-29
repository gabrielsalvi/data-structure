#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REG_LEN 11
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
    struct student *previous;
    struct student *next;
} Student;

typedef struct student_list
{
    Student *head;
    Student *tails;
} StudentList;

void initializeStudentList(StudentList *slist)
{
    slist->head = NULL;
    slist->tails = NULL;
}

Student *getStudent(StudentList *slist, char registration[11])
{
    for (Student *aux = slist->head; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->registration, registration) == 0)
        {
            return aux;
        }
    }

    return NULL;
}

void registerStudent(StudentList *slist, char prev_regis[11])
{
    Student *student = (Student *)malloc(sizeof(Student));

    scanf("%s", student->registration);
    scanf("%s", student->name);
    scanf("%d/%d/%d", &student->birth.day, &student->birth.month, &student->birth.year);
    scanf("%f", &student->average);

    student->previous = NULL;
    student->next = NULL;

    if (slist->head == NULL)
    {
        slist->head = student;
        slist->tails = student;
    }
    else
    {
        Student *previous = getStudent(slist, prev_regis);

        if (previous)
        {
            if (previous == slist->tails)
            {
                previous->next = student;
                student->previous = previous;
                slist->tails = student;
                return;
            }
            else
            {
                student->previous = previous;
                student->next = previous->next;
                previous->next->previous = student;
                previous->next = student;
                return;
            }
        }

        student->next = slist->head;
        slist->head->previous = student;
        slist->head = student;
    }
}

void deleteStudent(StudentList *slist, char registration[11])
{
    Student *student = getStudent(slist, registration);

    if (student)
    {
        if (slist->head == slist->tails)
        {
            slist->head = NULL;
            slist->tails = NULL;
        }
        else
        {
            if (student == slist->head)
            {
                slist->head = slist->head->next;
                slist->head->previous = NULL;
            }
            else if (student == slist->tails)
            {
                slist->tails = slist->tails->previous;
                slist->tails->next = NULL;
            }
            else
            {
                student->previous->next = student->next;
                student->next->previous = student->previous;
            }
        }
        free(student);
    }
}

void printStudents(Student *head)
{
    for (Student *aux = head; aux != NULL; aux = aux->next)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->registration, aux->name, aux->birth.day, aux->birth.month, aux->birth.year, aux->average);
    }
}

void printStudentsInversely(Student *tails)
{
    for (Student *aux = tails; aux != NULL; aux = aux->previous)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->registration, aux->name, aux->birth.day, aux->birth.month, aux->birth.year, aux->average);
    }
}

void clear(StudentList *slist)
{
    Student *delete = NULL;

    while (slist->head)
    {
        delete = slist->head;
        slist->head = slist->head->next;

        free(delete);

        if (slist->head == NULL)
        {
            printf("*\n\n");
        }
        else
        {
            printf("*");
        }
    }

    initializeStudentList(slist);
}

int main()
{
    StudentList slist;
    initializeStudentList(&slist);

    int op;
    char registration[REG_LEN];

    do
    {
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            if (slist.head != NULL)
            {
                clear(&slist);
            }
            break;

        case 1:
            scanf("%s", registration);
            registerStudent(&slist, registration);
            break;

        case 2:
            scanf("%s", registration);

            if (slist.head == NULL)
            {
                printf("Lista Vazia!\n");
                break;
            }

            deleteStudent(&slist, registration);
            break;

        case 3:
            if (slist.head == NULL)
            {
                printf("Lista Vazia!\n");
                break;
            }

            printStudents(slist.head);
            break;

        case 4:
            if (slist.tails == NULL)
            {
                printf("Lista Vazia!\n");
                break;
            }

            printStudentsInversely(slist.tails);
            break;
        }

    } while (op != 0);

    return 0;
}