#pragma once
#include <iostream>
#include "GeometricShape.h"
using namespace std;
class Square : public GeometricShape
{
	public:
		void calculateArea() override;
};

