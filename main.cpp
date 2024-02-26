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
    int x0 = N / 2, y0 = M / 2, r = 128;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if ((i - x0) * (i - x0) + (j - y0) * (j - y0) <= r * r) {
                Screen[i][j] = {1, 0, 0};
            }
        }
    }
    vector<Point> polygon = {{0,   0},
                             {1.5, 0},
                             {2,   2},
                             {2.5, 0},
                             {4,   0},
                             {3,   -1},
                             {3.5, -2},
                             {2,   -1.5},
                             {0.5, -2},
                             {1,   -1}};
    for (int i = 0; i < polygon.size(); ++i) {
        polygon[i].x *= 64, polygon[i].y *= 64;
        polygon[i].x += 712, polygon[i].y += 712;
//        swap(polygon[i].x, polygon[i].y);
    }
    Triangle z1(polygon[0], polygon[4], polygon[7]),
            z2(polygon[2], polygon[8], polygon[7]),
            z3(polygon[5], polygon[6], polygon[7]),
            z4(polygon[4], polygon[5], polygon[7]);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (inTriangle(z1, Point(i, j)) || inTriangle(z2, Point(i, j)) || inTriangle(z3, Point(i, j)) ||
                inTriangle(z4, Point(i, j))) {
                Screen[i][j] = {0, 0, 1};
            }
        }
    }
    printS(Screen);
    cout << "No Errors\n";
}

