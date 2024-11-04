#pragma once
#include <iostream>
#include "GeometricShape.h"
using namespace std;
class Triangle : public GeometricShape
{
	public:
		void calculateArea() override;
};

