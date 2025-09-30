#include "matrix.hpp"
#include "matrix_utils.hpp"
#include "math_utils.hpp"
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>

Matrix::Matrix(size_t rows, size_t columns)
    : rows(rows), columns(columns), data(new double[rows * columns]()) 
{
    assert(rows != 0);
    assert(columns != 0);
}

Matrix::Matrix(const Matrix& other)
    : rows(other.rows), columns(other.columns), data(new double[other.rows * other.columns]) 
{
    std::copy(other.data, other.data + rows * columns, data);
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        delete[] data;
        rows = other.rows;
        columns = other.columns;
        data = new double[rows * columns];
        std::copy(other.data, other.data + rows * columns, data);
    }
    return *this;
}

Matrix::~Matrix() {
    delete[] data;
}


size_t Matrix::getRows() const
{
    return rows;
}

size_t Matrix::getColumns() const
{
    return columns;
}

double Matrix::operator()(size_t row_i, size_t column_j) const
{
    return data[index(row_i, column_j)];
}

double& Matrix::operator()(size_t row_i, size_t column_j)
{
    return data[index(row_i, column_j)];
}

bool Matrix::operator==(Matrix const& other) const
{  
    if (rows != other.rows || columns != other.columns) {
        return false;
    }

    size_t number_of_elements = rows * columns;
    for (size_t i = 0; i < number_of_elements; ++i) 
    {
        if(!are_doubles_nearly_equal(data[i], other.data[i], error_threshold))
        // if(std::fabs(data[i] - other.data[i]) > error_threshold)
        {
            std::cout << "data[i]: " << data[i] << ", other.data[i]: " << other.data[i] << ", fabs: " << std::fabs(data[i] - other.data[i]) << std::endl; // --- IGNORE ---
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(Matrix const& other) const
{
    return !(*this == other);
}

Matrix& Matrix::operator*=(double scalar)
{
    size_t number_of_elements = rows * columns;
    for (size_t i = 0; i < number_of_elements; ++i) 
    {
        data[i] *= scalar;
    }
    return *this;
}

Matrix Matrix::operator*(double scalar) const
{
    Matrix result(*this);
    result *= scalar;
    return result;
}

Matrix& Matrix::operator/=(double scalar)
{
    assert(std::abs(scalar) > error_threshold);
    return *this *= (1.0 / scalar);
}

Matrix Matrix::operator/(double scalar) const
{
    assert(std::abs(scalar) > error_threshold);
    Matrix result(*this);
    result /= scalar;
    return result;
}

Matrix& Matrix::operator+=(Matrix const& other)
{
    assert(rows == other.rows);
    assert(columns == other.columns);
    size_t number_of_elements = rows * columns;
    for (size_t i = 0; i < number_of_elements; ++i) 
    {
        data[i] += other.data[i];
    }   
    return *this;
}

Matrix Matrix::operator+(Matrix const& other) const
{
    assert(rows == other.rows);
    assert(columns == other.columns);
    Matrix result(*this);
    result += other;
    return result;
}

Matrix& Matrix::operator-=(Matrix const& other)
{
    assert(rows == other.rows);
    assert(columns == other.columns);
    size_t number_of_elements = rows * columns;
    for (size_t i = 0; i < number_of_elements; ++i) 
    {
        data[i] -= other.data[i];   
    }
    return *this;
}

Matrix Matrix::operator-(Matrix const& other) const
{
    assert(rows == other.rows);
    assert(columns == other.columns);
    Matrix result(*this);
    result -= other;
    return result;
}

Matrix& Matrix::operator*=(Matrix const& other)
{
    assert(columns == other.rows);
    Matrix result(rows, other.columns);
    for (size_t row_i=0; row_i < rows; ++row_i)
    {
        for (size_t column_j=0; column_j < other.columns; ++column_j)
        {
            double sum = 0.0;
            for (size_t k=0; k < columns; ++k)
            {
                sum += (*this)(row_i, k) * other(k, column_j);
            }
            result(row_i, column_j) = sum;
        }
    }
    *this = result;
    return *this;
}

Matrix Matrix::operator*(Matrix const& other) const
{
    assert(columns == other.rows);
    Matrix result(*this);
    result *= other;
    return result;
}

void Matrix::swapRows(size_t row_i, size_t row_j)
{
    assert(row_i < rows);
    assert(row_j < rows);
    assert(row_i != row_j);
    for (size_t column = 0; column < columns; ++column) 
    {
        std::swap((*this)(row_i, column), (*this)(row_j, column));
    }
}

void Matrix::scaleRow(size_t row_i, double scale_factor)
{
    assert(row_i < rows);
    for (size_t column = 0; column < columns; ++column) 
    {
        (*this)(row_i, column) *= scale_factor;
    }
}

void Matrix::reduceRow(size_t target_row, size_t source_row)
{
    assert(target_row < rows);
    assert(source_row < rows);
    assert(target_row != source_row);
    for (size_t column_j = 0; column_j < columns; ++column_j) 
    {
        (*this)(target_row, column_j) -= (*this)(source_row, column_j);
    }
}

size_t Matrix::find_pivot_row(size_t column_j)
{
    assert(column_j < columns);
    assert(column_j < rows);
    size_t pivot_row = column_j;
    double pivot = (*this)(column_j, column_j);
    for(size_t row_i= column_j + 1; row_i < rows; row_i++)
    {
        double candidate_pivot = (*this)(row_i, column_j);
        if(std::fabs(candidate_pivot) > std::fabs(pivot))
        {
            pivot = candidate_pivot;
            pivot_row = row_i;
        }
    }

    return pivot_row;
}

Matrix Matrix::fill(size_t rows, size_t columns, double value)
{
    Matrix result = Matrix(rows, columns);
    size_t number_of_elements = rows * columns;
    std::fill(result.data, result.data + number_of_elements, value);
    return result;
}

Matrix Matrix::identity(size_t size)
{
    Matrix result = Matrix::fill(size, size, 0.0);
    for (size_t i = 0; i < size; ++i)
    {
        result(i, i) = 1.0; 
    }
    return result;
}

Matrix Matrix::homogeneousRotation2D(double angle_degrees)
{
    Matrix result = Matrix::identity(3);
    double angle_radians = angle_degrees * M_PI / 180.0;
    double cos = std::cos(angle_radians);
    double sin = std::sin(angle_radians);
    result(0, 0) = cos; result(0, 1) = -sin;
    result(1, 0) = sin; result(1, 1) = cos; 
    return result;
}

Matrix Matrix::homogeneousScaling2D(double scale_factor_x, double scale_factor_y)
{
    Matrix result = Matrix::identity(3);
    result(0, 0) = scale_factor_x;
    result(1, 1) = scale_factor_y;
    return result;
}

Matrix Matrix::homogeneousTranslation2D(double translation_x, double translation_y)
{
    Matrix result = Matrix::identity(3);
    result(0, 2) = translation_x;
    result(1, 2) = translation_y;
    return result;
}

Matrix Matrix::homogeneousRotationX3D(double angle_degrees)
{
    Matrix result = Matrix::identity(4);
    double angle_radians = angle_degrees * M_PI / 180.0;
    double cos = std::cos(angle_radians);
    double sin = std::sin(angle_radians);
    result(1, 1) = cos; result(1, 2) = -sin;
    result(2, 1) = sin; result(2, 2) = cos; 
    return result;
}

Matrix Matrix::homogeneousRotationY3D(double angle_degrees)
{
    Matrix result = Matrix::identity(4);
    double angle_radians = angle_degrees * M_PI / 180.0;
    double cos = std::cos(angle_radians);
    double sin = std::sin(angle_radians);
    result(0, 0) = cos; result(0, 2) = sin;
    result(2, 0) = -sin; result(2, 2) = cos; 
    return result;
}

Matrix Matrix::homogeneousRotationZ3D(double angle_degrees)
{
    Matrix result = Matrix::identity(4);
    double angle_radians = angle_degrees * M_PI / 180.0;
    double cos = std::cos(angle_radians);
    double sin = std::sin(angle_radians);
    result(0, 0) = cos; result(0, 1) = -sin;
    result(1, 0) = sin; result(1, 1) = cos; 
    return result;
}

Matrix Matrix::homogeneousScaling3D(double scale_factor_x, double scale_factor_y, double scale_factor_z)
{
    Matrix result = Matrix::identity(4);
    result(0, 0) = scale_factor_x;
    result(1, 1) = scale_factor_y;
    result(2, 2) = scale_factor_z;
    return result;
}

Matrix Matrix::homogeneousTranslation3D(double translation_x, double translation_y, double translation_z)
{
    Matrix result = Matrix::identity(4);
    result(0, 3) = translation_x;
    result(1, 3) = translation_y;
    result(2, 3) = translation_z;
    return result;
}

size_t Matrix::index(size_t row_i, size_t column_j) const
{
    assert(row_i < rows);
    assert(column_j < columns);
    return row_i * columns + column_j;
}

double Matrix::operator[](size_t index) const
{
    return data[index];
}

double& Matrix::operator[](size_t index)
{
    return data[index];
}