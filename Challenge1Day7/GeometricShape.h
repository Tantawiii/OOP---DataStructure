#pragma once
#include <iostream>
using namespace std;
class GeometricShape
{
	public:
		virtual double calculateArea() const = 0;
		virtual ~GeometricShape() {}
};

