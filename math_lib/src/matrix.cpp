#include "matrix.hpp"
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
        if (std::abs(data[i] - other.data[i]) > error_threshold) {
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
    for (size_t column = 0; column < columns; ++column) 
    {
        (*this)(target_row, column) -= (*this)(source_row, column);
    }
}

// Matrix Matrix::fill(size_t rows, size_t columns, double value=0.0)
// {

// }

// Matrix Matrix::identity(size_t size)
// {

// }

// Matrix Matrix::homogeneousRotation2D(double angle_degrees)
// {

// }

// Matrix Matrix::homogeneousScaling2D(double angle_degrees)
// {

// }

// Matrix Matrix::homogeneousTranslation2D(double translation_x, double translation_y)
// {

// }

// Matrix Matrix::homogeneousRotationX3D(double angle_degrees)
// {

// }

// Matrix Matrix::homogeneousRotationY3D(double angle_degrees)
// {

// }

// Matrix Matrix::homogeneousRotationZ3D(double angle_degrees)
// {

// }

// Matrix Matrix::homogeneousScaling3D(double scale_factor_x, double scale_factor_y, double scale_factor_z)
// {

// }

// Matrix Matrix::homogeneousTranslation3D(double translation_x, double translation_y, double translation_z)
// {

// }

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