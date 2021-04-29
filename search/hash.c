#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXELE 20
#define OVERFLOW 5

typedef struct
{
    int id;
    char name[41];
    double salary;
    int age;
} Employee;

int hash(int key)
{
    return key % MAXELE;
}

void initHashTable(Employee *hashTable)
{
    for (int i = 0; i < MAXELE + OVERFLOW; i++)
    {
        Employee employee;

        employee.id = -1;
        strcpy(employee.name, "");
        employee.salary = -1.0;
        employee.age = -1;

        hashTable[i] = employee;
    }
}

Employee readEmployee(Employee employee)
{
    printf("Id: ");
    scanf("%d", &employee.id);

    printf("Nome: ");
    scanf("%s", employee.name);

    printf("Salário: ");
    scanf("%lf", &employee.salary);

    printf("Idade: ");
    scanf("%d", &employee.age);

    return employee;
}

void insertEmployee(Employee *hashTable)
{
    Employee employee = readEmployee(employee);

    int index = hash(employee.age);

    if (hashTable[index].age == -1)
    {
        hashTable[index] = employee;
    }
    else
    {
        for (int i = MAXELE; i < (MAXELE + OVERFLOW); i++)
        {
            if (hashTable[i].age == -1)
            {
                hashTable[i] = employee;
                return;
            }
        }

        printf("\nA área de overflow está lotada!\n");
    }
}

void printEmployee(Employee employee, int index)
{
    if (employee.age != -1)
    {
        printf("%d: %d, %s, R$%.2lf, %d\n", index, employee.id, employee.name, employee.salary, employee.age);
    }
    else
    {
        printf("%d: Free Slot\n", index);
    }
}

void searchHashTable(Employee *hashTable, int age)
{
    int index = hash(age);

    printEmployee(hashTable[index], index);

    // busca linear na área de overflow
    for (int i = MAXELE; i < (MAXELE + OVERFLOW); i++)
    {
        if (hashTable[i].age == age)
        {
            printEmployee(hashTable[i], i);
        }
    }
}

void listHashTable(Employee *hashTable)
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < MAXELE; i++)
    {
        printEmployee(hashTable[i], i);
    }

    printf("\nOverflow:\n");

    for (i = MAXELE; i < MAXELE + OVERFLOW; i++)
    {
        printEmployee(hashTable[i], i);
    }
}

int main()
{
    Employee hashTable[MAXELE + OVERFLOW];
    initHashTable(hashTable);

    int op, age;

    do
    {
        printf("\nMenu: 0- Sair; 1- Inserir; 2- Consultar; 3- Mostrar Hash Table;\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("\nPrograma Encerrado!\n");
            break;

        case 1:
            insertEmployee(hashTable);
            break;

        case 2:
            printf("Idade: ");
            scanf("%d", &age);
            
            searchHashTable(hashTable, age);
            break;

        case 3:
            listHashTable(hashTable);
            break;
        }
    } while (op != 0);

    return 0;
}