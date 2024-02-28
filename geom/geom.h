
#ifndef RAYTRACING_GEOM_H
#define RAYTRACING_GEOM_H

#include <bits/stdc++.h>


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

    ld operator%(Point a) const;

    Point operator+(Point a) const;

    Point operator-(Point a) const;

    Point operator*(ld k) const;

    Point norm();
};

class Sphere {
public:
    Point centre;
    ld r;

    Sphere() {}

    Sphere(Point centre, ld r) : centre(centre), r(r) {}

    shared_ptr<pair<ld, ld>> IntersectRay(const Point Vdir, const Point o = {0, 0, 0});
};

#endif //RAYTRACING_GEOM_H
