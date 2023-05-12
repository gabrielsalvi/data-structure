#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {
    int V, E, O;
    cin >> V >> E;

    Grafo grafo(V);

    for (auto i = 0; i < E; i++) {
        int X, Y;
        cin >> X >> Y;
        grafo.insere_aresta(Aresta(X, Y));
    }

    cin >> O;

    for (auto i = 0; i < O; i++) {
        vector<int> marcado, vertices;
        marcado.resize(V);
        string saida = "";
        char op;
        cin >> op;
        
        switch (op) {
            case 'S':
                int M;
                cin >> M;

                for (auto i = 0; i < M; i++) {
                    int N;
                    cin >> N;
                    vertices.push_back(N);
                }
                
                saida = grafo.eh_caminho(vertices) ? "SIM" : "NAO";
                break;
            case 'C':
                int X, Y;
                cin >> X >> Y;
                saida = grafo.existe_caminho(X, Y, marcado) ? "SIM" : "NAO";
                break;
            case 'X':
                saida = grafo.eh_conexo() ? "SIM" : "NAO";
                break;
            case 'A':
                saida = grafo.eh_aciclico() ? "SIM" : "NAO";
                break;
            default:
                break;
        }

        cout << saida << endl;
    }
        
    return 0;
}
