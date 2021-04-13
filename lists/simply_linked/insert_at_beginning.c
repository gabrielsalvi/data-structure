#include <stdio.h>

struct list
{
    int number;
    struct list *next;
};
typedef struct list List;

List *createNewElement()
{
    List *new = malloc(sizeof(List));
    return new;
}

List *insertAtBeginning(List *first, int number)
{
    List *new = createNewElement();

    new->number = number;

    if (first == NULL)
    {
        new->next = NULL;
        return new;
    }

    // The first will always be the last one of the list
    new->next = first; 
    first = new;

    // The first will awalys remain the first one of the list
    // new->next = first->next;
    // first->next = new;

    return first;
}

void printList(List *first)
{
    List *aux = first;

    while (aux != NULL)
    {
        printf("%d -> ", aux->number);
        aux = aux->next;
    }
    printf("\n");
}

int main()
{
    List *first = NULL;
    int number;

    printf("Count from x to zero. x = ");
    scanf("\n%d", &number);

    for (int i = 0; i <= number; i++)
    {
        first = insertAtBeginning(first, i);
    }

    printList(first);

}
