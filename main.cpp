#include <iostream>
#include <fstream>

#include <cmath>
#include <vector>
#include <complex>

using vec = std::vector<double>;

vec addVec(vec v, vec w) {
    vec x(v.size());
    for (size_t n=0; n < v.size(); n++) {
        x[n] = v[n] + w[n];
    }
    return x;
}

vec multVec(vec v, double c) {
    vec w = v;
    for (double& x : w) {
        x *= c;
    }
    return w;
}

int clampCol(double val) {
     if (val < 0.0) {
         return int(0);
     } else if (val > 1.0) {
         return int(255);
     } else {
         return int(val * 255);
     }
}

void writeCol(std::ofstream& out, const vec& col) {
    int rByte = clampCol(col[0]);
    int gByte = clampCol(col[1]);
    int bByte = clampCol(col[2]);
    
    out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}

void render() {
    std::ofstream file("output.ppm");
    int width = 400;
    int height = 200;
    double aspect = double(width)/double(height);

    file << "P3\n" << width << ' ' << height << "\n255\n";

    for (int j=0; j < height; j++) {
        std::clog << "\rScanlines Remaining: " << (height - j) << std::flush;

        for (int i=0; i < width; i++) {
            
            vec pixCoord = {double(i), double(j)};
            vec uv = {pixCoord[0] / width, pixCoord[1] / height};
            uv = addVec(multVec(uv, 2.0), vec{-1.0, -1.0});
            uv[0] *= aspect;
            
            vec pixCol = {0, 0, 0};

            writeCol(file, pixCol);
        }
    }
}

int main() {
    render();
    return 0;
}