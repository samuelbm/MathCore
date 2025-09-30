#include "matrix.hpp"
#include <iostream>

bool are_doubles_nearly_equal(double a, double b, double threshold=1e-9);

std::string convert_matrix_to_string(Matrix const& matrix, size_t precision=3);
static void compute_maximum_number_of_digits(Matrix const& matrix, size_t& max_magnitude, size_t& min_magnitude, size_t precision);
static void compute_number_of_digits(double value, size_t& max_magnitude, size_t& min_magnitude, size_t precision);
static void format_all_matrix_entries(Matrix const& matrix, size_t max_magnitude, size_t min_magnitude, size_t precision, std::ostringstream& oss);
static void format_matrix_entry(double value, size_t max_magnitude, size_t min_magnitude, size_t precision, std::ostringstream& oss);