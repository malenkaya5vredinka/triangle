#include <iostream>
#include <iomanip>
#include "triangle.h"

int main() {
    double a, b, c;
    std::cout << "Введите стороны треугольника: ";
    std::cin >> a >> b >> c;

    if (!exists(a, b, c)) {
        std::cout << "Треугольник не существует" << std::endl;
        return 1;
    }

    std::cout << "Треугольник существует, он ";

    int at = angleType(a, b, c);
    if (at == 0) std::cout << "остроугольный";
    else if (at == 1) std::cout << "прямоугольный";
    else std::cout << "тупоугольный";

    int st = sideType(a, b, c);
    if (st == 1) std::cout << " и равнобедренный";
    else if (st == 2) std::cout << " и равносторонний";

    std::cout << "." << std::endl;

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Периметр равен " << perimeter(a, b, c) << std::endl;
    std::cout << "Площадь равна " << area(a, b, c) << std::endl;

    return 0;
}
