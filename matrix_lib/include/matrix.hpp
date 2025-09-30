#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <cstddef> 

class Matrix {
public:
    Matrix(size_t rows, size_t columns);
    Matrix(Matrix const& other);
    Matrix& operator=(Matrix const& other);
    ~Matrix();
    size_t getRows() const;
    size_t getColumns() const;

    double operator()(size_t row_i, size_t column_j) const;
    double& operator()(size_t row_i, size_t column_j);

    bool operator==(Matrix const& other) const;
    bool operator!=(Matrix const& other) const;

    Matrix& operator*=(double scalar);
    Matrix operator*(double scalar) const;
    Matrix& operator/=(double scalar);
    Matrix operator/(double scalar) const;

    Matrix& operator+=(Matrix const& other);
    Matrix operator+(Matrix const& other) const;
    Matrix& operator-=(Matrix const& other);
    Matrix operator-(Matrix const& other) const;
    Matrix& operator*=(Matrix const& other);
    Matrix operator*(Matrix const& other) const;

    void swapRows(size_t row_i, size_t row_j);
    void scaleRow(size_t row_i, double scale_factor);
    void reduceRow(size_t target_row, size_t source_row);
    size_t find_pivot_row(size_t column_j);

    static Matrix fill(size_t rows, size_t columns, double value=0.0);
    static Matrix identity(size_t size);
    
    static Matrix homogeneousRotation2D(double angle_degrees);
    static Matrix homogeneousScaling2D(double scale_factor_x, double scale_factor_y);
    static Matrix homogeneousTranslation2D(double translation_x, double translation_y);

    static Matrix homogeneousRotationX3D(double angle_degrees);
    static Matrix homogeneousRotationY3D(double angle_degrees);
    static Matrix homogeneousRotationZ3D(double angle_degrees);
    static Matrix homogeneousScaling3D(double scale_factor_x, double scale_factor_y, double scale_factor_z);
    static Matrix homogeneousTranslation3D(double translation_x, double translation_y, double translation_z);

private:
    size_t index(size_t row_i, size_t column_j) const;
    double operator[](size_t index) const;
    double& operator[](size_t index);
    

private: 
    size_t rows;
    size_t columns;   
    double* data;
    static constexpr double error_threshold = 1e-9;
};

#endif // CALCULATOR_HPP