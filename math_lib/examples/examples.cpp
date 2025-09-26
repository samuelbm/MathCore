#include <iostream>
#include "matrix.hpp"
#include "linear_algebra.hpp"
#include "matrix_utils.hpp"

int main() 
{
    Matrix A(2, 3);
    A(0, 0) = 1.0; A(0, 1) = 1.0; A(0, 2) = 1.0;
    A(1, 0) = 2.0; A(1, 1) = 1.0; A(1, 2) = 1.0;

    std::cout << convert_matrix_to_string(A, 3) << std::endl;

    return 0;
}