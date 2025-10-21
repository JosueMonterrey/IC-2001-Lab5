#include <bits/stdc++.h>

using namespace std;

int colorear(vector<vector<int>> G, int * colores, int nodoActual) {
    
    set<int> coloresUsados; // es un arbol rojinegro

    // obtener todos los colores ya utilizados por los vecinos
    for (int vecino : G[nodoActual]) {
        int colorVecino = colores[vecino];
        if (colorVecino)
            coloresUsados.insert(colores[vecino]);  // si el vecino está coloreado marcar como color usado
    }

    // probar desde el color #1 hasta encontrar uno que no sea usado por los vecinos
    int color = 1;
    for (int usado : coloresUsados) {
        if (usado == color) color++;
        else break;
    }
    
    colores[nodoActual] = color;    // asignarle el color al nodo

    // colorear vecinos
    for (int vecino : G[nodoActual]) {
        // si el vecino no está coloreado
        if (!colores[vecino]) {
            int maxColorVecinos = colorear(G, colores, vecino);
            color = max(color, maxColorVecinos);
        }
    }

    return color;
}

int main() {
    int N, M;       // # nodos, # aristas
    cin >> N >> M;

    if (N == 0) {
        cout << "0\n";
        return 0;
    }

    vector<vector<int>> G(N);
    int colores[N]; // Guarda el color de cada nodo
    for (int i = 0; i < N; i++) {
        colores[i] = 0;
    }

    // leer M aristas (i, j)
    int i, j;
    while (M--) {
        cin >> i >> j;
        G[i].push_back(j);
        G[j].push_back(i);
    }

    int maxColor = colorear(G, colores, 0);
    cout << maxColor << "\n";
}