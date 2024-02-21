
#ifndef RAYTRACING_GEOM_H
#define RAYTRACING_GEOM_H

#include <bits/stdc++.h>


using namespace std;
using ld = long double;

const double PI = acos(-1);
const double EPS = 1e-9;

class Point {
public:
    ld x, y;

    Point() {}

    Point(ld _x, ld _y) : x(_x), y(_y) {}

    ld operator*(Point a) const {
        return x * a.x + y * a.y;
    }

    ld operator%(Point a) const {
        return x * a.y - y * a.x;
    }

    Point operator+(Point a) const {
        return Point(x + a.x, y + a.y);
    }

    Point operator-(Point a) const {
        return Point(x - a.x, y - a.y);
    }

    Point operator*(ld k) const {
        return Point(x * k, y * k);
    }
};

class Triangle {
public:
    Point a, b, c;

    Triangle() {}

    Triangle(Point a, Point b, Point c) : a(a), b(b), c(c) {}
};

bool inAngle(Point a, Point o, Point b, Point p);

bool inTriangle(Triangle &t, Point p);

#endif //RAYTRACING_GEOM_H
