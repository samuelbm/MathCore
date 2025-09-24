#include "matrix.hpp"
#include <algorithm>
#include <cstring>

Matrix::Matrix(size_t rows, size_t columns)
    : rows(rows), columns(columns), data(new double[rows * columns]()) 
{

}

Matrix::Matrix(const Matrix& other)
    : rows(other.rows), columns(other.columns), data(new double[other.rows * other.columns]) {
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


// size_t Matrix::getRows() const
// {

// }

// size_t Matrix::getColumns() const
// {
    
// }

// double Matrix::operator()(size_t row_i, size_t column_j)
// {

// }

// double& Matrix::operator()(size_t row_i, size_t column_j) const
// {

// }

// bool Matrix::operator==(Matrix const& other) const
// {

// }

// bool Matrix::operator!=(Matrix const& other) const
// {

// }

// Matrix& Matrix::operator*=(double scalar)
// {

// }

// Matrix Matrix::operator*(double scalar) const
// {

// }

// Matrix& Matrix::operator/=(double scalar)
// {

// }

// Matrix Matrix::operator/(double scalar) const
// {

// }

// Matrix& Matrix::operator+=(Matrix const& other)
// {

// }

// Matrix Matrix::operator+(Matrix const& other) const
// {
    
// }

// Matrix& Matrix::operator-=(Matrix const& other)
// {

// }

// Matrix Matrix::operator-(Matrix const& other) const
// {

// }

// Matrix& Matrix::operator*=(Matrix const& other)
// {

// }

// Matrix Matrix::operator*(Matrix const& other) const
// {

// }

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

}

double Matrix::operator[](size_t index)
{

}

double& Matrix::operator[](size_t index) const
{
    
}