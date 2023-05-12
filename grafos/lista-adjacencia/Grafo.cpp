#include <iostream>
#include <vector>
#include "Grafo.h"

Grafo::Grafo(int num_vertices) {
    this->num_vertices_ = num_vertices;
    this->num_arestas_ = 0;
    this->lista_adjacencia = new list<int>[num_vertices];
}

int Grafo::num_arestas() {
    return num_arestas_;
}

int Grafo::num_vertices() {
    return num_vertices_;
}

void Grafo::insere_aresta(Aresta aresta) {
    int v1 = aresta.v1, v2 = aresta.v2;
    bool ehLaco = v1 == v2;
    
    if (!ehLaco && !this->existe_aresta(aresta)) {
        lista_adjacencia[v1].push_front(v2);
        lista_adjacencia[v2].push_front(v1);
        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta aresta) {
    int v1 = aresta.v1, v2 = aresta.v2;
    if (this->existe_aresta(aresta)) {
        lista_adjacencia[v1].remove(v2);
        lista_adjacencia[v2].remove(v1);
        num_arestas_--;
    }
}

bool Grafo::existe_aresta(Aresta aresta) {
    int v1 = aresta.v1, v2 = aresta.v2;
    for (int v : lista_adjacencia[v1]) {
        if (v == v2) return true;
    }
    return false;
}

int Grafo::obterGrau(int vertice) {
    return lista_adjacencia[vertice].size();
}

int Grafo::grau_maximo() {
    int grau_maximo = 0;
    for (int i = 0; i < num_vertices_; i++) {
        int grau_vertice = this->obterGrau(i);
        grau_maximo = max(grau_maximo, grau_vertice);
    }
    return grau_maximo;
}

int Grafo::grau_minimo() {
    int grau_minimo = this->obterGrau(0);
    for (int i = 1; i < num_vertices_; i++) {
        int grau_vertice = this->obterGrau(i);
        grau_minimo = min(grau_minimo, grau_vertice);
    }
    return grau_minimo;
}

bool Grafo::existe_caminho(int v1, int v2, vector<int> marcado) {
    if (v1 == v2) return true;

    marcado[v1] = 1;
    for (auto vertice : lista_adjacencia[v1]) {
        if (marcado[vertice] == 0) {
            if (existe_caminho(vertice, v2, marcado)) return true;
        }
    }
    return false;
}

bool Grafo::eh_caminho(vector<int> vertices) {
    if (vertices.empty()) return false;
    if (vertices.size() == 1) return true;

    int ultimo_vertice_visitado = -1;
    for (auto i = 0; i < static_cast<int>(vertices.size()) - 1; i++) {
        int vertice = vertices[i]; // 2
        int proximo_vertice = vertices[i+1]; // 1
        
        if (lista_adjacencia[vertice].size() == 0) {
            return false;
        }

        if (proximo_vertice == ultimo_vertice_visitado) {
            return false;
        }

        if (!existe_aresta(Aresta(vertice, proximo_vertice))) { 
            return false;
        }

        ultimo_vertice_visitado = vertice;
    }

    return true;
}

bool Grafo::eh_conexo() {
    bool *visited = new bool[num_vertices_];
    busca_profunda(0, visited);

    for(int i = 0; i < num_vertices_; i++) {
        if(!visited[i]) {
            return false;
        }
    }

    return true;
}

void Grafo::busca_profunda(int v, bool *marcado) {
    marcado[v] = true;
    for(auto vizinho = lista_adjacencia[v].begin(); vizinho != lista_adjacencia[v].end(); vizinho++) {
        if(!marcado[*vizinho]) {
            busca_profunda(*vizinho, marcado);
        }
    }
}

bool Grafo::eh_aciclico() {
    return true;
}

void Grafo::imprime() {
    for (int i = 0; i < num_vertices_; i++) {
        cout << i << ": ";
        for (int vertice : lista_adjacencia[i]) {
            cout << vertice << " ";
        }
        cout << endl;
    }
}