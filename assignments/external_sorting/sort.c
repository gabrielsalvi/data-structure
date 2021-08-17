#include <stdio.h>
#include <stdlib.h>

#define BLC_MEMORIA 4
#define N_VALUES 31
#define N_FILES 4

// funções
void checkFile(FILE *file, char *filename);
FILE *combinaBlocos(FILE *arqEnt[], int blocoId, int iter);
void externalSort(FILE *file);
void merge(int *A, int p, int q, int r);
void mergeSort(int *A, int p, int r);

// -----

int main () 
{
    FILE *input = fopen("input.txt", "r+");
    checkFile(input, "input.txt");
    
    externalSort(input);

    // le do arquivo ordenado para a memoria e exibe
    int *mAg = (int *)malloc(sizeof(int) * N_VALUES);
    fseek(input, 0, SEEK_SET);
    fread(mAg, sizeof(int), N_VALUES, input);
    printf("\n\n\nDepois da ordenacao: \n");
    
    int i;
    for (i = 0; i < N_VALUES; i++) 
    {
        printf("-> %d \n", mAg[i]);
    }

    return 0;
}

void checkFile(FILE *file, char *filename) 
{
    if (!file) 
    {
        printf("Não foi possível abrir ou criar o arquvivo %s\n", filename);
        exit(1);
    }
}

void merge(int *A, int p, int q, int r){ // funcao de intercalacao do mergesort em memoria principal
    int i, j, k;
    int B[r - p];
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r)
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i < q)
        B[k++] = A[i++];
    while (j < r)
        B[k++] = A[j++];
    for (i = p; i < r; ++i)
        A[i] = B[i - p];
}

void mergeSort(int *A, int p, int r) {
    if (p < r - 1) {
        int q = (int)(p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q, r);
        merge(A, p, q, r);
    }
}

void swap(int *i, int *k)
{
    int aux = *i;
    
    *i = *k;
    *k = aux;
}

int partition(int *array, int start, int end)
{
    int k = start, pivot_pos = end;

    for (int i = start; i < end; i++)
    {
        if (array[i] <= array[pivot_pos])
        {
            swap(&array[i], &array[k]);

            k++;
        }
    }

    if (array[k] > array[pivot_pos])
    {
        swap(&array[k], &array[pivot_pos]);
        pivot_pos = k;
    }

    return pivot_pos;
}

void quickSort(int *array, int start, int end)
{
    if (start < end)
    {
        int pivot_pos = partition(array, start, end);

        quickSort(array, start, pivot_pos - 1);
        quickSort(array, pivot_pos + 1, end);
    }
}

void externalSort(FILE *file) 
{
    FILE *auxFiles[N_FILES];

    int *intBloco = malloc(sizeof(int) * BLC_MEMORIA);
    int size;

    //Primeira fase: ler os dados e colocar nos diferentes arquivos (classificacao)
    for (int i = 0; i < N_FILES; i++) {
        char fileName[40];
        snprintf(fileName, 40, "%s-%d.aux", "arquivo", i+1);
        auxFiles[i] = fopen(fileName, "w+b");
    }

    size = fread(intBloco, sizeof(int), BLC_MEMORIA, file);

    int i = 0;
    while (size > 0) {
        // ordena bloco na memoria principal usando merge sort
        mergeSort(intBloco, 0, size);
        fwrite(intBloco, sizeof(int), size, auxFiles[i % N_FILES]);
        i++;
        size = fread(intBloco, sizeof(int), BLC_MEMORIA, file);
    }

    int numBloco = (i + 1) / N_FILES;

    //Segunda fase: intercalação
    FILE **arquivosEntrada = auxFiles; // a primeira entrada sao os arquivos gerados pela etapa de classificacao
    FILE **arquivosSaida;

    int iteracao = 0;
    while (numBloco > 0) 
    {
        arquivosSaida = (FILE **)malloc(sizeof(FILE *) * numBloco);

        for (int j = 0; j < numBloco; j++) 
        {
            arquivosSaida[j] = combinaBlocos(arquivosEntrada, j + 1, iteracao);
        }

        numBloco = numBloco / N_FILES;
        arquivosEntrada = arquivosSaida; // a saida vira a entrada da proxima etapa

        iteracao++;
    }

    //Terminou intercalacoes; copia do ultimo arquivo de merge de volta para o arquivo inicial
    fseek(file, 0, SEEK_SET);
    fseek(arquivosSaida[0], 0, SEEK_SET);

    size = fread(intBloco, sizeof(int), BLC_MEMORIA, arquivosSaida[0]);

    while (size > 0) 
    {
        fwrite(intBloco, sizeof(int), size, file);
        size = fread(intBloco, sizeof(int), BLC_MEMORIA, arquivosSaida[0]);
    }
}

FILE *combinaBlocos(FILE *arqEnt[], int blocoId, int iter) 
{
    char fileName[40];
    snprintf(fileName, 40, "%s-%d-it%d.aux", "merge", blocoId, iter);

    FILE *resposta = fopen(fileName, "w+b");

    int i, *counter = calloc(N_FILES, sizeof(int));

    for (i = 0; i < N_FILES; i++)
        fseek(arqEnt[i], (blocoId - 1) * BLC_MEMORIA * sizeof(int), SEEK_SET); // desloca o cursor do arquivo para o inicio da coluna que esta sendo intercalada

    int *auxRead = malloc(sizeof(int) * N_FILES);
    int *lidos = calloc(N_FILES, sizeof(int));

    int bool = 1;
    while (bool) {
        int candidatoEscrita = -1;

        //Le um elemento de cada arquivo
        for (i = 0; i < N_FILES; i++) {
            int readSize = -1;
            if (!lidos[i] && counter[i] < (blocoId * BLC_MEMORIA * (iter + 1))) {
                readSize = fread(&auxRead[i], sizeof(int), 1, arqEnt[i]);
                lidos[i]++;
            }
            if (readSize == 0) {
                lidos[i] = -1; // Nao leu ninguem; chegou ao final do arquivo
            }
            if (candidatoEscrita < 0 && lidos[i] > 0) 
            {
                candidatoEscrita = i;
            }
        }

        for (i = 1; i < N_FILES; i++) 
        {
            if (lidos[i] > 0) 
            {
                if (auxRead[i] < auxRead[candidatoEscrita]) // compara para encontrar o menor dos registros e decidir quem sera copiado para a saida
                { 
                    candidatoEscrita = i;
                }
            }
        }

        if (candidatoEscrita < 0) 
        {
            break;
        }

        fwrite(&auxRead[candidatoEscrita], sizeof(int), 1, resposta); // grava o menor elemento no arquivo de saida

        lidos[candidatoEscrita] = 0;
        counter[candidatoEscrita]++;

        int soma = 0, endedFiles = 0;
        for (i = 0; i < N_FILES; i++) 
        {
            soma += counter[i];

            if (feof(arqEnt[i])) 
            {
                endedFiles++;
            }
        }

        if (soma >= BLC_MEMORIA * N_FILES * (iter + 1)) { 
            bool = 0;
        }
    }

    return resposta;
}