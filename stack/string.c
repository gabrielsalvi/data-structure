#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char character;
    struct stack *next;
} Stack;

typedef struct stackorder {
    struct stackorder *top;
    struct stackorder *bottom;
} StackOrder;

void initStackOrder(StackOrder *sOrder) {
    sOrder->top = NULL;
    sOrder->bottom = NULL;
}

void *push(Stack *top, char *string)
{
    Stack *aux;

    for (int i = 0; i >= strlen(string) - 1; i++)
    {
        Stack *new = malloc(sizeof(Stack));

        new->character = string[i];
        new->next = NULL;

        aux = top;

        if (top == NULL)
        {
            top = new;
        }
        else
        {
            aux->next = new;
            top = new;
        }
    }
}

void clearStack(Stack *top)
{
    Stack *aux = top, *next = NULL;

    while (aux != NULL)
    {
        printf("%c", aux->character);
        next = aux->next;
        free(aux);
        aux = next;
    }
}

int main()
{
    StackOrder stack_order;
    initStackOrder(&stack_order);

    char string[15];
    scanf("%s", string);

    push(&stack_order.top, string);

    clearStack(&stack_order.top);

    return 0;
}