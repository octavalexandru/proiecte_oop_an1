//
// Created by octav on 15/03/2024.
//

#include "ComplexMatrix.h"

using namespace std;

ComplexMatrix::ComplexMatrix() {
    this->mat = NULL;
    this->lines = 0;
    this->col = 0;
}

ComplexMatrix::ComplexMatrix(Complex **mat, int m, int n) {
    this->lines = m;
    this->col = n;
    this->mat = new Complex *[m];   //daca nu merge, matrix  = new Complex[n*m]
    for (int i = 0; i < m; i++) {
        this->mat[i] = new Complex[n];
        for (int j = 0; j < n; j++) {
            this->mat[i][j] = mat[i][j];
        }
    }
}

ComplexMatrix::ComplexMatrix(ComplexMatrix &mat) {
    this->lines = mat.lines;
    this->col = mat.col;
    this->mat = new Complex*[mat.lines];
    for(int i = 0; i < this->lines; i++)
    {
        this->mat[i] = new Complex[this->col];
        for(int j = 0; j < this->col; j++)
            this->mat[i][j] = mat.mat[i][j];
    }
}
ComplexMatrix::~ComplexMatrix() {
    for (int i = 0; i < lines; i++) {
        delete[] mat[i];
    }
    delete[] mat;
    lines = 0;
    col = 0;
}

Complex& ComplexMatrix::operator[](int index) {
    return *mat[index];

}

ostream& operator<<(ostream &out, const ComplexMatrix& cm){
        for(int i = 0; i < cm.lines; i++)
        {
            for(int j = 0; j < cm.col; j++)
                out << cm.mat[i][j] << ' ';
            out << endl;
        }
        return out;
}

istream& operator>>(istream& in, ComplexMatrix& cm) {
    for(int i = 0; i < cm.lines; i++) {
        for(int j = 0; j < cm.col; j++) {
            in >> cm.mat[i][j];
        }
    }
    return in;}

ComplexMatrix ComplexMatrix::operator+(const ComplexMatrix& cm) {
    if (lines != cm.lines || col != cm.col) {
        throw invalid_argument("Matrices must have the same dimensions for addition.");
    }

    ComplexMatrix result;
    result.lines = lines;
    result.col = col;
    result.mat = new Complex*[lines];
    for (int i = 0; i < lines; ++i) {
        result.mat[i] = new Complex[col];
        for (int j = 0; j < col; ++j) {
            result.mat[i][j] = mat[i][j] + cm.mat[i][j];
        }
    }
    return result;
}

ComplexMatrix ComplexMatrix::operator*(const ComplexMatrix& cm) {

    if (col != cm.lines) {
        throw invalid_argument("Number of columns in the first matrix must match the number of rows in the second matrix.");
    }

    ComplexMatrix result;
    result.lines = lines;
    result.col = cm.col;
    result.mat = new Complex*[lines];
    for (int i = 0; i < lines; ++i) {
        result.mat[i] = new Complex[cm.col];
        for (int j = 0; j < cm.col; ++j) {
            result.mat[i][j] = Complex();  // Initialize result matrix element to 0
            for (int k = 0; k < col; ++k) {
                result.mat[i][j] = result.mat[i][j] + (mat[i][k] * cm.mat[k][j]);
            }
        }
    }
    return result;
}
ComplexMatrix ComplexMatrix::module() const {
    ComplexMatrix result;
    result.lines = lines;
    result.col = col;
    result.mat = new Complex*[lines];

    for(int i = 0; i < lines; ++i) {
        result.mat[i] = new Complex[col];
        for(int j = 0; j < col; ++j) {
            double absSquared = mat[i][j].AbsSquared();
            result.mat[i][j] = Complex(absSquared, 0); // Imaginary part is 0
        }
    }

    return result;
}