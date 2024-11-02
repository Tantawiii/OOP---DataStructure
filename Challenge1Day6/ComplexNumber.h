#pragma once
#include <iostream>
using namespace std;

class ComplexNumber {
private:
    float real;
    float imaginary;
    float wow = real + imaginary;
    static int objectCount;

public:
    ComplexNumber(float r = 0.0, float i = 0.0);
    ComplexNumber(const ComplexNumber& other);

    ~ComplexNumber();

    void setReal(float real);
    float getReal() const;
    void setImaginary(float imaginary);
    float getImaginary() const;

    ComplexNumber Add(ComplexNumber& value);
    ComplexNumber Subtract(ComplexNumber& value);
    void Display();
    void display();

    static int getObjectCount();

    ComplexNumber operator+(const ComplexNumber &op);
    ComplexNumber operator-(const ComplexNumber& op);
    ComplexNumber operator/(const ComplexNumber& op);
    ComplexNumber operator*(const ComplexNumber& op);
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
    bool operator==(const ComplexNumber& op);
    bool operator!=(const ComplexNumber& op);
    operator int() const;
};
