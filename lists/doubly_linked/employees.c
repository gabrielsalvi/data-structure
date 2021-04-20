#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 40

typedef struct
{
    int day, month, year;
} Data;

typedef struct employee
{
    int id;
    char name[NAME_LENGTH];
    Data birth;
    double salary;
    struct employee *previous;
    struct employee *next;
} Employee;

Employee *getLast(Employee *list)
{
    Employee *last = list;
    for (last; last->next != NULL; last = last->next)
        ;
    return last;
}

Employee *registerEmployee(Employee *list)
{
    Employee *employee = (Employee *)malloc(sizeof(Employee)), *aux;

    printf("\n-> Register an employee (name, dd/mm/yyyy, salary): \n");
    scanf("\n");
    fgets(employee->name, sizeof(employee->name), stdin);
    scanf("%d/%d/%d", &employee->birth.day, &employee->birth.month, &employee->birth.year);
    scanf("%lf", &employee->salary);
    employee->previous = NULL;
    employee->next = NULL;

    if (list == NULL)
    {
        employee->id = 1;
        return employee;
    }
    else
    {
        aux = getLast(list);

        employee->id = aux->id + 1;
        employee->previous = aux;
        aux->next = employee;
    }

    return list;
}

Employee *deleteEmployee(Employee *list, int id)
{
    if (list == NULL)
    {
        printf("Lista Vazia!\n");
        return;
    }

    for (Employee *aux = list; aux != NULL; aux = aux->next)
    {
        if (aux->id == id)
        {
            if (aux == list)
            {
                list = list->next;
                list->previous = NULL;
            }
            if (aux->next == NULL)
            {
                aux->previous->next = NULL;
            }
            else
            {
                aux->previous->next = aux->next;
                aux->next->previous = aux->previous;
            }

            printf("\nThe employee has been deleted! (ID: %d)\n", aux->id);
            free(aux);

            return list;
        }
    }

    printf("\nNo employee with id = '%d' was found!\n", id);
    return list;
}

void printEmployees(Employee *list)
{
    if (list == NULL)
    {
        printf("Lista Vazia!\n");
        return;
    }

    Employee *aux = list;

    while (aux != NULL)
    {
        printf("\n\t-> ID: %d\n", aux->id);
        printf("\t-> Name: %s", aux->name);
        printf("\t-> Birth Date: %02d/%02d/%d\n", aux->birth.day, aux->birth.month, aux->birth.year);
        printf("\t-> Salary: R$%.2f\n", aux->salary);

        aux = aux->next;
    }
}

void printEmployeesInversely(Employee *list)
{
    if (list == NULL)
    {
        printf("Lista Vazia!\n");
        return;
    }

    if (list->next == NULL)
    {
        printEmployee(list, list->id);
        return;
    }

    Employee *aux = list;

    printEmployeesInversely(aux->next);

    printf("\n\t-> ID: %d\n", aux->id);
    printf("\t-> Name: %s", aux->name);
    printf("\t-> Birth Date: %02d/%02d/%d\n", aux->birth.day, aux->birth.month, aux->birth.year);
    printf("\t-> Salary: R$%.2f\n", aux->salary);
}

void printEmployee(Employee *head, int id)
{
    if (head == NULL)
    {
        printf("Lista Vazia!\n");
        return;
    }

    Employee *aux = head;

    for (aux; aux != NULL; aux = aux->next)
    {
        if (aux->id == id)
        {
            printf("\n\t-> ID: %d\n", aux->id);
            printf("\t-> Name: %s", aux->name);
            printf("\t-> Birth Date: %02d/%02d/%d\n", aux->birth.day, aux->birth.month, aux->birth.year);
            printf("\t-> Salary: R$%.2f\n", aux->salary);

            return;
        }
    }
}

int listLength(Employee *list)
{
    if (list == NULL)
    {
        return 0;
    }

    return 1 + listLength(list->next);
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

    for (i = list, j = list2; i->next != NULL && j->next != NULL; i = i->next, j = j->next)
    {
        if (i->id != j->id)
        {
            return 0;
        }
    }

    return 1;
}

void clear(Employee *head)
{
    if (head->next == NULL)
    {
        free(head);
        return;
    }

    clear(head->next);

    free(head);
}

int main()
{
    Employee *list = NULL;
    int id = 0;
    int op = 0;

    while (1)
    {
        printf("\nMenu: 0- exit; 1- insert; 2- delete; 3- print all employees; 4- print employees inversely; 5- print an employee; 6- older employee; 7- lower salary; 8- list length;\n");
        scanf("%d", &op);

        switch (op)
        {

        case 0:
            if (list != NULL)
            {
                clear(list);
            }

            exit(0);

        case 1:
            list = registerEmployee(list);
            break;

        case 2:
            printf("\nType the id to delete the employee: -> ");
            scanf("%d", &id);

            list = deleteEmployee(list, id);
            break;

        case 3:
            printEmployees(list);
            break;

        case 4:
            printEmployeesInversely(list);
            break;

        case 5:
            printf("\nType the id to print the employee -> ");
            scanf("%d", &id);

            printEmployee(list, id);
            break;

        case 6:
            printf("\nThis is the older employee:\n");
            printEmployee(list, olderEmployee(list)->id);
            break;

        case 7:
            printf("\nThe lower salary is %.2f!\n", lowerSalary(list));
            break;

        case 8:
            printf("\nThe employee list has %d elements!\n", listLength(list));
            break;
        }
    }

    return 0;
}
