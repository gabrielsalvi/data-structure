#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue
{
    char character;
    struct queue *next;
} Queue;

Queue *getLast(Queue *queue)
{
    Queue *last = queue;
    for (last; last->next != NULL; last = last->next);
    return last;
}

Queue *insertQueue(Queue *queue, char *string)
{
    Queue *aux;

    for (int i = 0; i < strlen(string); i++)
    {
        Queue *new = malloc(sizeof(Queue));

        new->character = string[i];
        new->next = NULL;

        aux = queue;

        if (queue == NULL)
        {
            queue = new;
        }
        else
        {
            aux = getLast(aux);
            aux->next = new;
        }
    }

    return queue;
}

Queue *clearQueue(Queue *queue)
{
    Queue *aux = queue, *next = NULL;

    while (aux != NULL)
    {
        printf("%c", aux->character);
        next = aux->next;
        free(aux);
        aux = next;
    }

    queue = NULL;

    return queue;
}

int main()
{
    Queue *queue = NULL;

    char string[15];
    printf("Type a string: ");
    scanf("%s", string);
    
    queue = insertQueue(queue, string);

    printf("Clearing the queue: ");
    queue = clearQueue(queue);

    return 0;
}