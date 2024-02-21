
#ifndef RAYTRACING_OUTPUT_H
#define RAYTRACING_OUTPUT_H

#include <vector>
#include <fstream>

using namespace std;

class Pixel {
public:
    double r = 0, g = 0, b = 0;

    Pixel() {}

    Pixel(double r, double g, double b) : r(r), g(g), b(b) {}
};

void printS(vector<vector<Pixel>> &shot, int color_ = 255);

#endif //RAYTRACING_OUTPUT_H
