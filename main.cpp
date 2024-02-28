#include <bits/stdc++.h>
#include "geom/geom.h"
//#include "Output/Output.h"

using namespace std;

using ll = long long;
using d = double;

const int N = 1024, M = 1024;
const Color BACKGROUND = {0.55, 0.45, 1};


vector<vector<Color>> Screen(N, vector<Color>(M, BACKGROUND));


void code();

int main() {
    code();
    printS(Screen);
    cout << "No Errors\n";
}

void code() {
    ld mh = 1, mw = 1, md = 1;

    Point Camera(0, 0, 0);
    vector<Point> Suns = {Point(60, 1, 15)};

    vector<Sphere> Balls = {
            Sphere(Point(-9, 1, 50), 10, Color(1, 0, 0)),
            Sphere(Point(11, 1, 50), 10, Color(1, 0, 0)),
    };
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            ld Dist = 1e9;
            for (auto ball: Balls) {
                Point ij(-mw / 2.0 + mw * (ld(j) / (M - 1)), mh / 2.0 - mh * (ld(i) / (N - 1)), md);
                Point Vv = (ij - Camera).norm();
                auto ntr = ball.IntersectRay(Vv, Camera);
                if (ntr) {
                    if (Dist > ntr->first) {
                        Point PointInt = Vv * (ntr->first);
                        Point VcTop = (PointInt - ball.centre);
                        ld mx = 0.35;
                        for (auto sun: Suns) {
                            Point VpTos = sun - PointInt;
                            bool b = true;
                            for (auto ball2: Balls) {
                                if (ball == ball2) continue;
                                auto tr = ball2.IntersectRay(VpTos, PointInt);
                                if (tr && tr->first >= 0) {
                                    b = false;
                                    break;
                                }
                            }
                            if (b) {
                                ld kof = max(0.0, VpTos.norm() * VcTop.norm()) + 0.35;
                                mx = max(mx, kof);
                            }
                        }
                        Screen[i][j] = ball.col * mx;
                        Dist = ntr->first;
                    }
                }
            }
        }
    }

}