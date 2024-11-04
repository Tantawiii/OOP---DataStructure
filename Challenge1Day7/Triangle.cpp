#include "Triangle.h"

Triangle::Triangle(double b, double h) : base(b), height(h) {}

double Triangle::calculateArea() const {
    cout << 0.5 * base * height << endl;
    return 0.5 * base * height;
}
