#include "ComplexNumber.h"
#include <iostream>


ComplexNumber::ComplexNumber(double r, double i) {
    real = r;
    imaginary = i;
}

ComplexNumber ComplexNumber::Add(ComplexNumber& value) {
    double newReal = real + value.real;
    double newImag = imaginary + value.imaginary;
    return ComplexNumber(newReal, newImag);
}

ComplexNumber ComplexNumber::Subtract(ComplexNumber& value) {
    double newReal = real - value.real;
    double newImag = imaginary - value.imaginary;
    return ComplexNumber(newReal, newImag);
}

void ComplexNumber::Display() {
    cout << real << " + " << imaginary << "i" << endl;
}
