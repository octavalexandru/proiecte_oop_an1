//
// Created by alexa on 3/7/2024.
//

#ifndef LAB1_COMPLEXDYNAMIC_H
#define LAB1_COMPLEXDYNAMIC_H

#include <iostream>


class ComplexDynamic {
    double *real;
    double *imaginary;

public:
    ComplexDynamic();
    ComplexDynamic(double realValue, double imaginaryValue);
    ComplexDynamic(const ComplexDynamic& complex);


    double GetReal() { return *real; }
    double GetImaginary() { return *imaginary; }

    void SetReal(double realValue) { *real = realValue; }
    void SetImaginary(double imaginaryValue) { *imaginary = imaginaryValue; }

    ComplexDynamic& operator=(const ComplexDynamic& c);
    ~ComplexDynamic() {delete real; delete imaginary;}


};


#endif //LAB1_COMPLEXDYNAMIC_H
