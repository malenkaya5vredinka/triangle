#include "triangle.h"
#include <cmath>
#include <algorithm>

bool exists(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int angleType(double a, double b, double c) {
    double x = std::min({a, b, c});
    double z = std::max({a, b, c});
    double y = a + b + c - x - z;
    double x2 = x * x, y2 = y * y, z2 = z * z;
    if (std::abs(z2 - (x2 + y2)) < 1e-9) return 1;
    if (z2 < x2 + y2) return 0;
    return 2;
}

int sideType(double a, double b, double c) {
    if (std::abs(a - b) < 1e-9 && std::abs(b - c) < 1e-9) return 2;
    if (std::abs(a - b) < 1e-9 || std::abs(b - c) < 1e-9 || std::abs(a - c) < 1e-9) return 1;
    return 0;
}

double perimeter(double a, double b, double c) {
    return a + b + c;
}

double area(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}
