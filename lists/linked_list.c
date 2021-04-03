#include <stdio.h>

#define NAME_LENGTH 50

typedef struct
{
    int dia, mes, ano;
} Data;

struct funcionario
{
    int id;
    char nome[NAME_LENGTH];
    Data nascimento;
    double salario;
    struct funcionario *proximo;
};
typedef struct funcionario Funcionario;

void imprimeFuncionario(Funcionario *lista)
{
    Funcionario *aux = lista;
    while (aux != NULL)
    {
        int dia = aux->nascimento.dia;
        int mes = aux->nascimento.mes;
        int ano = aux->nascimento.ano;

        printf("\nFuncionario: \n");
        printf("\t-> ID: %d\n", aux->id);
        printf("\t-> Nome: %s", aux->nome);
        printf("\t-> Data de Nascimento: %d/%d/%d\n", dia, mes, ano);
        printf("\t-> Salario: R$ %.2f\n", aux->salario);

        aux = aux->proximo;
    }
}

Funcionario *criarFuncionario(Funcionario *lista)
{
    Funcionario *funcionario = malloc(sizeof(Funcionario)), *aux;

    printf("\n-> Insira um funcionario: \n");
    scanf("\n");
    fgets(funcionario->nome, sizeof(funcionario->nome), stdin);
    scanf("%d/%d/%d", &funcionario->nascimento.dia, &funcionario->nascimento.mes, &funcionario->nascimento.ano);
    scanf("%lf", &funcionario->salario);

    if (lista == NULL)
    {
        funcionario->id = 1;
        funcionario->proximo = NULL;
        return funcionario;
    }

    funcionario->proximo = lista;
    funcionario->id = lista->id + 1;

    lista = funcionario;

    return lista;
}

Funcionario *deletarFuncionario(Funcionario *lista, int id)
{
    Funcionario *aux = lista, *anterior = NULL;

    for (aux; aux != NULL; aux = aux->proximo)
    {
        if (aux->id == id)
        {
            if (aux == lista)
            {
                lista = lista->proximo;
            }
            else
            {
                anterior->proximo = aux->proximo;
            }
            free(aux);
        }
        anterior = aux;
    }

    printf("Funcionario nao encontrado!\n");
    return lista;
}

int main()
{
    Funcionario *lista = NULL;

    lista = criarFuncionario(lista);
    lista = criarFuncionario(lista);
    lista = criarFuncionario(lista);

    imprimeFuncionario(lista);

    lista = deletarFuncionario(lista, 4);

    imprimeFuncionario(lista);

    return 0;
}
