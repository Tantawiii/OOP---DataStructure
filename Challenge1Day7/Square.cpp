#include "Square.h"

Square::Square(double s) : side(s) {}

double Square::calculateArea() const {
    cout << side * side << endl;
    return side * side;
}
