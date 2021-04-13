#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REG_LENGTH 10
#define NAME_LENGTH 20

typedef struct
{
    int day;
    int month;
    int year;
} Date;

struct student
{
    char registration[REG_LENGTH];
    char name[NAME_LENGTH];
    Date birth;
    float mean;
    struct student *next;
};
typedef struct student Student;

Student *getLast(Student *head)
{
    Student *last = head;
    for (last; last->next != NULL; last = last->next)
        ;
    return last;
}

Student *registerStudent(Student *head)
{
    Student *student = (Student *)malloc(sizeof(Student));

    scanf("\n");

    fgets(student->registration, REG_LENGTH, stdin);
    student->registration[strlen(student->registration) - 1] = '\0';

    fgets(student->name, NAME_LENGTH, stdin);
    student->name[strlen(student->name) - 1] = '\0';

    scanf("%d/%d/%d", &student->birth.day, &student->birth.month, &student->birth.year);
    scanf("%f", &student->mean);
    student->next = NULL;

    if (head == NULL)
    {
        return student;
    }

    Student *aux = getLast(head);
    aux->next = student;

    return head;
}

Student *deleteStudent(Student *head, char registration[10])
{
    Student *aux = head, *previous;

    for (aux; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->registration, registration) == 0)
        {
            if (aux == head)
            {
                head = head->next;
            }
            else
            {
                previous->next = aux->next;
            }

            free(aux);
            return head;
        }
        previous = aux;
    }
    return head;
}

void printAllStudents(Student *head)
{
    Student *aux = head;

    for (aux; aux != NULL; aux = aux->next)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->registration, aux->name, aux->birth.day, aux->birth.month, aux->birth.year, aux->mean);
    }
}

void printStudent(Student *head, char registration[10])
{
    Student *aux = head, *previous;

    for (aux; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->registration, registration) == 0)
        {
            printf("%s, %s, %d/%d/%d, %.2f\n", aux->registration, aux->name, aux->birth.day, aux->birth.month, aux->birth.year, aux->mean);
        }
    }
}

void printAllStudentsReverse(Student *head)
{
    if (head->next == NULL)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", head->registration, head->name, head->birth.day, head->birth.month, head->birth.year, head->mean);
        return;
    }

    Student *aux = head;

    printAllStudentsReverse(aux->next);
    printf("%s, %s, %d/%d/%d, %.2f\n", aux->registration, aux->name, aux->birth.day, aux->birth.month, aux->birth.year, aux->mean);
}

int listLength(Student *head)
{
    Student *aux = head;
    int elements = 0;

    for (aux; aux != NULL; aux = aux->next)
    {
        elements += 1;
    }

    return elements;
}

void clear(Student *head)
{
    if (head->next == NULL)
    {
        free(head);
        printf("-");
        return;
    }

    clear(head->next);

    free(head);
    printf("-");
}

int main()
{
    Student *head = NULL;
    char registration[REG_LENGTH];
    int op;

    while (op != 0)
    {
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            if (head != NULL) {
                clear(head);
            }
            exit(0);
        case 1:
            head = registerStudent(head);
            break;
        case 2:
            if (head == NULL)
            {
                printf("Lista Vazia!\n");
                break;
            }

            memset(registration, 0, REG_LENGTH);
            scanf("\n");
            fgets(registration, REG_LENGTH, stdin);
            registration[strlen(registration) - 1] = '\0';

            head = deleteStudent(head, registration);
            break;
        case 3:
            if (head == NULL)
            {
                printf("Lista Vazia!\n");
                break;
            }

            printAllStudents(head);
            break;
        case 4:
            if (head == NULL)
            {
                printf("Lista Vazia!\n");
                break;
            }

            printAllStudentsReverse(head);
            break;
        case 5:
            printf("%d\n", listLength(head));
            break;
        case 6:
            if (head == NULL)
            {
                printf("Lista Vazia!\n");
                break;
            }

            memset(registration, 0, REG_LENGTH);
            scanf("\n");
            fgets(registration, REG_LENGTH, stdin);
            registration[strlen(registration) - 1] = '\0';

            printStudent(head, registration);
            break;
        }
    }

    return 0;
}