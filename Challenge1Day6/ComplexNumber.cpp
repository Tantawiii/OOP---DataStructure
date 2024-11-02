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

ComplexNumber ComplexNumber::operator+(const ComplexNumber& op) {
    cout << "This is +" << endl;
    return ComplexNumber(real + op.real, imaginary + op.imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& op) {
    cout << "This is -" << endl;
    return ComplexNumber(real - op.real, imaginary - op.imaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& op) {
    cout << "This is *" << endl;
    return ComplexNumber(real * op.real - imaginary * op.imaginary,real * op.imaginary + imaginary * op.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& op) {
    cout << "This is /" << endl;
    double denominator = op.real * op.real + op.imaginary * op.imaginary;
    return ComplexNumber((real * op.real + imaginary * op.imaginary) / denominator,(imaginary * op.real - real * op.imaginary) / denominator);
}

bool ComplexNumber::operator==(const ComplexNumber& op) {
    cout << "This is ==" << endl;
    return real == op.real && imaginary == op.imaginary;
}

bool ComplexNumber::operator!=(const ComplexNumber& op) {
    cout << "This is !=" << endl;
    return (real != op.real || imaginary != op.imaginary);
}