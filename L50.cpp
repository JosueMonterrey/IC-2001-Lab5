#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, E;
    int a, b;
    cin >> N >> M >> E;

    int personas[N];

    for (int i = 0; i < N; i++) {
        personas[i] = i;
    }

    while (M--) {
        cin >> a >> b;
        personas[b] = personas[a];
    }

    while (E--) {
        cin >> a >> b;
    }
}