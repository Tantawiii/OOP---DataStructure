#pragma once
using namespace std;
class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0);

    ComplexNumber Add(ComplexNumber& value);
    ComplexNumber Subtract(ComplexNumber& value);

    void Display();
};


