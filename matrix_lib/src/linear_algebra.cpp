#include "linear_algebra.hpp"
#include "matrix.hpp"
#include <cassert>
#include <iostream>
#include <cmath>
#include "math_utils.hpp"

    Matrix getSubMatrix(Matrix const& base_matrix, size_t start_row, size_t start_column, size_t sub_rows, size_t sub_columns)
    {
        assert(sub_rows >= 1);
        assert(sub_columns >= 1);
        assert(start_row + sub_rows <= base_matrix.getRows());
        assert(start_column + sub_columns <= base_matrix.getColumns());
        Matrix sub_matrix = Matrix(sub_rows, sub_columns);
        for(size_t row_i=0; row_i<sub_rows; row_i++)
        {
            for(size_t column_j=0; column_j<sub_columns; column_j++)
            {
                sub_matrix(row_i, column_j) = base_matrix(row_i + start_row, column_j + start_column);
            }
        }
        return sub_matrix;
    }

    Matrix getRow(Matrix const& base_matrix, size_t row_i)
    {
        size_t start_column = 0;
        size_t sub_rows = 1;
        size_t sub_columns = base_matrix.getColumns();
        return getSubMatrix(base_matrix, row_i, start_column, sub_rows, sub_columns);
    }

    Matrix getColumn(Matrix const& base_matrix, size_t column_j)
    {
        size_t start_row = 0;
        size_t sub_rows = base_matrix.getRows();
        size_t sub_columns = 1;
        return getSubMatrix(base_matrix, start_row, column_j, sub_rows, sub_columns);
    }

    bool isMatrixSquare(Matrix const& matrix)
    {
        return matrix.getRows() == matrix.getColumns();  
    }

    Matrix getMinor(Matrix const& square_matrix, size_t excluded_row, size_t excluded_column)
    {
        assert(isMatrixSquare(square_matrix));
        assert(excluded_row < square_matrix.getRows());
        assert(excluded_column < square_matrix.getColumns());
        size_t minor_size = square_matrix.getRows() - 1;
        Matrix minor(minor_size, minor_size);
        size_t minor_row = 0;
        for(size_t row_i=0; row_i<square_matrix.getRows(); row_i++)
        {
            if(row_i == excluded_row)
            {
                continue;
            }
            size_t minor_column = 0;
            for(size_t column_j=0; column_j<square_matrix.getColumns(); column_j++)
            {
                if(column_j == excluded_column)
                {
                    continue;
                }
                minor(minor_row, minor_column) = square_matrix(row_i, column_j);
                minor_column++;
            }
            minor_row++;
        }
        return minor;
    }


    void setSubMatrix(Matrix& base_matrix, Matrix const& sub_matrix, size_t start_row, size_t start_column, size_t sub_rows, size_t sub_columns)
    {
        assert(sub_rows >= 1);
        assert(sub_columns >= 1);
        assert(sub_rows <= sub_matrix.getRows());
        assert(sub_columns <= sub_matrix.getColumns());
        assert(start_row + sub_rows <= base_matrix.getRows());
        assert(start_column + sub_columns <= base_matrix.getColumns());
        for(size_t row_i=0; row_i<sub_rows; row_i++)
        {
            for(size_t column_j=0; column_j<sub_columns; column_j++)
            {
                base_matrix(row_i + start_row, column_j + start_column) = sub_matrix(row_i, column_j);
            }
        }
    }

    void setRow(Matrix& base_matrix, Matrix const& row_matrix, size_t row_i)
    {
        assert(row_matrix.getRows() == 1);
        assert(row_matrix.getColumns() == base_matrix.getColumns());
        size_t start_row = row_i;
        size_t start_column = 0;
        size_t sub_rows = 1;
        size_t sub_columns = row_matrix.getColumns(); 
        setSubMatrix(base_matrix, row_matrix, start_row, start_column, sub_rows, sub_columns);
    }

    void setColumn(Matrix& base_matrix, Matrix const& column_matrix, size_t column_j)
    {
        assert(column_matrix.getColumns() == 1);
        assert(column_matrix.getRows() == base_matrix.getRows());
        size_t start_row = 0;
        size_t start_column = column_j;
        size_t sub_rows = column_matrix.getRows();
        size_t sub_columns = 1; 
        setSubMatrix(base_matrix, column_matrix, start_row, start_column, sub_rows, sub_columns);
    }

    Matrix stitchMatricesHorizontally(Matrix const& left_matrix, Matrix const& right_matrix)
    {
        assert(left_matrix.getRows() == right_matrix.getRows());
        size_t left_columns = left_matrix.getColumns();
        size_t right_columns = right_matrix.getColumns();
        size_t rows = left_matrix.getRows();
        size_t columns = left_columns + right_columns;
        Matrix stiched_matrix(rows, columns);
        setSubMatrix(stiched_matrix, left_matrix, 0, 0, rows, left_columns);
        setSubMatrix(stiched_matrix, right_matrix, 0, left_columns, rows, right_columns); 
        return stiched_matrix;
    }
    
    bool isVector(Matrix const& vector)
    {
        return vector.getColumns() == 1;
    }
    
    double computeVectorDotProduct(Matrix const& vector_a, Matrix const& vector_b)
    {
        assert(isVector(vector_a));
        assert(isVector(vector_b));
        assert(vector_a.getRows() == vector_b.getRows());
        double scalor_product = 0.0;
        for(size_t row_i=0; row_i<vector_a.getRows(); row_i++)
        {
            scalor_product += vector_a(row_i, 0) * vector_b(row_i, 0); 
        }

        return scalor_product;
    }
    
    double computeVectorNormSquared(Matrix const& vector)
    {
        assert(isVector(vector));
        return computeVectorDotProduct(vector, vector);
    }

    double computeVectorNorm(Matrix const& vector)
    {
        return std::sqrt(computeVectorNormSquared(vector));
    }
    
    Matrix computeVectorCrossProduct(Matrix const& vector3D_a, Matrix const& vector3D_b)
    {
        assert(isVector(vector3D_a));
        assert(isVector(vector3D_b));
        assert(vector3D_a.getRows() == 3);
        assert(vector3D_b.getRows() == 3);
        Matrix cross_product(3, 1);
        cross_product(0, 0) = vector3D_a(1, 0)*vector3D_b(2, 0) - vector3D_a(2, 0)*vector3D_b(1, 0);
        cross_product(1, 0) = -(vector3D_a(0, 0)*vector3D_b(2, 0) - vector3D_a(2, 0)*vector3D_b(0, 0));
        cross_product(2, 0) = vector3D_a(0, 0)*vector3D_b(1, 0) - vector3D_a(1, 0)*vector3D_b(0, 0);
        return cross_product;
    }
    
    Matrix computeUnitVector(Matrix const& vector)
    {
        assert(isVector(vector));
        assert(!are_doubles_nearly_equal(computeVectorNormSquared(vector), 0.0, Matrix::error_threshold));
        double norm = computeVectorNorm(vector);
        Matrix unit_vector(vector);
        return unit_vector / norm;
    }

    Matrix computeTranspose(Matrix const& matrix)
    {
        Matrix transposed(matrix.getColumns(), matrix.getRows());
        for(size_t row_i=0; row_i<matrix.getRows(); row_i++)
        {
            for(size_t column_j=0; column_j<matrix.getColumns(); column_j++)
            {
                transposed(column_j, row_i) = matrix(row_i, column_j);
            }
        }    
        return transposed;
    }

    void rowReducedEchelonForm(Matrix& matrix)
    {
        size_t number_of_pivots = std::min(matrix.getRows(), matrix.getColumns());
        for(size_t pivot_index=0; pivot_index<number_of_pivots; pivot_index++)
        {
            size_t pivot_row = matrix.find_pivot_row(pivot_index);
            if(std::abs(matrix(pivot_row, pivot_index)) < Matrix::error_threshold)
            {
                continue;
            }
            if(pivot_row != pivot_index)
            {
                matrix.swapRows(pivot_index, pivot_row);
            }
            double pivot = matrix(pivot_index, pivot_index);
            matrix.scaleRow(pivot_index, 1.0 / pivot);
            for(size_t target_row=0; target_row<matrix.getRows(); target_row++)
            {
                if(target_row != pivot_index)
                {
                    double coefficient = matrix(target_row, pivot_index);
                    matrix.reduceRow(target_row, pivot_index, coefficient);
                }
            }
        }
    }
    
    size_t computeRank(Matrix const& matrix)
    {
        size_t rank = 0;
        Matrix RREF(matrix);
        rowReducedEchelonForm(RREF);
        size_t number_of_possible_pivots = std::max(RREF.getRows(), RREF.getColumns());
        size_t row = 0;
        size_t column = 0;
        for(size_t index=0; index<number_of_possible_pivots; index++)
        {
            double element = RREF(row, column);
            if(are_doubles_nearly_equal(element, 1.0, Matrix::error_threshold))
            {
                rank++;
                row++;
            }
            column++;

            if(row >= RREF.getRows() || column >= RREF.getColumns())
            {
                break;
            }
        }
        return rank;
    }

    bool isMatrixInvertible(Matrix const& square_matrix)
    {
        assert(isMatrixSquare(square_matrix));
        return computeRank(square_matrix) == square_matrix.getRows();
    }

    Matrix solveLinearSystem(Matrix const& square_matrix_A, Matrix const& vector_b)
    {
        assert(isMatrixInvertible(square_matrix_A));
        assert(isVector(vector_b));
        assert(square_matrix_A.getRows() == vector_b.getRows());
        size_t n = square_matrix_A.getRows();
        Matrix augmented_matrix = stitchMatricesHorizontally(square_matrix_A, vector_b);
        rowReducedEchelonForm(augmented_matrix);
        Matrix solution_vector = getColumn(augmented_matrix, n);
        return solution_vector;
    }
    
    Matrix computeInverse(Matrix const& square_matrix)
    {
        assert(isMatrixInvertible(square_matrix));
        size_t n = square_matrix.getRows();
        Matrix identity = Matrix::identity(n);
        Matrix augmented_matrix = stitchMatricesHorizontally(square_matrix, identity);
        rowReducedEchelonForm(augmented_matrix); 
        size_t start_row = 0; 
        size_t start_column = n; 
        size_t sub_rows = n; 
        size_t sub_columns = n;
        Matrix inversed_matrix = getSubMatrix(augmented_matrix, start_row, start_column, sub_rows, sub_columns);
        return inversed_matrix;
    }
    
    double computeDeterminant(Matrix const& square_matrix)
    {
        assert(isMatrixInvertible(square_matrix));

        size_t n = square_matrix.getRows();
        if(n == 1)
        {
            return square_matrix(0, 0);
        }
        else
        {
            double determinant = 0.0;
            for(size_t row_i=0; row_i<n; row_i++)
            {
                double factor = square_matrix(row_i, 0) * ((row_i % 2 == 0) ? 1.0 : -1.0);
                Matrix minor = getMinor(square_matrix, row_i, 0);
                double minor_determinant = computeDeterminant(minor);
                determinant += factor * minor_determinant;
            }
            return determinant;
        }
    }

    Matrix exponentiate(Matrix const& square_matrix,  size_t exponent)
    {
        assert(isMatrixSquare(square_matrix));
        Matrix exponentiated = Matrix::identity(square_matrix.getRows());
        Matrix power_of_two(square_matrix);
        if(exponent == 0)
        {
            return exponentiated;
        }
        else if(exponent == 1)
        {
            return square_matrix;
        }
        else
        {
            do
            {
                if(exponent % 2 == 1)
                {
                    exponentiated *= power_of_two;
                }
                power_of_two *= power_of_two;
                exponent >>=1;
            } while (exponent);
            return exponentiated;
        }
    }
