#pragma once
#include <iostream>
#include "GeometricShape.h"
using namespace std;
class Rectangle : public GeometricShape
{
	public:
		void calculateArea() override;
};

