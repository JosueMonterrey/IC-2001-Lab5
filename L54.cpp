#include <bits/stdc++.h>

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    // imposible un grafo conexo con menos de N-1 aristas
    if (M < N-1) {
        cout << "NO\n";
        return 0;
    }

    int nodos[N];

    // cada nodo esta en su propia componente conexa
    for (int i = 0; i < N; i++) {
        nodos[i] = i;
    }

    // union find
    int u, v;
    while (M--) {
        cin >> u >> v;
        nodos[v-1] = nodos[u-1];
    }

    // si hay mas de una componente conexa
    int representante = nodos[0];
    for (int i = 0; i < N; i++) {
        if (nodos[i] != representante) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "SI\n";
}