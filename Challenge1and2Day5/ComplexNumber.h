#pragma once
#include <iostream>
using namespace std;

class ComplexNumber {
private:
    double real;
    double imaginary;
    static int objectCount;

public:
    ComplexNumber(double r = 0.0, double i = 0.0);
    ComplexNumber(const ComplexNumber& other);

    ~ComplexNumber();

    void setReal(double real);
    double getReal() const;
    void setImaginary(double imaginary);
    double getImaginary() const;

    ComplexNumber Add(ComplexNumber& value);
    ComplexNumber Subtract(ComplexNumber& value);
    void Display();

    static int getObjectCount();
};
