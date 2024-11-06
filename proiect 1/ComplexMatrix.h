//
// Created by octav on 15/03/2024.
//

#ifndef PROIECT_1_COMPLEXMATRIX_H
#define PROIECT_1_COMPLEXMATRIX_H

#include "Complex.h"

using namespace std;

class ComplexMatrix {
private:
    int lines, col;
    Complex **mat;
public:
    ComplexMatrix();

    ComplexMatrix(Complex **, int, int);

    ComplexMatrix(ComplexMatrix &);

    ~ComplexMatrix();

    Complex &operator[](int index);

    friend ostream &operator<<(ostream &, const ComplexMatrix &);

    friend istream &operator>>(std::istream &in, ComplexMatrix &cm);

    ComplexMatrix operator+(const ComplexMatrix &);

    ComplexMatrix operator*(const ComplexMatrix &);

    ComplexMatrix& operator=(const ComplexMatrix &);

    ComplexMatrix module() const;

    int get_cols() const {
        return col;
    }

    int get_lines() const {
        return lines;
    }

    void set_lines(int lines)
    {
        this->lines = lines;
    }
    void set_cols(int col)
    {
        this->col = col;
    }
    Complex **get_mat() {
        return mat;
    }

    void set_elem(int line, int col, Complex **c);

};


#endif //PROIECT_1_COMPLEXMATRIX_H