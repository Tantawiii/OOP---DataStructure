#include "ComplexNumber.h"
#include <iostream>

int ComplexNumber::objectCount = 0;

ComplexNumber::ComplexNumber(double r, double i) : real(r), imaginary(i) {
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
    return ComplexNumber(real + value.real, imaginary + value.imaginary);
}

ComplexNumber ComplexNumber::Subtract(ComplexNumber& value) {
    return ComplexNumber(real - value.real, imaginary - value.imaginary);
}

void ComplexNumber::Display() {
    cout << real << " + " << imaginary << "i" << endl;
}

int ComplexNumber::getObjectCount() {
    return objectCount;
}
