#pragma once
#include <iostream>
#include "GeometricShape.h"
using namespace std;
class Circle : public GeometricShape 
{
	public:
		void calculateArea() override;
};

