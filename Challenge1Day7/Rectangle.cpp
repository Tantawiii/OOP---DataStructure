#include "Rectangle.h"

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::calculateArea() const {
    cout << width * height << endl;
    return width * height;
}
