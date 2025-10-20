#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define vi  vector<int>
#define vvi vector<vi>
#define vb  vector<bool>

pii nodoMasLejano(vvi G, vb visitados, int nActual = 0, int distancia = 0) {
    visitados[nActual] = true;

    int masLejano = nActual;
    int maxDistancia = distancia;

    for (int vecino : G[nActual]) {
        if (!visitados[vecino]) {
            pii resultadoVecino = nodoMasLejano(G, visitados, vecino, distancia + 1);
            int masLejanoVecino = resultadoVecino.first;
            int maxDistanciaVecino = resultadoVecino.second;

            if (maxDistanciaVecino > maxDistancia) {
                masLejano = masLejanoVecino;
                maxDistancia = maxDistanciaVecino;
            }
        }
    }

    return pii(masLejano, maxDistancia);
}

int main() {
    int N, M;
    cin >> N >> M;

    vvi G(N);

    int u, v;
    while (M--) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int origen = 0, origenAnterior;
    int masLejano = 0, masLejanoAnterior;
    int perimetro;

    do {
        masLejanoAnterior = masLejano;
        origenAnterior = origen;
        origen = masLejanoAnterior;

        vb visitados(N);
        pii r = nodoMasLejano(G, visitados, origen); // nodo mas alejado del nodo 0 (default).

        masLejano = r.first;
        perimetro = r.second;

    } while (origenAnterior != masLejano || origen != masLejanoAnterior);

    cout << perimetro << "\n";
}