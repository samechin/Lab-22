#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber {
    public:
        double real;
        double imag;
        ComplexNumber(double x = 0, double y = 0);

        friend ComplexNumber operator+(const ComplexNumber &, const ComplexNumber &);
        friend ComplexNumber operator-(const ComplexNumber &, const ComplexNumber &);
        friend ComplexNumber operator*(const ComplexNumber &, const ComplexNumber &);
        friend ComplexNumber operator/(const ComplexNumber &, const ComplexNumber &);
        friend bool operator==(const ComplexNumber &, const ComplexNumber &);
        
        friend ostream& operator<<(ostream &, const ComplexNumber &);

        double abs();
        double angle();
};

ComplexNumber::ComplexNumber(double x, double y) {
    real = x; imag = y;
}

ComplexNumber operator+(const ComplexNumber &a, const ComplexNumber &b) {
    return ComplexNumber(a.real + b.real, a.imag + b.imag);
}

ComplexNumber operator-(const ComplexNumber &a, const ComplexNumber &b) {
    return ComplexNumber(a.real - b.real, a.imag - b.imag);
}

ComplexNumber operator*(const ComplexNumber &a, const ComplexNumber &b) {
    return ComplexNumber(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
}

ComplexNumber operator/(const ComplexNumber &a, const ComplexNumber &b) {
    double denominator = pow(b.real, 2) + pow(b.imag, 2);
    return ComplexNumber((a.real * b.real + a.imag * b.imag) / denominator, 
                         (a.imag * b.real - a.real * b.imag) / denominator);
}

bool operator==(const ComplexNumber &a, const ComplexNumber &b) {
    return (a.real == b.real && a.imag == b.imag);
}

double ComplexNumber::abs() {
    return sqrt(pow(real, 2) + pow(imag, 2));
}

double ComplexNumber::angle() {
    return atan2(imag, real) * 180 / M_PI;
}

ostream& operator<<(ostream &os, const ComplexNumber &c) {
    if (c.real == 0 && c.imag == 0) return os << 0;
    if (c.real == 0) return os << c.imag << "i";
    if (c.imag == 0) return os << c.real;
    if (c.imag > 0) return os << c.real << "+" << c.imag << "i";
    return os << c.real << c.imag << "i";
}