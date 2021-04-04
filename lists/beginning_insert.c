#include <stdio.h>

struct list
{
    int number;
    struct list *next;
};
typedef struct list List;

List *createNewElement()
{
    List *new = (List *)malloc(sizeof(List));
    return new;
}

List* insertAtBeginning(List* head, int number)
{
    List *new = createNewElement();

    new->number = number;

    if (head == NULL)
    {
        head = new;
        new->next = NULL;
    }
    else
    {
        new->next = head;
        head = new;
    }

    return head;
}

void printList(List *head) {
    List *aux = head;
    
    while(aux != NULL) {
        printf("%d -> ", aux->number);
        aux = aux->next;
    }
    printf("\n");
}

int main()
{
    List *head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 4);
    head = insertAtBeginning(head, 16);
    
    printList(head);

    return 0;
}