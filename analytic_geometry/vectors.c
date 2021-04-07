#include <stdio.h>
#include <stdlib.h>

struct _vector
{
    int x, y, z;
    struct _vector *next;
};
typedef struct _vector Vector;

Vector *initializeVector(Vector *head)
{
    Vector *new = malloc(sizeof(Vector));

    printf("\n-> Type the values of the vector(x, y, z):\n");
    scanf("\n");
    scanf("%d %d %d", &new->x, &new->y, &new->z);

    if (head == NULL)
    {
        new->next = NULL;
        return new;
    }

    new->next = head;
    head = new;

    return head;
}

void printVectors(Vector *head)
{
    Vector *aux;

    if (head == NULL)
    {
        return;
    }

    for (aux = head; aux != NULL; aux = aux->next)
    {
        printf("(x: %d, y: %d, z: %d)\n", aux->x, aux->y, aux->z);
    }
}

void paralelos()
{
    int vectors = 0;

    printf("\nComparation between how many vectors? - ");
    scanf("%d", &vectors);

    if (vectors < 2)
    {
        printf("\nIt's necessary at least 2 vectors to compare!\n");
        option();
    }

    Vector *head = NULL;

    for (int i = 0; i < vectors; i++)
    {
        printVectors(head);
        head = initializeVector(head);
    }
}

void ortogonais()
{
    int vectors = 0;

    printf("\nComparation between how many vectors? - ");
    scanf("%d", &vectors);

    if (vectors < 2)
    {
        printf("\nIt's necessary at least 2 vectors to compare!\n");
        option();
    }

    Vector *head = NULL;

    for (int i = 0; i < vectors; i++)
    {
        head = initializeVector(head);
    }

    Vector *calc;
    int cont = 0;

    // for (Vector *aux = head; aux->next != NULL; aux = aux->next)
    // {
    //     if (cont > 0)
    //     {
    //         calc->x = calc->x * (aux->x * aux->next->x);
    //         calc->y = calc->y * (aux->y * aux->next->y);
    //         calc->z = calc->z * (aux->z * aux->next->z);
    //     } else {
    //         calc->x = aux->x * aux->next->x;
    //         calc->y = aux->y * aux->next->y;
    //         calc->z = aux->z * aux->next->z;
    //     }

    //     printVectors(calc);
    //     cont = cont + 1;
    // }

    printVectors(head);
}

void option()
{
    Vector *vector = NULL;
    int typed = 0;

    printf("\nType:\n1- Paralelos\n2- Ortogonais\n");
    scanf("%d", &typed);

    if (typed == 1)
        paralelos(vector);
    else if (typed == 2)
        ortogonais(vector);
    else
        return;
}

int main()
{
    //ortogonais(vector);
    option();

    return 0;
}