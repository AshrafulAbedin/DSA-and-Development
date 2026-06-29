#include <bits/stdc++.h>
using namespace std;

int linearCol(int keys[], int M, int N) {
    vector<int> t(N, -1);
    int total = 0;
    for (int i = 0; i < M; i++) {
        int k = keys[i], j = 0;
        while (t[(k % N + j) % N] != -1) { total++; j++; }
        t[(k % N + j) % N] = k;
    }
    return total;
}

int quadCol(int keys[], int M, int N) {
    vector<int> t(N, -1);
    int total = 0;
    for (int i = 0; i < M; i++) {
        int k = keys[i], j = 0;
        while (t[(k % N + j*j) % N] != -1) { total++; j++; }
        t[(k % N + j*j) % N] = k;     // only change: j*j
    }
    return total;
}

int main() {
    int N, M; cin >> N >> M;
    int keys[1005];
    for (int i = 0; i < M; i++) cin >> keys[i];
    cout << "Linear Probing Collisions: "    << linearCol(keys, M, N) << "\n";
    cout << "Quadratic Probing Collisions: " << quadCol(keys, M, N)  << "\n";
    return 0;
}
