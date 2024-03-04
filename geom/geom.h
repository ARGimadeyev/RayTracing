
#ifndef RAYTRACING_GEOM_H
#define RAYTRACING_GEOM_H

#include <bits/stdc++.h>
#include "Output.h"

using namespace std;
using ld = double;

const double PI = acos(-1);
const double EPS = 1e-9;

class Point;

class Vector;

class Point {
public:
    ld x, y, z;

    Point() {}

    Point(ld _x, ld _y, ld _z) : x(_x), y(_y), z(_z) {}

    Point(Vector a);

    Point operator+(Point a) const;

    Point operator-(Point a) const;

    Point operator*(ld k) const;

    bool operator==(Point a) const;
};

class Vector {
public:
    ld x, y, z;

    Vector() {}

    Vector(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
        z = b.z - a.z;
    }

    Vector(Point a) {
        x = a.x, y = a.y, z = a.z;
    }

    Vector(ld _x, ld _y, ld _z) : x(_x), y(_y), z(_z) {}

    ld operator*(Vector a) const;

    Vector operator+(Vector a) const;

    Vector operator-(Vector a) const;

    Vector operator*(ld k) const;

    Vector norm();
};

class Sphere {
public:
    Point centre;
    ld r;
    Color col;

    Sphere() {}

    Sphere(Point centre, ld r, Color col) : centre(centre), r(r), col(col) {}

    shared_ptr<pair<ld, ld>> IntersectRay(Vector dir, Point o = {0, 0, 0}) const;

    bool operator==(Sphere a) const;
};

#endif //RAYTRACING_GEOM_H
