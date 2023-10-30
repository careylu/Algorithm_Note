// Copyright 2023, Tencent Inc.
// Author: root
// Date: 10/30/23
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Complex
{
public:
    Complex(double real, double imag) : _real(real), _imag(imag) {}

    // 重载+运算符(成员函数)
    Complex operator+(const Complex& other) const {
        return Complex(_real + other._real, _imag + other._imag);
    }

    // 重载<<运算符(友元函数)
     friend std::ostream& operator<<(std::ostream& os, const Complex& other) {
        os << other._real << "+" << other._imag << "i";
        return os;
    }

private:
    double _real;
    double _imag;
};


int main()
{
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3 = c1 + c2;

    std::cout << "c1: " << c1 << endl;
    std::cout << "c2: " << c2 << endl;
    std::cout << "c3: " << c3 << endl;
}