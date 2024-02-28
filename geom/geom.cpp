#include "geom.h"

using namespace std;

// Point
ld Point::operator*(Point a) const {
    return x * a.x + y * a.y + z * a.z;
}

ld Point::operator%(Point a) const {
    return x * a.y - y * a.x;
}

Point Point::operator+(Point a) const {
    return {x + a.x, y + a.y, z + a.z};
}

Point Point::operator-(Point a) const {
    return {x - a.x, y - a.y, z - a.z};
}

Point Point::operator*(ld k) const {
    return {x * k, y * k, z * k};
}

Point Point::norm() {
    ld len = (*this) * (*this);
    return {x / len, y / len, z / len};
}

//Sphere

shared_ptr<pair<ld, ld>> Sphere::IntersectRay(const Point Vdir, const Point o) {
    Point Vco = o - centre;
    ld A = Vdir * Vdir;
    ld B = 2 * (Vco * Vdir);
    ld C = (Vco * Vco) - r * r;
    ld D = B * B - 4 * A * C;
    if (D < 0 + EPS) {
        return nullptr;
    }
    ld x1 = (-B + sqrt(D)) / (2 * A);
    ld x2 = (-B - sqrt(D)) / (2 * A);
    if (x1 > x2) swap(x1, x2);
    return make_shared<pair<ld, ld>>(x1, x2);
}