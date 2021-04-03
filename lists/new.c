#include <stdio.h>

struct listaInt
{
    int valor;
    struct listaInt *proximo;
};
typedef struct listaInt ListaInt;

ListaInt *constroiLista(int length, int *v)
{
    ListaInt *lista = NULL;
    ListaInt *novo = malloc(sizeof(ListaInt)), *auxiliar, *ultimo;
    
    for (int i = 0; i < length; i++)
    {   
        novo->valor = v[i];
        novo->proximo = NULL;

        if (lista == NULL)
        {
            lista = novo;
            printf("novo: %d\n", novo->valor);
        }
        else
        {   
            auxiliar = lista;
            while (auxiliar->proximo != NULL)
            {   
                auxiliar = auxiliar->proximo;
            }

            novo->valor = v[i];
            novo->proximo = NULL;
            auxiliar->proximo = novo;
            lista = auxiliar;
            
            printf("novo: %d\n", novo->valor);
        }
        
        printf("ultimo: %d\n", ultimo->valor);
    }

    return lista;
}

int main()
{
    int v[4] = {1, 21, 4, 6};

    ListaInt *lista = constroiLista(4, v);

    ListaInt *aux = lista;
    while (aux != NULL)
    {
        printf("%d, ", aux->valor);
        aux = aux->proximo;
    }

    return 0;
}