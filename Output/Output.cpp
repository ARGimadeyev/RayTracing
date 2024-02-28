#include "Output.h"

using namespace std;

Color Color::operator*(double k) const {
    return {r * k, g * k, b * k};
}

void printS(vector<vector<Color>> &shot, int color_) {
    ofstream fout("../photo.ppm");
    fout << "P3\n";
    fout << shot[0].size() << ' ' << shot.size() << '\n';
    fout << color_ << '\n';
    for (auto &i: shot) {
        for (auto &j: i) {
            fout << int(j.r * color_) << ' ' << int(j.g * color_) << ' ' << int(j.b * color_) << '\n';
        }
    }
    fout.close();
}