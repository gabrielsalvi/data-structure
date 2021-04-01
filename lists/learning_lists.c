#include <stdio.h>

struct no
{
    int num;
    struct no *prox;
};
typedef struct no No;

No *criarNo()
{
    No *novo = (No *)malloc(sizeof(No));
    return novo;
}

No* inserir_no_inicio(No* lista, int dado)
{
    No *novo = criarNo();

    novo->num = dado;

    if (lista == NULL)
    {
        lista = novo;
        novo->prox = NULL;
    }
    else
    {
        novo->prox = lista;
        lista = novo;
    }

    return lista;
}

void imprimeLista(No *lista) {
    No *aux = lista;
    
    while(aux != NULL) {
        printf("%d\n", aux->num);
        aux = aux->prox;
    }
}

int main()
{
    No *lista = NULL;

    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 4);
    lista = inserir_no_inicio(lista, 16);
    imprimeLista(lista);

    return 0;
}