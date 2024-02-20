#include <bits/stdc++.h>
#include "Output.h"

using namespace std;

using ll = long long;
using ld = long double;

void solve();

int main() {
    const int N = 1024, M = 1024;
    vector<vector<Pixel>> Screen(N, vector<Pixel>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            Screen[i][j] = {1, 0, 1};
        }
    }
    printS(Screen);
    cout << "compile\n";
}

