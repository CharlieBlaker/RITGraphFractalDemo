#include <iostream>
#include <fstream>

#include <cmath>
#include <vector>
#include <complex>

uint8_t clampCol(double val) {
     if (val < 0.0) {
         return uint8_t(0);
     } else if (val > 1.0) {
         return uint8_t(255);
     } else {
         return uint8_t(val * 255);
     }
}

void writeCol(std::ofstream& out, const std::vector<double>& col) {
    uint8_t rByte = clampCol(col[0]);
    uint8_t gByte = clampCol(col[1]);
    uint8_t bByte = clampCol(col[2]);
    
    out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}

void render() {
    std::ofstream file;
    double width = 200;
    double height = 100;

    file << "P3\n" << width << ' ' << height << "\n255\n";
}

int main() {
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}