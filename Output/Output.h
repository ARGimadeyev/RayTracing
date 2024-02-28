
#ifndef RAYTRACING_OUTPUT_H
#define RAYTRACING_OUTPUT_H

#include <vector>
#include <fstream>

using namespace std;

class Color {
public:
    double r = 0, g = 0, b = 0;

    Color() {}

    Color(double r, double g, double b) : r(r), g(g), b(b) {}
};

void printS(vector<vector<Color>> &shot, int color_ = 255);

#endif //RAYTRACING_OUTPUT_H
