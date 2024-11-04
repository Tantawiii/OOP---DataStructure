#pragma once
#include <iostream>
#include "GeometricShape.h"
using namespace std;
class Rectangle : public GeometricShape {
private:
    double width, height;

public:
    Rectangle(double w, double h);
    double calculateArea() const override;
};