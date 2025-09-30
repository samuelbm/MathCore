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
    Matrix A(2, 3);
    A(0, 0) = -1.0; A(0, 1) = 0.0012345; A(0, 2) = 1.0;
    A(1, 0) = 2.01; A(1, 1) = 1.0004; A(1, 2) = 12348.12355;

    std::cout << convert_matrix_to_string(A) << std::endl;

    return 0;
}