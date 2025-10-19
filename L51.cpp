#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>


int mujerPrefiere(int N, int* mujerPrefs, int proponente, int hombreActual) {
    for (int i = 0; i < N; i++) {
        if (mujerPrefs[i] == proponente) return proponente;
        if (mujerPrefs[i] == hombreActual) return hombreActual;
    }

    return -1; // no prefiere a ninguno (se arrepintió xD)
}

int main() {
    int N;
    cin >> N;

    queue<int> hombres[N];      // arreglo de hombres, y cada hombre tiene su lista de preferencias
    int mujeres[N][N];          // arreglo de mujeres, y cada mujer tiene sus preferencias
    
    queue<int> proponentes;     // cola de hombres que todavia no tienen pareja
    int parejas[N];             // index=mujerIndex, value=hombreIndex

    // leer preferencias de hombres
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int m;
            cin >> m;
            hombres[i].push(m - 1);
        }
        proponentes.push(i);    // ningun hombre tiene pareja al inicio
        parejas[i] = -1;        // la i-esima mujer no tiene pareja (ninguna al inicio)
    }

    // leer preferencias de mujeres
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int h;
            cin >> h;
            mujeres[i][j] = h - 1;
        }
    }

    // hasta que todos esten emparejados
    while (!proponentes.empty()) {
        int proponente = proponentes.front(); proponentes.pop();
        queue<int> preferenciasHombre = hombres[proponente];

        // proponer hasta encontrar pareja
        while (!preferenciasHombre.empty()) {
            int mujerIndex = preferenciasHombre.front(); preferenciasHombre.pop();

            int hombreParejaActual = parejas[mujerIndex];

            // si la mujer no tiene pareja todavia, entonces acepta al hombre
            if (hombreParejaActual == -1) {
                parejas[mujerIndex] = proponente;
                break;      // dejar de buscar pareja
            }

            // si ya tiene pareja hay que ver a quien prefiere
            int prefiere = mujerPrefiere(N, mujeres[mujerIndex], proponente, hombreParejaActual);

            // si prefiere al nuevo, deja botado al de antes y ese queda soltero de nuevo :(
            if (prefiere == proponente) {
                proponentes.push(hombreParejaActual);   // va a tener que proponer de nuevo
                parejas[mujerIndex] = proponente;
                break;      // dejar de buscar pareja
            }
        }
    }

    // heapsort y print
    priority_queue<pii, vector<pii>, greater<pii>> heap;

    for (int i = 0; i < N; i++) {
        heap.push(pair<int, int>(parejas[i] + 1, i + N + 1));
    }
    while (!heap.empty()) {
        pii pareja = heap.top(); heap.pop();
        cout << pareja.first << " " << pareja.second << "\n";
    }
}