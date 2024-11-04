#include "Circle.h"

Circle::Circle(double r) : radius(r) {}

double Circle::calculateArea() const {
    cout << 3.14159 * radius * radius << endl;
    return 3.14159 * radius * radius;
}
