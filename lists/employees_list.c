#include <stdio.h>

#define NAME_LENGTH 50

typedef struct
{
    int day, month, year;
} Data;

struct employee
{
    int id;
    char name[NAME_LENGTH];
    Data birth;
    double salary;
    struct employee *next;
};
typedef struct employee Employee;

struct intList
{
    int value;
    struct intList *next;
};
typedef struct intList IntList;

void printEmployee(Employee *list)
{
    Employee *aux = list;

    printf("\nEmployees List:\n");

    while (aux != NULL)
    {
        int day = aux->birth.day;
        int month = aux->birth.month;
        int year = aux->birth.year;

        printf("\n\t-> ID: %d\n", aux->id);
        printf("\t-> Name: %s", aux->name);
        printf("\t-> Birth Date: %d/%d/%d\n", day, month, year);
        printf("\t-> Salary: R$%.2f\n", aux->salary);

        aux = aux->next;
    }
}

Employee *registerEmployee(Employee *list)
{
    Employee *employee = malloc(sizeof(Employee));

    printf("\n-> Register an employee: \n");
    scanf("\n");
    fgets(employee->name, sizeof(employee->name), stdin);
    scanf("%d/%d/%d", &employee->birth.day, &employee->birth.month, &employee->birth.year);
    scanf("%lf", &employee->salary);

    if (list == NULL)
    {
        employee->id = 1;
        employee->next = NULL;
        return employee;
    }

    employee->next = list;
    employee->id = list->id + 1;

    list = employee;

    return list;
}

Employee *deleteEmployee(Employee *list, int id)
{
    Employee *aux = list, *anterior = NULL;

    for (aux; aux != NULL; aux = aux->next)
    {
        if (aux->id == id)
        {
            if (aux == list)
            {
                list = list->next;
            }
            else
            {
                anterior->next = aux->next;
            }

            printf("\nThe employee has been deleted! (ID: %d)\n", aux->id);
            free(aux);

            return list;
        }
        anterior = aux;
    }

    printf("\nNo employee with id = '%d' was found!\n", id);
    return list;
}

IntList *buildIntList(int length, int *v)
{
    IntList *list, *aux;

    for (int i = 0; i < length; i++)
    {
        IntList *new = malloc(sizeof(IntList));

        new->value = v[i];
        new->next = NULL;

        aux = list;

        if (list == NULL)
        {
            list = new;
        }
        else
        {
            while (aux->next != NULL)
            {
                aux = aux->next;
            }

            aux->next = new;
        }
    }

    return list;
}

int main()
{
    // Employee *list = NULL;
    // int num_employees;

    // printf("How many employees do you want to register? -> ");
    // scanf("%d", &num_employees);

    // for (int i = 0; i < num_employees; i++)
    // {
    //     list = registerEmployee(list);
    // }

    // printEmployee(list);

    // list = deleteEmployee(list, 3);

    // printEmployee(list);

    IntList *int_list;
    int length, v[4] = {1, 21, 4, 6};

    length = sizeof(v) / sizeof(v[0]);

    int_list = buildIntList(length, v);

    IntList *aux = int_list;
    while (aux != NULL)
    {
        printf("%d -> ", aux->value);
        aux = aux->next;
    }

    return 0;
}