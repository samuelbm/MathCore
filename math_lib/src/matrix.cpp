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
    return *this;
}

Matrix Matrix::operator+(Matrix const& other) const
{
    
}

Matrix& Matrix::operator-=(Matrix const& other)
{

}

Matrix Matrix::operator-(Matrix const& other) const
{

}

Matrix& Matrix::operator*=(Matrix const& other)
{

}

Matrix Matrix::operator*(Matrix const& other) const
{

}

// void Matrix::swapRows(size_t row_i, size_t row_j)
// {

// }

// void Matrix::scaleRow(size_t row_i, double scale_factor)
// {

// }

// void Matrix::reduceRow(size_t target_row, size_t source_row)
// {

// }

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