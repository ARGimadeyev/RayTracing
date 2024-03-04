#include <bits/stdc++.h>
#include "geom/geom.h"
//#include "Output/Output.h"

using namespace std;

using ll = long long;
using d = double;

const int N = 2048, M = 2048;
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
    vector<Point> Suns = {Point(60, 1, 15), Point(50, 30, 15)};

    vector<Sphere> Balls = {
            Sphere(Point(-9, 1, 50), 10, Color(0.6, 0.3, 0.9)),
            Sphere(Point(11, 1, 50), 10, Color(0.55, 1, 0.4)),
    };
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            ld Dist = 1e9;
            for (auto ball: Balls) {
                Point ij(-mw / 2.0 + mw * (ld(j) / (M - 1)), mh / 2.0 - mh * (ld(i) / (N - 1)), md);
                Vector v(Camera, ij);
                auto ntr = ball.IntersectRay(v, Camera);
                if (ntr) {
                    if (Dist > ntr->first) {
                        Point PointInt = Point(v * (ntr->first));
                        Vector cTop = Vector(ball.centre, PointInt);
                        ld mx = 0.15;
                        for (auto sun: Suns) {
                            Vector vToc(PointInt, sun);
                            bool b = true;
                            for (auto ball2: Balls) {
                                if (ball == ball2) continue;
                                auto tr = ball2.IntersectRay(vToc, PointInt);
                                if (tr && tr->first >= 0) {
                                    b = false;
                                    break;
                                }
                            }
                            if (b) {
                                ld kof = (max(0.0, vToc.norm() * cTop.norm())) * d(1 - 0.15) / (Suns.size());
                                mx += kof;
                            }
                        }
                        Screen[i][j] = ball.col * min(mx, d(1));
                        Dist = ntr->first;
                    }
                }
            }
        }
    }

}