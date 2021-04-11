#include <stdio.h>
#include <stdlib.h>

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
    Employee *employee = (Employee *)malloc(sizeof(Employee));

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

int listLength(Employee *employee)
{
    Employee *aux = employee;
    int elements = 0;

    while (aux != NULL)
    {
        elements += 1;
        aux = aux->next;
    }

    return elements;
}

double lowerSalary(Employee *employee)
{
    Employee *aux = employee;
    double lower = employee->salary;

    while (aux != NULL)
    {
        if (aux->salary < lower)
        {
            lower = aux->salary;
        }
        aux = aux->next;
    }

    return lower;
}

Employee *olderEmployee(Employee *employee)
{
    Employee *older = employee;
    Employee *aux = employee->next;

    if (listLength(employee) <= 1)
    {
        return employee;
    }

    while (aux->next != NULL)
    {
        if (older->birth.year > aux->birth.year)
        {
            older = aux;
        }
        else if (older->birth.year == aux->birth.year)
        {
            if (older->birth.month > aux->birth.month)
            {
                older = aux;
            }
            else if (older->birth.month == aux->birth.month)
            {
                if (older->birth.day > aux->birth.day)
                {
                    older = aux;
                }
            }
        }
        aux = aux->next;
    }

    return older;
}

int compareLists(Employee *list, Employee *list2)
{
    if (list->next == NULL && list2->next == NULL)
    {
        return 1;
    }
    else if (list->next == NULL || list2->next == NULL)
    {
        return 0;
    }

    Employee *i, *j;

    for (i=list, j=list2; i->next != NULL && j->next != NULL; i=i->next, j=j->next) {
        if(i->id != j->id) {
            return 0;
        }
    }

    return 1;
}

Employee *printReverseList(Employee *list)
{
    if (list == NULL)
    {
        return;
    }

    printReverseList(list->next);

    int day = list->birth.day;
    int month = list->birth.month;
    int year = list->birth.year;

    printf("\n\t-> ID: %d\n", list->id);
    printf("\t-> Name: %s", list->name);
    printf("\t-> Birth Date: %d/%d/%d\n", day, month, year);
    printf("\t-> Salary: R$%.2f\n", list->salary);
}

int main()
{
    Employee *list = NULL;
    int num_employees;

    printf("How many employees do you want to register? -> ");
    scanf("%d", &num_employees);

    for (int i = 0; i < num_employees; i++)
    {
        list = registerEmployee(list);
    }

    printEmployee(list);
    
    Employee *list2 = list;
    list2 = deleteEmployee(list, 3);

    printf("The lists are equal? (no = 0/ yes = 1) -> %d", compareLists(list, list2));

    printEmployee(list2);
    printReverseList(list);

    // IntList *int_list;
    // int length, v[4] = {1, 21, 4, 6};

    // length = sizeof(v) / sizeof(v[0]);

    // int_list = buildIntList(length, v);

    // IntList *aux = int_list;
    // while (aux != NULL)
    // {
    //     printf("%d -> ", aux->value);
    //     aux = aux->next;
    // }

    return 0;
}