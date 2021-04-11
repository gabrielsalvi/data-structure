#include <stdio.h>

struct listaInt
{
    int valor;
    struct listaInt *proximo;
};
typedef struct listaInt ListaInt;

ListaInt *constroiLista(int length, int *v)
{
    ListaInt *lista, *auxiliar;

    for (int i = 0; i < length; i++)
    {
        ListaInt *novo = malloc(sizeof(ListaInt));

        novo->valor = v[i];
        novo->proximo = NULL;

        auxiliar = lista;

        if (lista == NULL)
        {
            lista = novo;
        }
        else
        {
            while (auxiliar->proximo != NULL)
            {
                auxiliar = auxiliar->proximo;
            }

            auxiliar->proximo = novo;
        }
        printf("novo: %d\n", novo->valor);
    }

    return lista;
}

int main()
{
    ListaInt *lista;
    int length, v[4] = {1, 21, 4, 6};

    length = sizeof(v) / sizeof(v[0]);

    lista = constroiLista(length, v);

    ListaInt *aux = lista;
    while (aux != NULL)
    {
        printf("%d -> ", aux->valor);
        aux = aux->proximo;
    }

    return 0;
}