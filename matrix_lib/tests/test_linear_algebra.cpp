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

TEST(MatrixIsSquareTest, GivenSquareMatrix_WhenTestingForSaqure_ThenReturnTrue) {
    Matrix A = Matrix::identity(3);
    ASSERT_TRUE(isMatrixSquare(A));
}

TEST(MatrixIsSquareTest, GivenRectangleMatrix_WhenTestingForSaqure_ThenReturnFalse) {
    Matrix A(3, 2);
    ASSERT_FALSE(isMatrixSquare(A));
}

TEST(MatrixManipulationTest, GivenSquareMatrix_WhenComputingMinor_ThenReturnMinor) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;
 
    size_t row_excluded = 1;
    size_t column_excluded = 1;

    Matrix minor = getMinor(A, row_excluded, column_excluded);

    Matrix expected(2, 2);
    expected(0, 0) = 1.0; expected(0, 1) = 3.0;
    expected(1, 0) = 7.0; expected(1, 1) = 9.0;

    ASSERT_TRUE(expected == minor);
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

TEST(MatrixVectorTest, GivenAVector_WhenTestingIfVector_ThenReturnTrue) {
    Matrix A(3, 1);
    A(0, 0) = 1.0;
    A(1, 0) = 2.0;
    A(2, 0) = 3.0;
    
    ASSERT_TRUE(isVector(A));
}

TEST(MatrixVectorTest, GivenANoneVector_WhenTestingIfVector_ThenReturnFalse) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;
    
    ASSERT_FALSE(isVector(A));
}

TEST(MatrixVectorTest, GivenTwoVectors_WhenTestingDotProduct_ThenReturnDotProduct) {
    Matrix A(3, 1);
    A(0, 0) = 1.0;
    A(1, 0) = 2.0;
    A(2, 0) = 3.0;

    Matrix B(3, 1);
    B(0, 0) = 3.0;
    B(1, 0) = 2.0;
    B(2, 0) = 1.0;

    double scalar_product = computeVectorDotProduct(A, B);

    double expected = 10.0;
    
    ASSERT_NEAR(expected, scalar_product, 1e-9);
}

TEST(MatrixVectorTest, GivenAVector_WhenTestingNormSquared_ThenReturnNormSquared) {
    Matrix A(3, 1);
    A(0, 0) = 2.0;
    A(1, 0) = 3.0;
    A(2, 0) = 6.0;

    double norm_squared = computeVectorNormSquared(A);

    double expected = 49.0;
    
    ASSERT_NEAR(expected, norm_squared, 1e-9);
}

TEST(MatrixVectorTest, GivenAVector_WhenTestingNorm_ThenReturnNorm) {
    Matrix A(3, 1);
    A(0, 0) = 2.0;
    A(1, 0) = 3.0;
    A(2, 0) = 6.0;

    double norm = computeVectorNorm(A);

    double expected = 7.0;
    
    ASSERT_NEAR(expected, norm, 1e-9);
}

TEST(MatrixVectorTest, GivenTwoVectors_WhenTestingCrossProduct_ThenReturnVector) {
    Matrix A(3, 1);
    A(0, 0) = 1.0;
    A(1, 0) = 2.0;
    A(2, 0) = 3.0;

    Matrix B(3, 1);
    B(0, 0) = 4.0;
    B(1, 0) = 5.0;
    B(2, 0) = 6.0;

    Matrix cross_product = computeVectorCrossProduct(A, B);

    Matrix expected(3, 1);
    expected(0, 0) = -3.0;
    expected(1, 0) = 6.0;
    expected(2, 0) = -3.0;
    
    ASSERT_TRUE(expected == cross_product);
}

TEST(MatrixVectorTest, GivenAVector_WhenTestingUnit_ThenReturnUnitVector) {
    Matrix A(3, 1);
    A(0, 0) = 2.0;
    A(1, 0) = 3.0;
    A(2, 0) = 6.0;

    Matrix unit = computeUnitVector(A);

    Matrix expected(3, 1);
    expected(0, 0) = 2.0/7.0;
    expected(1, 0) = 3.0/7.0;
    expected(2, 0) = 6.0/7.0;
    
    ASSERT_TRUE(expected == unit);
}

TEST(MatrixTransposeTest, GivenAMatrix_WhenTestingTranspose_ThenReturnTransposedMatrix) {
    Matrix A(3, 2);
    A(0, 0) = 1.0; A(0, 1) = 4.0;
    A(1, 0) = 2.0; A(1, 1) = 5.0;
    A(2, 0) = 3.0; A(2, 1) = 6.0;

    Matrix transposed = computeTranspose(A);

    Matrix expected(2, 3);
    expected(0, 0) = 1.0; expected(0, 1) = 2.0; expected(0, 2) = 3.0;
    expected(1, 0) = 4.0; expected(1, 1) = 5.0; expected(1, 2) = 6.0;
    
    ASSERT_TRUE(expected == transposed);
}

TEST(MatrixRREFTest, GivenAMatrix_WhenTestingRREF_ThenReturnRREFMatrix) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;

    rowReducedEchelonForm(A);

    Matrix expected(3, 3);
    expected(0, 0) = 1.0; expected(0, 1) = 0.0; expected(0, 2) = -1.0;
    expected(1, 0) = 0.0; expected(1, 1) = 1.0; expected(1, 2) = 2.0;
    expected(2, 0) = 0.0; expected(2, 1) = 0.0; expected(2, 2) = 0.0;
    
    ASSERT_TRUE(expected == A);

}

