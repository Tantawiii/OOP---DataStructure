#include "ComplexNumber.h"
#include <iostream>

int ComplexNumber::objectCount = 0;

ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {
    objectCount++;
}

ComplexNumber::ComplexNumber(const ComplexNumber& other) : real(other.real), imaginary(other.imaginary) {
    objectCount++;
}

ComplexNumber::~ComplexNumber() {
    objectCount--;
}

void ComplexNumber::setReal(double r) {
    real = r;
}

double ComplexNumber::getReal() const {
    return real;
}

void ComplexNumber::setImaginary(double i) {
    imaginary = i;
}

double ComplexNumber::getImaginary() const {
    return imaginary;
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

int ComplexNumber::getObjectCount() {
    return objectCount;
}
