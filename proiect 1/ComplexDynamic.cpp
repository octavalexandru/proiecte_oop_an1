//
// Created by alexa on 3/7/2024.
//

#include "ComplexDynamic.h"

ComplexDynamic::ComplexDynamic() {
    real = new double ; imaginary = new double ;
    *real = 0; *imaginary = 0;
}

ComplexDynamic::ComplexDynamic(double realValue, double imaginaryValue) {
    real = new double ; imaginary = new double ;
    *real = realValue; *imaginary = imaginaryValue;
}

ComplexDynamic::ComplexDynamic(const ComplexDynamic& complex) {
    real = new double ; imaginary = new double ;
    *real = *complex.real; *imaginary = *complex.imaginary;
}

ComplexDynamic& ComplexDynamic::operator=(const ComplexDynamic& c) {
    *(this -> real) = *c.real; *(this -> imaginary) = *c.imaginary;
    return *this;
}