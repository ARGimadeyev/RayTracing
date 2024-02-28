
#ifndef RAYTRACING_GEOM_H
#define RAYTRACING_GEOM_H

#include <bits/stdc++.h>
#include "Output.h"

using namespace std;
using ld = double;

const double PI = acos(-1);
const double EPS = 1e-9;

class Point {
public:
    ld x, y, z;

    Point() {}

    Point(ld _x, ld _y, ld _z) : x(_x), y(_y), z(_z) {}

    ld operator*(Point a) const;

//    ld operator%(Point a) const;

    Point operator+(Point a) const;

    Point operator-(Point a) const;

    bool operator==(Point a) const;
    Point operator*(ld k) const;

    Point norm();
};

class Sphere {
public:
    Point centre;
    ld r;
    Color col;

    Sphere() {}

    Sphere(Point centre, ld r, Color col) : centre(centre), r(r), col(col) {}

    shared_ptr<pair<ld, ld>> IntersectRay(const Point Vdir, const Point o = {0, 0, 0});

    bool operator==(Sphere a) const;
};

#endif //RAYTRACING_GEOM_H
