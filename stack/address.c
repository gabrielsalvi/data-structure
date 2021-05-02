#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_item
{
    char address[60];
    struct stack_item *down;
} StackItem;

typedef struct
{
    StackItem *top;
    StackItem *bottom;
} Stack;

void initStack(Stack *stack)
{
    stack->top = NULL;
    stack->bottom = NULL;
}

void push(Stack *stack, char *address)
{
    StackItem *new = (StackItem *)malloc(sizeof(StackItem));

    strcpy(new->address, address);
    new->down = NULL;

    if (stack->top == NULL)
    {
        stack->top = new;
        stack->bottom = new;
    }
    else
    {
        new->down = stack->top;
        stack->top = new;
    }
}

void pop(Stack *stack)
{
    printf("%s\n", stack->top->address);

    if (stack->top == stack->bottom)
    {
        free(stack->top);
        initStack(stack);
    }
    else
    {
        StackItem *delete = NULL;

        delete = stack->top;
        stack->top = stack->top->down;

        free(delete);
    }
}

void clearStack(Stack *stack)
{
    StackItem *delete = NULL;

    while (stack->top != NULL)
    {
        delete = stack->top;
        stack->top = stack->top->down;
        free(delete);

        if (stack->top != NULL)
        {
            printf("@");
        }
        else
        {
            printf("@\n");
            initStack(stack);
        }
    }
}

int main()
{
    Stack stack;
    initStack(&stack);

    char string[60];

    do
    {
        scanf("%s", string);

        if (strcmp(string, "B") == 0)
        {
            if (stack.top == NULL)
            {
                printf("Vazio\n");
            }
            else
            {
                pop(&stack);
            }
        }
        else if (strcmp(string, "E") == 0)
        {
            if (stack.top == NULL)
            {
                printf("!\n");
            }
            else
            {
                clearStack(&stack);
            }
        }
        else
        {
            push(&stack, string);
        }

    } while (strcmp(string, "E") != 0);

    return 0;
}