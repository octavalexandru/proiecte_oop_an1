//
// Created by alexa on 3/7/2024.
//

#include "ComplexDynamicTest.h"

//void ComplexDynamicTest::TestGetterAndSetter() {
//    ComplexDynamic c;
////
////    c.SetReal(1);
////    c.SetImaginary(0.5);
////
//    std::cout << c.GetReal() << ' ' << c.GetImaginary() << std::endl;
//}
//
//void ComplexDynamicTest::TestContructorInit() {
//    ComplexDynamic c(1, 2);
//
//    std::cout << c.GetReal() << ' ' << c.GetImaginary() << std::endl;
//}
//
void ComplexDynamicTest::TestConstructorCopiere() {
    ComplexDynamic c(1, 2);
    ComplexDynamic c2(c);

    std::cout << c.GetReal() << ' ' << c.GetImaginary() << std::endl;
    std::cout << c2.GetReal() << ' ' << c2.GetImaginary() << std::endl;

    std::cout << "Inainte de modificare valoare pe c1" << std::endl;
    c.SetImaginary(5);

    std::cout << c.GetReal() << ' ' << c.GetImaginary() << std::endl;
    std::cout << c2.GetReal() << ' ' << c2.GetImaginary() << std::endl;

    std::cout << "Dupa de modificare valoare pe c1" << std::endl;
}

void ComplexDynamicTest::TestOperatorAtribuire() {
    ComplexDynamic c(1, 2);
    ComplexDynamic c2(c);

    c = c2;

    std::cout << c.GetReal() << ' ' << c.GetImaginary() << std::endl;
    std::cout << c2.GetReal() << ' ' << c2.GetImaginary() << std::endl;

    std::cout << "Inainte de modificare valoare pe c1" << std::endl;
    c.SetImaginary(5);

    std::cout << c.GetReal() << ' ' << c.GetImaginary() << std::endl;
    std::cout << c2.GetReal() << ' ' << c2.GetImaginary() << std::endl;

    std::cout << "Dupa de modificare valoare pe c1" << std::endl;
}

void ComplexDynamicTest::TestCreareComplexSiAfisareValori() {
    ComplexDynamic c;

    std::cout << c.GetReal() << ' ' << c.GetImaginary();
}