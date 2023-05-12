#ifndef GRAFO_H

#define GRAFO_H

#include <list>
#include <vector>
#include "Aresta.h"

using namespace std;

class Grafo {
public:
    Grafo(int num_vertices);
    int num_arestas();
    int num_vertices();
    void insere_aresta(Aresta aresta);
    void remove_aresta(Aresta aresta);
    bool existe_aresta(Aresta aresta);
    int grau_maximo();
    int grau_minimo();
    bool eh_caminho(vector<int> vertices);
    bool existe_caminho(int v1, int v2, vector<int> marcado);
    bool eh_conexo();
    bool eh_aciclico();
    void imprime();
private:
    int num_vertices_;
    int num_arestas_;
    list<int> *lista_adjacencia;
    int obterGrau(int vertice);
};

#endif /* GRAFO_H */
