#include "linear_algebra.hpp"
#include "matrix.hpp"
#include <cassert>
#include <iostream>

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

    void MatsetSubMatrix(Matrix const& base_row, Matrix const& sub_matrix, size_t start_row, size_t start_column, size_t sub_rows, size_t sub_columns, Matrix& result_matrix)
    {

    }

    void setRow(Matrix const& base_matrix, size_t row_i, Matrix& result_matrix)
    {

    }

    void setColumn(Matrix const& base_matrix, size_t column_j, Matrix& result_matrix)
    {

    }

    Matrix stitchMatricesHorizontally(Matrix const& left_matrix, Matrix const& right_matrix)
    {
        // Matrix result_matrix;
    }
    
    // bool isVector(Matrix const& vectort)
    // {

    // }
    
    // double computeVectorNormSquared(Matrix const& vector)
    // {

    // }

    // double computeVectorNorm(Matrix const& vector)
    // {

    // }

    // double computeVectorDotProduct(Matrix const& vector_a, Matrix const& vector_b)
    // {

    // }
    
    // Matrix computeVectorCrossProduct()
    // {

    // }
    
    // Matrix computeUnitVector(Matrix const& vector)
    // {

    // }

    // Matrix transpose(Matrix const& square_matrix, Matrix& result_matrix)
    // {

    // }
    
    // Matrix exponentiate(Matrix const& square_matrix, Matrix& result_matrix)
    // {

    // }

    // Matrix rowReducedEchelonForm(Matrix & matrix)
    // {

    // }
    
    // Matrix solveLinearSystem(Matrix const& square_matrix_A, Matrix const& vector_b)
    // {

    // }
    
    // Matrix computeInverse(Matrix const& square_matrix, Matrix& result_matrix)
    // {

    // }
    
    // double computeDeterminant(Matrix const& square_matrix)
    // {
        
    // }