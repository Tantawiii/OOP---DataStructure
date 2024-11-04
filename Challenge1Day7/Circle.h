#pragma once
#include <iostream>
#include "GeometricShape.h"
using namespace std;
class Circle : public GeometricShape {
private:
    double radius;

public:
    Circle(double r);
    double calculateArea() const override;
};
