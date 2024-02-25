#include <bits/stdc++.h>
#include "geom/geom.h"
#include "Output/Output.h"

using namespace std;

using ll = long long;
using d = double;


int main() {
    const int N = 1024, M = 1024;
    vector<vector<Pixel>> Screen(N, vector<Pixel>(M));
    Triangle t(Point(200, 200), Point(300, 300), Point(150, 250));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (inTriangle(t, Point(i, j))) {
                Screen[i][j] = {0, 1, 0};
            } else {
                Screen[i][j].r = d(i + j) / (N + M);
                Screen[i][j].g = d(N - i - 1 + j) / (N + M);
                Screen[i][j].b = d(i + M - j - 1) / (N + M);
            }
        }
    }
    printS(Screen);
    cout << "No Errors\n";
}

