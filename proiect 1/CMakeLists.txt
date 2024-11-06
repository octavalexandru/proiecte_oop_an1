cmake_minimum_required(VERSION 3.27)
project(proiect_1)

set(CMAKE_CXX_STANDARD 98)

add_executable(proiect_1
        Complex.cpp
        Complex.h
        ComplexDynamic.cpp
        ComplexDynamic.h
        ComplexDynamicTest.cpp
        ComplexDynamicTest.h
        ComplexTest.cpp
        ComplexTest.h
        main.cpp
        ComplexMatrix.cpp
        ComplexMatrix.h)
