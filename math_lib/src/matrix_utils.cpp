#include "matrix_utils.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

bool are_doubles_nearly_equal(double a, double b, double threshold)
{
    return std::fabs(a - b) < threshold;
}

std::string convert_matrix_to_string(Matrix const& matrix, size_t precision)
{
    std::ostringstream oss;
    size_t max_magnitude = 0;
    size_t min_magnitude = 0;
    compute_maximum_number_of_digits(matrix, max_magnitude, min_magnitude, precision);

    format_all_matrix_entries(matrix, max_magnitude, min_magnitude, precision, oss);
    return oss.str();
}

void compute_maximum_number_of_digits(Matrix const& matrix, size_t& max_magnitude, size_t& min_magnitude, size_t precision)
{
    max_magnitude = 0;
    min_magnitude = 0;
    size_t single_max_magnitude = 0;
    size_t single_min_magnitude = 0;
    for(size_t row_i=0; row_i < matrix.getRows(); ++row_i)
    {
        for(size_t column_j = 0; column_j < matrix.getColumns(); ++column_j)
        {
            compute_number_of_digits(matrix(row_i, column_j), single_max_magnitude, single_min_magnitude, precision);
            max_magnitude = std::max(max_magnitude, single_max_magnitude);
            min_magnitude = std::max(min_magnitude, single_min_magnitude);
        }
    }
}

void compute_number_of_digits(double value, size_t& max_magnitude, size_t& min_magnitude, size_t precision)
{
    max_magnitude = 0;
    min_magnitude = 0;
    
    if(value == 0.0)
    {
        return;
    }
    
    if(value < 0.0)
    {
        max_magnitude++;
        value = -value;
    }

    int number_of_digits = (int) std::floor(std::log10(value)) + 1;
    if(number_of_digits <= 0)
    {
        min_magnitude += (size_t) ((int) precision + 1 - number_of_digits);
    }
    else if(number_of_digits > 0 && number_of_digits < (int) precision)
    {
        max_magnitude += (size_t) number_of_digits;
        min_magnitude += (size_t) ((int) precision + 1 - number_of_digits);
    }
    else
    {
        max_magnitude += (size_t) number_of_digits;
    }
}

void format_all_matrix_entries(Matrix const& matrix, size_t max_magnitude, size_t min_magnitude, size_t precision, std::ostringstream& oss)
{
    oss << std::endl;
    for(size_t row_i=0; row_i < matrix.getRows(); ++row_i)
    {
        for(size_t column_j = 0; column_j < matrix.getColumns(); ++column_j)
        {
            format_matrix_entry(matrix(row_i, column_j), max_magnitude, min_magnitude, precision, oss);
            oss << " ";
        }
        oss << std::endl;
    }
}

void format_matrix_entry(double value, size_t max_magnitude, size_t min_magnitude, size_t precision, std::ostringstream& oss)
{
    size_t local_max_magnitude;
    size_t local_min_magnitude;
    compute_number_of_digits(value, local_max_magnitude, local_min_magnitude, precision);

    for(size_t i = 0; i < max_magnitude - local_max_magnitude; ++i)
    {
        oss << " ";
    }

    bool is_negative = (value < 0.0);
    if(is_negative)
    {
        oss << "-";
        value = -value;
        local_max_magnitude--;
    }

    for(int i = (int) local_max_magnitude-1; i >= 0; --i)
    {
        int digit = (int) (value / std::pow(10.0, i));
        oss << digit;
        value -= digit * std::pow(10.0, i);
    }

    if(min_magnitude > 0)
    {
        oss << ".";

        for(size_t i = 1; i < min_magnitude; ++i)
        {
            value *= 10.0;
            int digit = (int) value;
            oss << digit;
            value -= digit;
        }
    }
}