#include "matrix.hpp"
#include "linear_algebra.hpp"
#include <gtest/gtest.h>

TEST(MatrixManipulationTest, Given3by3Matrix_WhenGettingSubMatrix2x2_ThenMatrixReturnHasCorrectSize) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;
 
    size_t start_row = 1;
    size_t start_column = 1;
    size_t sub_rows = 2;
    size_t sub_columns = 2;

    Matrix B = getSubMatrix(A, start_row, start_column, sub_rows, sub_columns);

    size_t expected_rows = 2;
    size_t expected_columns = 2;

    ASSERT_EQ(expected_rows, B.getRows());
    ASSERT_EQ(expected_columns, B.getColumns());
}

TEST(MatrixManipulationTest, Given3by3Matrix_WhenGettingSubMatrix2x2_ThenMatrixReturnMatrixWithCorrectElements) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;
 
    size_t start_row = 1;
    size_t start_column = 1;
    size_t sub_rows = 2;
    size_t sub_columns = 2;

    Matrix B = getSubMatrix(A, start_row, start_column, sub_rows, sub_columns);

    Matrix expected(2, 2);
    expected(0, 0) = 5.0; expected(0, 1) = 6.0;
    expected(1, 0) = 8.0; expected(1, 1) = 9.0;

    ASSERT_TRUE(expected == B);
}

TEST(MatrixManipulationTest, Given3by3Matrix_WhenGettingRow_ThenMatrixReturnMatrixWithCorrectElements) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;
 
    size_t row_i = 1;

    Matrix B = getRow(A, row_i);

    Matrix expected(1, 3);
    expected(0, 0) = 4.0; expected(0, 1) = 5.0; expected(0, 2) = 6.0; 

    ASSERT_TRUE(expected == B);
}

TEST(MatrixManipulationTest, Given3by3Matrix_WhenGettingColumn_ThenMatrixReturnMatrixWithCorrectElements) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;
 
    size_t column_j = 0;

    Matrix B = getColumn(A, column_j);

    Matrix expected(3, 1);
    expected(0, 0) = 1.0; 
    expected(1, 0) = 4.0; 
    expected(2, 0) = 7.0; 

    ASSERT_TRUE(expected == B);
}

TEST(MatrixManipulationTest, Given3by3Matrix_WhenSettingSubmatrix_ThenMatrixReturnedWithCorrectSize) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;

    Matrix B(2, 2);
    B(0, 0) = 10.0; B(0, 1) = 11.0;
    B(1, 0) = 12.0; B(1, 1) = 13.0;
 
    size_t start_row = 1;
    size_t start_column = 1;
    size_t sub_rows = 2;
    size_t sub_columns = 2;    
    
    setSubMatrix(A, B, start_row, start_column, sub_rows, sub_columns);

    size_t expected_rows = 3;
    size_t expected_columns = 3;
    
    ASSERT_EQ(expected_rows, A.getRows());
    ASSERT_EQ(expected_columns, A.getColumns()); 
}

TEST(MatrixManipulationTest, Given3by3Matrix_WhenSettingSubmatrix_ThenMatrixReturnedWithCorrectElements) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;

    Matrix B(2, 2);
    B(0, 0) = 10.0; B(0, 1) = 11.0;
    B(1, 0) = 12.0; B(1, 1) = 13.0;
 
    size_t start_row = 1;
    size_t start_column = 1;
    size_t sub_rows = 2;
    size_t sub_columns = 2;    
    
    setSubMatrix(A, B, start_row, start_column, sub_rows, sub_columns);

    Matrix expected(3, 3);
    expected(0, 0) = 1.0; expected(0, 1) = 2.0; expected(0, 2) = 3.0;
    expected(1, 0) = 4.0; expected(1, 1) = 10.0; expected(1, 2) = 11.0;
    expected(2, 0) = 7.0; expected(2, 1) = 12.0; expected(2, 2) = 13.0;
    
    ASSERT_TRUE(expected == A);
}

TEST(MatrixManipulationTest, Given3by3Matrix_WhenSettingRow_ThenMatrixReturnedWithCorrectElements) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;

    Matrix B(1, 3);
    B(0, 0) = 10.0; B(0, 1) = 11.0; B(0, 2) = 12.0;
 
    size_t row_i = 1;    
    
    setRow(A, B, row_i);

    Matrix expected(3, 3);
    expected(0, 0) = 1.0; expected(0, 1) = 2.0; expected(0, 2) = 3.0;
    expected(1, 0) = 10.0; expected(1, 1) = 11.0; expected(1, 2) = 12.0;
    expected(2, 0) = 7.0; expected(2, 1) = 8.0; expected(2, 2) = 9.0;
    
    ASSERT_TRUE(expected == A);
}

TEST(MatrixManipulationTest, Given3by3Matrix_WhenSettingColumn_ThenMatrixReturnedWithCorrectElements) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;

    Matrix B(3, 1);
    B(0, 0) = 10.0;
    B(1, 0) = 11.0; 
    B(2, 0) = 12.0;
 
    size_t column_j = 1;
    
    setColumn(A, B, column_j);

    Matrix expected(3, 3);
    expected(0, 0) = 1.0; expected(0, 1) = 10.0; expected(0, 2) = 3.0;
    expected(1, 0) = 4.0; expected(1, 1) = 11.0; expected(1, 2) = 6.0;
    expected(2, 0) = 7.0; expected(2, 1) = 12.0; expected(2, 2) = 9.0;
    
    ASSERT_TRUE(expected == A);
}

TEST(MatrixManipulationTest, Given3by3Matrix_WhenStichingMatricesHorizontally_ThenMatrixReturnedWithCorrectSize) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;

    Matrix B(3, 1);
    B(0, 0) = 10.0;
    B(1, 0) = 11.0; 
    B(2, 0) = 12.0;
 
    size_t column_j = 1;
    
    Matrix C = stitchMatricesHorizontally(A, B);

    size_t expected_rows = 3;
    size_t expected_columns = 4;

    ASSERT_EQ(expected_rows, C.getRows());
    ASSERT_EQ(expected_columns, C.getColumns());
}

TEST(MatrixManipulationTest, Given3by3Matrix_WhenStichingMatricesHorizontally_ThenMatrixReturnedWithCorrectElements) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;

    Matrix B(3, 1);
    B(0, 0) = 10.0;
    B(1, 0) = 11.0; 
    B(2, 0) = 12.0;
 
    size_t column_j = 1;
    
    Matrix C = stitchMatricesHorizontally(A, B);

    Matrix expected(3, 4);
    expected(0, 0) = 1.0; expected(0, 1) = 2.0; expected(0, 2) = 3.0; expected(0, 3) = 10.0;
    expected(1, 0) = 4.0; expected(1, 1) = 5.0; expected(1, 2) = 6.0; expected(1, 3) = 11.0;
    expected(2, 0) = 7.0; expected(2, 1) = 8.0; expected(2, 2) = 9.0; expected(2, 3) = 12.0;
    
    ASSERT_TRUE(expected == C);
}
