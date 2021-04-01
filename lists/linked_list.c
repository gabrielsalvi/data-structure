/* Crie as estruturas indicadas, e crie o primeiro funcionário da lista;
Adicione um segundo funcionário ao início da lista;
Crie uma função capaz de imprimir todos os funcionários; */

#include <stdio.h>

typedef struct
{
    int dia, mes, ano;
} Data;

struct funcionario
{
    int id;
    char nome[41];
    double salario;
    Data nascimento;
    struct funcionario *proximo;
};
typedef struct funcionario Funcionario;

Data createDate(int d, int m, int y)
{
    Data date = {d, m, y};

    return date;
}

void imprimeFuncionario(Funcionario *lista)
{
    Funcionario *aux = lista;

    while (aux != NULL)
    {
        int dia = aux->nascimento.dia;
        int mes = aux->nascimento.mes;
        int ano = aux->nascimento.ano;

        printf("id: %d | nome: %s | salario: R$ %.2lf | nascimento: %d/%d/%d\n", aux->id, aux->nome, aux->salario, dia, mes, ano);

        aux = aux->proximo;
    }

    printf("\n");
}

Funcionario *criarFuncionario(Funcionario *lista, int id, char *name, Data nascimento, double salario)
{
    Funcionario *funcionario = malloc(sizeof(Funcionario));
    funcionario->id = id;
    snprintf(funcionario->nome, 41, name);
    funcionario->nascimento = nascimento;
    funcionario->salario = salario;

    if (lista == NULL)
    {
        lista = funcionario;
        funcionario->proximo = NULL;
    }
    else
    {
        funcionario->proximo = lista;
        lista = funcionario;
    }

    return lista;
}

Funcionario *deletarFuncionario(Funcionario *lista, int id)
{
    Funcionario *aux = lista, *anterior;

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
            return lista;
        }
        anterior = aux;
    }

    printf("Funcionario não encontrado!");
}

int main()
{
    Funcionario *lista = NULL;

    lista = criarFuncionario(lista, 1, "Yato", createDate(15, 10, 1995), 500.0);
    lista = criarFuncionario(lista, 2, "Satoru Gojo", createDate(8, 2, 1987), 10000.0);
    lista = criarFuncionario(lista, 3, "Eren Yeager", createDate(7, 12, 2003), 1200.0);

    imprimeFuncionario(lista);

    lista = deletarFuncionario(lista, 2);

    imprimeFuncionario(lista);

    return 0;
}
