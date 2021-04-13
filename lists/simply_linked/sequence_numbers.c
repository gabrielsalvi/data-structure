#include <stdio.h>

struct intList
{
    int value;
    struct intList *next;
};
typedef struct intList IntList;

IntList *getLast(IntList *list) {
    IntList *last = list;

    for (last;last->next!=NULL;last=last->next);

    return last;
}

IntList *buildIntList(int length, int *v)
{
    IntList *list, *aux;

    for (int i = 0; i < length; i++)
    {
        IntList *new = malloc(sizeof(IntList));

        new->value = v[i];
        new->next = NULL;

        aux = list;

        if (list == NULL)
        {
            list = new;
        }
        else
        {
            aux = getLast(aux);
            aux->next = new;
        }
    }

    return list;
}

int main()
{
    IntList *list;
    int length, v[4] = {1, 21, 4, 6};

    length = sizeof(v) / sizeof(v[0]);

    list = buildIntList(length, v);

    IntList *aux = list;
    while (aux != NULL)
    {
        printf("%d -> ", aux->value);
        aux = aux->next;
    }

    return 0;
}