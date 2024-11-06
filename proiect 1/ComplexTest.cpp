//
// Created by alexa on 3/7/2024.
//

#include "ComplexTest.h"

void ComplexTest::TestGetterAndSetter() {
    Complex c;

    c.SetReal(1);
    c.SetImaginary(0.5);

    std::cout << c.GetReal() << ' ' << c.GetImaginary() << std::endl;
}

void ComplexTest::TestContructorInit() {
    Complex c1; Complex c2(1,2);

    std::cout << c1.GetReal() << ' ' << c1.GetImaginary() << std::endl;
    std::cout << c2.GetReal() << ' ' << c2.GetImaginary() << std::endl;
}

void ComplexTest::TestConstructorCopiere() {
    Complex c1(1,2);
    Complex c2(c1);

    std::cout << c1.GetReal() << ' ' << c1.GetImaginary() << std::endl;
    std::cout << c2.GetReal() << ' ' << c2.GetImaginary() << std::endl;

    std::cout << "Inainte de modificare valoare pe c1" << std::endl;
    c1.SetImaginary(5);

    std::cout << c1.GetReal() << ' ' << c1.GetImaginary() << std::endl;
    std::cout << c2.GetReal() << ' ' << c2.GetImaginary() << std::endl;

    std::cout << "Dupa de modificare valoare pe c1" << std::endl;
}

void ComplexTest::TestOperatorInmultire() {
    Complex c1(1,2);
    Complex c2(c1);
    Complex c5(c1 * c2);
    std::cout << c5.GetReal() << ' ' << c5.GetImaginary() << std::endl;
}

void ComplexTest::TestOperatorImpartire() {
    Complex c1(1,2);
    Complex c2(c1);
    Complex c5(c1 / c2);
    std::cout << c5.GetReal() << ' ' << c5.GetImaginary() << std::endl;
}