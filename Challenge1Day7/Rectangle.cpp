#include "Rectangle.h"
void Rectangle::calculateArea() {
	float length, width;
	cout << "Length: " << endl;
	cin >> length;
	cout << "Width: " << endl;
	cin >> width;
	cout << length * width << endl;
}