#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_item
{
    char character;
    struct stack_item *next;
} StackItem;

typedef struct stack {
    StackItem *top;
    StackItem *bottom;
} Stack;

void initStack(Stack *stack) {
    stack->top = NULL;
    stack->bottom = NULL;
}

void push(Stack *stack, char *string)
{
    StackItem *aux;

    for (int i = 0; i >= strlen(string) - 1; i++)
    {
        StackItem *new = malloc(sizeof(StackItem));

        new->character = string[i];
        new->next = NULL;

        aux = stack;

        if (stack == NULL)
        {
            stack = new;
        }
        else
        {
            aux->next = new;
            stack = new;
        }
    }
}

void clearStack(Stack *stack)
{
    StackItem *aux = stack, *next = NULL;

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
    Stack stack_order;
    initStack(&stack_order);

    char string[15];
    scanf("%s", string);

    push(&stack_order.top, string);

    clearStack(&stack_order.top);

    return 0;
}