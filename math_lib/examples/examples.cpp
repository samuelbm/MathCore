#include <iostream>
#include "matrix.hpp"
#include "linear_algebra.hpp"
#include "matrix_utils.hpp"

int main() {
    Matrix mat(3, 3);


    std::cout << "3x3 Matrix initialized." << std::endl;
    Matrix A(2, 1);
    A(0, 0) = 1.0;
    A(1, 0) = 2.0;

    Matrix B(1, 2);
    B(0, 0) = 3.0; B(0, 1) = 4.0;

    Matrix expected(2, 2);
    expected(0, 0) = 3.0; expected(0, 1) = 4.0;
    expected(1, 0) = 6.0; expected(1, 1) = 8.0;

    A *= B;

    std::cout << "Matrix multiplication result:" << std::endl; 
    std::cout << A.getRows() << " " << A.getColumns() << std::endl;

    return 0;
}