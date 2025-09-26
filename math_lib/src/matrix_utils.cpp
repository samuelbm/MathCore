#include "matrix_utils.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

std::string convert_matrix_to_string(Matrix const& matrix, size_t precision_digits)
{
    std::ostringstream oss;
    oss << std::endl;
    for(size_t row_i; row_i < matrix.getRows(); ++row_i)
    {
        for(size_t column_j = 0; column_j < matrix.getColumns(); ++column_j)
        {
            oss << std::to_string(matrix(row_i, column_j)) << " ";
        }
        oss << std::endl;
    }
    return oss.str();
}