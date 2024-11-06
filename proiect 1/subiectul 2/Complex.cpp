//
// Created by alexa on 3/7/2024.
//

#include "Complex.h"

Complex::Complex() {
    real = 0; imaginary = 0;
 //   std::cout << "S-a apelat contructorul neparam" << std::endl;
}

Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {
        this -> real = real; this -> imaginary = imaginary;
//    std::cout << "S-a apelat contructorul param" << std::endl;
}

Complex::Complex(double real) {
    this -> real = real; imaginary = 0;
}


std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.real << " + " << c.imaginary << "i";
    return out;
}

std::istream& operator>>(std::istream& in, Complex& c) {
    std::cout << "Enter real part: ";
    in >> c.real;
    std::cout << "Enter imaginary part: ";
    in >> c.imaginary;
    return in;
}
Complex& Complex::operator=(const Complex& c) {
    real = c.real; imaginary = c.imaginary;
    //std::cout << "operator atribuire" << std::endl;
    return *this;
}

Complex operator-(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.SetImaginary(c1.GetImaginary() - c2.GetImaginary());
    return result;
}

Complex Complex::operator*(Complex c1) {
    return Complex(
            this->real * c1.real - this->imaginary * c1.imaginary,
            this->real * c1.imaginary + this->imaginary * c1.real
    );
}

Complex operator/(Complex c1, Complex c2) {
    Complex result;

    //avem nevoie de conjugatul lui c2 pentru a inmulti cu c1 si a imparti pe modulul la patrat
    Complex temp(c2.real, -c2.imaginary);
    result = c1 * temp;
    double absSquared = c2.AbsSquared();
    result.real = result.real / absSquared;
    result.imaginary /= absSquared;

    return result;
}