#include "geom.h"

using namespace std;

// Point
ld Vector::operator*(Vector a) const {
    return x * a.x + y * a.y + z * a.z;
}

Vector Vector::operator+(Vector a) const {
    return {x + a.x, y + a.y, z + a.z};
}

Vector Vector::operator-(Vector a) const {
    return {x - a.x, y - a.y, z - a.z};
}

Vector Vector::operator*(ld k) const {
    return {x * k, y * k, z * k};
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

Vector Vector::norm() {
    ld len = sqrt((*this) * (*this));
    return {x / len, y / len, z / len};
}

bool Point::operator==(Point a) const {
    return a.x == x && a.y == y && a.z == z;
}

Point::Point(Vector a) {
    x = a.x, y = a.y, z = a.z;
}
//Sphere


bool Sphere::operator==(Sphere a) const {
    return a.centre == centre && a.r == r;
}

shared_ptr<pair<ld, ld>> Sphere::IntersectRay(const Vector dir, const Point o) const {
    Vector Vco(centre, o);
    ld A = dir * dir;
    ld B = 2 * (Vco * dir);
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