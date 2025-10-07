#include <iostream>
#include "matrix.hpp"
#include "linear_algebra.hpp"
#include "matrix_utils.hpp"



#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
int main() 
{

    std::cout << "Hello, Matrix Library!" << std::endl;

    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;


    std::cout << "Matrix A:" << std::endl;
    size_t rank = computeRank(A);
    std::cout << convert_matrix_to_string(A, 6) << std::endl;
    std::cout << "Rank: " << rank << std::endl;

    return 0;
}