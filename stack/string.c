#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char character;
    struct stack *next;
} Stack;

Stack *getLast(Stack *stack)
{
    Stack *last = stack;
    for (last; last->next != NULL; last = last->next);
    return last;
}

Stack *push(Stack *stack, char *string)
{
    Stack *aux;

    for (int i = strlen(string) - 1; i >= 0; i--)
    {
        Stack *new = malloc(sizeof(Stack));

        new->character = string[i];
        new->next = NULL;

        aux = stack;

        if (stack == NULL)
        {
            stack = new;
        }
        else
        {
            aux = getLast(aux);
            aux->next = new;
        }
    }

    return stack;
}

void clearStack(Stack *stack)
{
    Stack *aux = stack, *next = NULL;

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
    Stack *stack = NULL;

    char string[15];
    scanf("%s", string);

    stack = push(stack, string);

    clearStack(stack);

    return 0;
}