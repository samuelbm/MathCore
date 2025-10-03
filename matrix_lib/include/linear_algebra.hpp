    #include "matrix.hpp"

    Matrix getSubMatrix(Matrix const& base_matrix, size_t start_row, size_t start_column, size_t sub_rows, size_t sub_columns);
    Matrix getRow(Matrix const& base_matrix, size_t row_i);
    Matrix getColumn(Matrix const& base_matrix, size_t column_j);
    void setSubMatrix(Matrix& base_row, Matrix const& sub_matrix, size_t start_row, size_t start_column, size_t sub_rows, size_t sub_columns);
    void setRow(Matrix& base_matrix, Matrix const& row_matrix, size_t row_i);
    void setColumn(Matrix& base_matrix, Matrix const& column_matrix, size_t column_j);
    Matrix stitchMatricesHorizontally(Matrix const& left_matrix, Matrix const& right_matrix); 
    
    bool isVector(Matrix const& vector);
    double computeVectorNormSquared(Matrix const& vector);
    double computeVectorDotProduct(Matrix const& vector_a, Matrix const& vector_b);
    double computeVectorNorm(Matrix const& vector);
    Matrix computeVectorCrossProduct(Matrix const& vector3D_a, Matrix const& vector3D_b);
    Matrix computeUnitVector(Matrix const& vector);

    Matrix computeTranspose(Matrix const& matrix);
    Matrix exponentiate(Matrix const& square_matrix, size_t exponent);
    Matrix rowReducedEchelonForm(Matrix & matrix);
    double computeRank(Matrix const& matrix);
    Matrix solveLinearSystem(Matrix const& square_matrix_A, Matrix const& vector_b);
    Matrix computeInverse(Matrix const& square_matrix, Matrix& result_matrix);
    double computeDeterminant(Matrix const& square_matrix);