//
// Created by alexa on 3/7/2024.
//

#ifndef LAB1_COMPLEX_H
#define LAB1_COMPLEX_H

#include <iostream>

class Complex {
    double real;
    double imaginary;
public:
    //constructori init
    Complex();
    Complex(double real, double imaginary);
    Complex(double real);
    //constructori copiere
    Complex(const Complex& complex): real(complex.real) {
        this -> imaginary = complex.imaginary;
        //std::cout << "S-a apelat contructorul copiere" << std::endl;
    }
    Complex& operator=(const Complex& c);

    ~Complex() {
//        std::cout << "S-a apelat destructorul" << std::endl;
    }
//    double Abs() {}
    //setteri
    void SetReal(double real) {
        this -> real = real;
    }
    void SetImaginary(double imaginary) {
        this -> imaginary = imaginary;
    }
    //getter
    double GetReal() {
        return real;
    }
    double GetImaginary() {
        return imaginary;
    }

    Complex operator+(Complex c2) {
        Complex result(
                this -> real + c2.real,
                this -> imaginary + c2.imaginary
        );
        return result;
    }

    Complex operator*(Complex c2);

    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
    friend std::istream& operator>>(std::istream& in, Complex& c);


    friend Complex operator-(Complex c1, Complex c2);
    friend Complex operator/(Complex c1, Complex c2);

    double AbsSquared() {
        return real * real + imaginary * imaginary;
    }

};




#endif //LAB1_COMPLEX_H
