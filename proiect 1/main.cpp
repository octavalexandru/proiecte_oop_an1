#include <iostream>
#include <cstdlib>
#include "Complex.h"
#include "ComplexMatrix.h"

using namespace std;

Complex generate_complex()
{
    double r, i;
    r = rand()%99;
    i  = rand()%99;
    Complex temp(r, i);
    return temp;
}

void compmat_print(ComplexMatrix cmat[], int l)
{
    for(int i = 0; i < l; i++)
        cout << cmat[i];
}

int main() {
    // Test Complex class
    Complex c1(3, 4), c2(2, -5);
     cout << "c1: " << c1 <<  endl;
     cout << "c2: " << c2 <<  endl;
     cout << "c1 + c2: " << c1 + c2 << endl;
    cout << "c1 * c2: " << c1 * c2 << endl;

    ComplexMatrix mat1, mat2;
    cout << "mat1 (2x2):\n";
    cin >> mat1;
    cout << "mat1:\n" << mat1 << endl;

     //Input for  mat2
    cout << "mat2 (2x2):\n";
    cin >> mat2;
    cout << "mat2:\n" << mat2 << endl;

    // Test addition
    if ( mat1.get_cols() !=  mat2.get_cols() ||  mat1.get_lines() !=  mat2.get_lines()) {
        cerr << "Error: Matrices must have the same dimensions for addition." << endl;
    } else {
        ComplexMatrix sum;
//        sum =  mat1 +  mat2;
//        cout << "Suma:\n" << sum << endl;
    }

    // Test multiplication
    if ( mat1.get_cols() !=  mat2.get_lines()) {
        cerr << "Error: Number of columns in the first matrix must match the number of rows in the second matrix." << endl;
    } else {
        ComplexMatrix product;
        product =  mat1 *  mat2;
        cout << "Produs:\n" << product << endl;
    }

//    Complex ** mat = new Complex*[2];
//    for (int i = 0; i < 2; ++i) {
//         mat[i] = new Complex[2];
//        for (int j = 0; j < 2; ++j) {
//             mat[i][j] = Complex(i + 1, j + 1);
//        }
//    }

     cout << "matricea modulelor (mat2):" <<  endl;
     cout << mat2.module() <<  endl;



//    // Cleanup
//    for (int i = 0; i < 2; i++) {
//        delete[]  mat[i];
//    }
//    delete[]  mat;


//    Complex **mat3;
//    for(int i = 0; i < 2; i++)
//    {
//        mat3[i] = new Complex[2];;
//            for(int j = 0; j < 2; j++)
//                mat3[i][j] = new Complex(2);
//    }
    ComplexMatrix arr[6];
    arr[0] = mat1;
    arr[1] = mat2;

//
//    for(int i = 0; i < 4; i++)
//    {
//        arr[i].set_cols(2);
//        arr[i].set_lines(2);
//        for(int j = 0; j <2; j++)
//        {
//
//            for(int k = 0; k < 2; k++)
//            {
//                Complex** temp = new Complex*;
//                **temp = generate_complex();
//                arr[i].set_elem(j, k, temp);
//            }
//        }
//
//    }
    compmat_print(arr, 2);

    return 0;
}
