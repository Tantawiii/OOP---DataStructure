#include "Triangle.h"
void Triangle::calculateArea() {
	float base, height;
	cout << "Base: " << endl;
	cin >> base;
	cout << "Height: " << endl;
	cin >> height;
	cout << 0.5 * base * height << endl;
}