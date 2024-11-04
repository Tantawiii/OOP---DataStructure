#pragma once
#include <iostream>
#include "GeometricShape.h"
using namespace std;
class Triangle : public GeometricShape {
private:
    double base, height;

public:
    Triangle(double b, double h);
    double calculateArea() const override;
};
