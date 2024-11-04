#pragma once
#include <iostream>
#include "GeometricShape.h"
using namespace std;
class Square : public GeometricShape {
private:
    double side;

public:
    Square(double s);
    double calculateArea() const override;
};
