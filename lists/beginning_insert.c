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

    // new->next = first; In this case, the first will always be the last one of the list
    // first = new;

    new->next = first->next;
    first->next = new; // the first will awalys remain the first one of the list

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

    first = insertAtBeginning(first, 10);
    first = insertAtBeginning(first, 4);
    first = insertAtBeginning(first, 16);
    first = insertAtBeginning(first, 18);
    first = insertAtBeginning(first, 2);
    first = insertAtBeginning(first, 5);

    printList(first);

    return 0;
}