TEST(MatrixRankTest, GivenANullMatrix_WhenTestingRank_ThenReturnZero) {
    Matrix A(2, 2);
    A(0, 0) = 0.0; A(0, 1) = 0.0;
    A(1, 0) = 0.0; A(1, 1) = 0.0;

    size_t rank = computeRank(A);

    size_t expected = 0;
    
    ASSERT_EQ(expected, rank);
}

TEST(MatrixRankTest, GivenAnIdentityMatrix_WhenTestingRank_ThenReturnFullRank) {
    Matrix A = Matrix::identity(4);
    
    size_t rank = computeRank(A);

    size_t expected = 4;
    
    ASSERT_EQ(expected, rank);
}

TEST(MatrixRankTest, GivenRectangularMatrixWithMLesserThanN_WhenTestingRank_ThenReturnRank) {
    Matrix A(2, 3);
    A(0, 0) = 0.0; A(0, 1) = 1.0; A(0, 2) = 0.0;
    A(1, 0) = 0.0; A(1, 1) = 0.0; A(1, 2) = 1.0;
    
    size_t rank = computeRank(A);

    size_t expected = 2;
    
    ASSERT_EQ(expected, rank);
}

TEST(MatrixRankTest, GivenSquareMatrix_WhenTestingRank_ThenReturnRank) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;
    
    size_t rank = computeRank(A);

    size_t expected = 2;
    
    ASSERT_EQ(expected, rank);
}

TEST(MatrixInvertibleTest, GivenSquareMatrix_WhenNoneSingular_ThenReturnTrue) {
    Matrix A = Matrix::identity(3);
    ASSERT_TRUE(isMatrixInvertible(A));
}

TEST(MatrixInvertibleTest, GivenSquareMatrix_WhenSingular_ThenReturnFalse) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    A(2, 0) = 7.0; A(2, 1) = 8.0; A(2, 2) = 9.0;
    
    ASSERT_FALSE(isMatrixInvertible(A));
}

TEST(MatrixSolveLinearSystemTest, GivenEquationSystem_WhenSolvingSystem_ThenReturnSolutionVector) {
    Matrix A(3, 3);
    A(0, 0) = 3.0; A(0, 1) = 2.0; A(0, 2) = 1.0;
    A(1, 0) = 6.0; A(1, 1) = 2.0; A(1, 2) = 0.0;
    A(2, 0) = 12.0; A(2, 1) = 6.0; A(2, 2) = -1.0;
    
    Matrix b(3, 1);
    b(0, 0) = 3.0;
    b(1, 0) = 3.0;
    b(2, 0) = 6.0;

    Matrix x = solveLinearSystem(A, b);

    Matrix expected(3, 1);
    expected(0, 0) = 1.0/3.0;
    expected(1, 0) = 1.0/2.0;
    expected(2, 0) = 1.0/1.0;
    
    ASSERT_TRUE(expected == x);
}

TEST(MatrixComputeInverseTest, GivenSquareMatrix_WhenComputingInverse_ThenReturnInverseMatrix) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 0.0; A(1, 1) = 1.0; A(1, 2) = 4.0;
    A(2, 0) = 5.0; A(2, 1) = 6.0; A(2, 2) = 0.0;
    
    Matrix inverse = computeInverse(A);
    
    Matrix expected(3, 3);
    expected(0, 0) = -24.0; expected(0, 1) = 18.0; expected(0, 2) = 5.0;
    expected(1, 0) = 20.0; expected(1, 1) = -15.0; expected(1, 2) = -4.0;
    expected(2, 0) = -5.0; expected(2, 1) = 4.0; expected(2, 2) = 1.0;
        
    ASSERT_TRUE(expected == inverse);
}

TEST(MatrixComputeDeterminantTest, GivenInvertibleMatrix_WhenComputingDeterminant_ThenReturnDeterminant) {
    Matrix A(4, 4);
    A(0, 0) = 1.0; A(0, 1) = 1.0; A(0, 2) = 1.0; A(0, 3) = 1.0;
    A(1, 0) = 2.0; A(1, 1) = 4.0; A(1, 2) = 6.0; A(1, 3) = 8.0;
    A(2, 0) = 3.0; A(2, 1) = 9.0; A(2, 2) = 18.0; A(2, 3) = 30.0;
    A(3, 0) = 4.0; A(3, 1) = 16.0; A(3, 2) = 40.0; A(3, 3) = 80.0;
    
    double determinant = computeDeterminant(A);
    
    double expected = 24.0;
        
    ASSERT_EQ(expected, determinant);
}

TEST(MatrixExponentiationTest, GivenASquareMatrix_WhenTestingExponentiation_ThenReturnExponentiatedMatrix) {
    Matrix A(2, 2);
    A(0, 0) = 0.9; A(0, 1) = 0.2;
    A(1, 0) = 0.1; A(1, 1) = 0.8;

    size_t exponent = 13;
    Matrix exponentiated = exponentiate(A, exponent);

    Matrix expected(2, 2);
    expected(0, 0) = 0.669896; expected(0, 1) = 0.660207;
    expected(1, 0) = 0.330104; expected(1, 1) = 0.339793;
    
    ASSERT_TRUE(expected == exponentiated);
}