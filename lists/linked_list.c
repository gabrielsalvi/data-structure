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

Data createDate(int d, int m, int a)
{
    Data date = {d, m, a};

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

        printf("id: %d | name: %s | salario: R$ %.2lf | nascimento: %d/%d/%d\n", aux->id, aux->nome, aux->salario, dia, mes, ano);

        aux = aux->proximo;
    }
}

Funcionario* createFuncionario(Funcionario *lista, int cont, char *name, Data nascimento, double salario)
{
    Funcionario *funcionario = malloc(sizeof(Funcionario));
    funcionario->id = cont;
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

int main()
{
    Funcionario *lista = NULL;

    lista = createFuncionario(lista, 1, "Killua", createDate(15, 10, 2001), 3000.0);
    lista = createFuncionario(lista, 2, "Gojou", createDate(8, 2, 1979), 10000.0);

    imprimeFuncionario(lista);

    return 0;
}
