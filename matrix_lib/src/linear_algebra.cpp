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
        assert(!are_doubles_nearly_equal(computeVectorNormSquared(vector), 0.0, 1e-9));
        double norm = computeVectorNorm(vector);
        Matrix unit_vector(vector);
        return unit_vector / norm;
    }

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