#include "geom.h"

using namespace std;

bool inAngle(Point a, Point o, Point b, Point p) {
    a = a - o, b = b - o, p = p - o;
    if ((a % p) >= 0 && (p % b) >= 0 && (a % b) >= 0 ||
        (a % p) <= 0 && (p % b) <= 0 && (a % b) <= 0) {
        return true;
    }
    return false;
}

bool inTriangle(Triangle &t, Point p) {
    if (inAngle(t.a, t.b, t.c, p) && inAngle(t.b, t.c, t.a, p)) {
        return true;
    }
    return false;
}