#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_item
{
    char character;
    struct stack_item *down;
} StackItem;

typedef struct
{
    StackItem *top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = NULL;
}

void push(Stack *stack, char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        StackItem *new = malloc(sizeof(StackItem));

        new->character = string[i];
        new->down = NULL;

        if (stack->top == NULL)
        {
            stack->top = new;
        }
        else
        {
            new->down = stack->top;
            stack->top = new;
        }
    }
}

void clearStack(Stack *stack)
{
    StackItem *previous;

    while (stack->top != NULL)
    {
        printf("%c", stack->top->character);

        previous = stack->top->down;
        free(stack->top);
        stack->top = previous;
    }
}

int main()
{
    Stack stack;
    initStack(&stack);

    char string[15];
    printf("Type a string: ");
    scanf("%s", string);

    push(&stack, string);

    printf("Clearing stack: ");
    clearStack(&stack);

    return 0;
}