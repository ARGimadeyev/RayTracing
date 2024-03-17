#include <bits/stdc++.h>
#include "geom/geom.h"

using namespace std;

using ll = long long;
using d = double;
//константы
const int N = 2048, M = 2048;
const Color BACKGROUND = {0.55, 0.45, 1};
//экран
vector<vector<Color>> Screen(N, vector<Color>(M, BACKGROUND));

//3-d
Point Camera(0, 0, 0);
vector<Point> Suns = {Point(60, 1, 15), Point(50, 30, 15)};
vector<Sphere> Balls = {
        Sphere(Point(-9, 1, 50), 10, Color(0.6, 0.3, 0.9)),
        Sphere(Point(11, 1, 50), 10, Color(0.55, 1, 0.4)),
};

void code();

int main() {
    code();
    printS(Screen);
    cout << "No Errors\n";
}

//код
Color CompuleLight(int i, int j) {
    d mh = 1, mw = 1, md = 1;
    d Dist = 1e9;
    Sphere s;
    Point trafaret(-mw / 2.0 + mw * (d(j) / (M - 1)), mh / 2.0 - mh * (d(i) / (N - 1)), md);
    Vector v(Camera, trafaret);

    for (auto ball: Balls) {
        auto ntr = ball.IntersectRay(v, Camera);
        if (ntr) {
            if (Dist > ntr->first) {
                Dist = ntr->first;
                s = ball;
            }
        }
    }
    // identity
    Point PointInt = Point(v * (Dist));
    Vector cTop = Vector(s.centre, PointInt);
    d mx = 0.15, res_blick = 0;
    for (auto sun: Suns) {
        Vector vToc(PointInt, sun);
        bool b = true;
        for (auto ball2: Balls) {
            if (s == ball2) continue;
            auto tr = ball2.IntersectRay(vToc, PointInt);
            if (tr && tr->first >= 0) {
                b = false;
                break;
            }
        }
        if (b) {
            ld kof = (max(0.0, vToc.norm() * cTop.norm())) * d(1 - 0.15) / (Suns.size());
            ld blick = pow(vToc.norm() * cTop.norm(), 149);
            res_blick = max(blick, res_blick);
            mx += kof;
        }
    }
    if (Dist != 1e9) {
        Screen[i][j] = s.col * mx + Color(1, 1, 1) * res_blick;
    }
    //diff

}

void code() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            CompuleLight(i, j);
        }
    }
}