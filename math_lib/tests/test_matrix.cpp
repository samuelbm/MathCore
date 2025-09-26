#include "matrix.hpp"
#include <gtest/gtest.h>

TEST(MatrixComparisonTest, GivenIdenticalMatrices_WhenComparingEquality_ThenReturnTrue) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    Matrix B(2, 2);
    B(0, 0) = 1.0; B(0, 1) = 2.0;
    B(1, 0) = 3.0; B(1, 1) = 4.0;

    ASSERT_TRUE(A == B);
}

TEST(MatrixComparisonTest, GivenDifferentValueMatrices_WhenComparingEquality_ThenReturnFalse) {
    double error = 1e-6;
    
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    Matrix B(2, 2);
    B(0, 0) = 1.0; B(0, 1) = 2.0;
    B(1, 0) = 3.0; B(1, 1) = 4.0 + error;

    ASSERT_FALSE(A == B);
}

TEST(MatrixComparisonTest, GivenDifferentSizeMatrices_WhenComparingEquality_ThenReturnFalse) {
    double error = 1e-6;
    
    Matrix A(1, 1);
    A(0, 0) = 1.0;

    Matrix B(2, 2);
    B(0, 0) = 1.0; B(0, 1) = 2.0;
    B(1, 0) = 3.0; B(1, 1) = 4.0 + error;

    ASSERT_FALSE(A == B);
}

TEST(MatrixComparisonTest, GivenIdenticalMatrices_WhenComparingInequality_ThenReturnFalse) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    Matrix B(2, 2);
    B(0, 0) = 1.0; B(0, 1) = 2.0;
    B(1, 0) = 3.0; B(1, 1) = 4.0;

    ASSERT_FALSE(A != B);
}

TEST(MatrixComparisonTest, GivenDifferentValueMatrices_WhenComparingInequality_ThenReturnTrue) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.1;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    Matrix B(2, 2);
    B(0, 0) = 1.0; B(0, 1) = 2.0;
    B(1, 0) = 3.0; B(1, 1) = 4.0;

    ASSERT_TRUE(A != B);
}

TEST(MatrixScalarTest, GivenMatrix_WhenScalarMultiplicationToSelf_ThenReturnScaledMatrix) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    double scale_factor = 2.5;
    Matrix B(2, 2);
    B(0, 0) = 1.0 * scale_factor; B(0, 1) = 2.0 * scale_factor;
    B(1, 0) = 3.0 * scale_factor; B(1, 1) = 4.0 * scale_factor;

    A *= scale_factor;

    ASSERT_TRUE(A == B);
}

TEST(MatrixScalarTest, GivenMatrix_WhenScalarMultiplicationOnSelf_ThenReturnScaledMatrix) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    double scale_factor = 2.5;
    Matrix B(2, 2);
    B(0, 0) = 1.0 * scale_factor; B(0, 1) = 2.0 * scale_factor;
    B(1, 0) = 3.0 * scale_factor; B(1, 1) = 4.0 * scale_factor;

    Matrix C = A * scale_factor;

    ASSERT_TRUE(C == B);
}

TEST(MatrixScalarTest, GivenMatrix_WhenScalarDivisionToSelf_ThenReturnScaledMatrix) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    double scale_factor = 2.5;
    Matrix B(2, 2);
    B(0, 0) = 1.0 / scale_factor; B(0, 1) = 2.0 / scale_factor;
    B(1, 0) = 3.0 / scale_factor; B(1, 1) = 4.0 / scale_factor;

    A /= scale_factor;

    ASSERT_TRUE(A == B);
}

TEST(MatrixScalarTest, GivenMatrix_WhenScalarDivisionOnSelf_ThenReturnScaledMatrix) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    double scale_factor = 2.5;
    Matrix B(2, 2);
    B(0, 0) = 1.0 / scale_factor; B(0, 1) = 2.0 / scale_factor;
    B(1, 0) = 3.0 / scale_factor; B(1, 1) = 4.0 / scale_factor;

    Matrix C = A / scale_factor;

    ASSERT_TRUE(C == B);
}

TEST(MatrixOperationTest, GivenMatrix_WhenAddedWithSelf_ThenReturnDoubledMatrix) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    double scale_factor = 2.0;
    Matrix B(2, 2);
    B(0, 0) = 1.0 * scale_factor; B(0, 1) = 2.0 * scale_factor;
    B(1, 0) = 3.0 * scale_factor; B(1, 1) = 4.0 * scale_factor;

    A += A ;

    ASSERT_TRUE(A == B);
}

TEST(MatrixOperationTest, GivenMatrix_WhenAddedToSelf_ThenReturnDoubledMatrix) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    double scale_factor = 2.0;
    Matrix B(2, 2);
    B(0, 0) = 1.0 * scale_factor; B(0, 1) = 2.0 * scale_factor;
    B(1, 0) = 3.0 * scale_factor; B(1, 1) = 4.0 * scale_factor;

    Matrix C = A + A;

    ASSERT_TRUE(C == B);
}

TEST(MatrixOperationTest, GivenMatrix_WhenSubstractedWithSelf_ThenReturnHalvedMatrix) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    double scale_factor = 2.0;
    Matrix B(2, 2);
    B(0, 0) = 1.0 * scale_factor; B(0, 1) = 2.0 * scale_factor;
    B(1, 0) = 3.0 * scale_factor; B(1, 1) = 4.0 * scale_factor;

    B -= A;

    ASSERT_TRUE(B == A);
}

TEST(MatrixOperationTest, GivenMatrix_WhenSubstractedToSelf_ThenReturnHalvedMatrix) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    double scale_factor = 2.0;
    Matrix B(2, 2);
    B(0, 0) = 1.0 * scale_factor; B(0, 1) = 2.0 * scale_factor;
    B(1, 0) = 3.0 * scale_factor; B(1, 1) = 4.0 * scale_factor;

    Matrix C = B - A;

    ASSERT_TRUE(C == A);
}

TEST(MatrixOperationTest, GivenMatrix_WhenMultiplicatingWithSelf_ThenReturnCorrectSize) {
    Matrix A(2, 1);
    A(0, 0) = 1.0;
    A(1, 0) = 2.0;

    Matrix B(1, 2);
    B(0, 0) = 3.0; B(0, 1) = 4.0;

    Matrix expected(2, 2);
    expected(0, 0) = 3.0; expected(0, 1) = 4.0;
    expected(1, 0) = 6.0; expected(1, 1) = 8.0;

    A *= B;

    ASSERT_TRUE(A.getRows() == expected.getRows());
    ASSERT_TRUE(A.getColumns() == expected.getColumns());
}

TEST(MatrixOperationTest, GivenMatrix_WhenMultiplicatingWithSelf_ThenReturnProduct) {
    Matrix A(2, 1);
    A(0, 0) = 1.0;
    A(1, 0) = 2.0;

    Matrix B(1, 2);
    B(0, 0) = 3.0; B(0, 1) = 4.0;

    Matrix expected(2, 2);
    expected(0, 0) = 3.0; expected(0, 1) = 4.0;
    expected(1, 0) = 6.0; expected(1, 1) = 8.0;

    A *= B;

    ASSERT_TRUE(A == expected);
}

TEST(MatrixOperationTest, GivenMatrix_WhenMultiplicatingToSelf_ThenReturnProduct) {
    Matrix A(2, 1);
    A(0, 0) = 1.0;
    A(1, 0) = 2.0;

    Matrix B(1, 2);
    B(0, 0) = 3.0; B(0, 1) = 4.0;

    Matrix expected(2, 2);
    expected(0, 0) = 3.0; expected(0, 1) = 4.0;
    expected(1, 0) = 6.0; expected(1, 1) = 8.0;

    Matrix C = A * B;

    ASSERT_TRUE(C == expected);
}

TEST(MatrixRowOperationTest, GivenMatrix_WhenSwappingRows_ThenRowsAreSwapped) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    Matrix expected(2, 2);
    expected(0, 0) = 3.0; expected(0, 1) = 4.0;
    expected(1, 0) = 1.0; expected(1, 1) = 2.0;

    A.swapRows(0, 1);

    ASSERT_TRUE(A == expected);
}

TEST(MatrixRowOperationTest, GivenMatrix_WhenScalingRow_ThenRowIsScaled) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    double scale_factor = 2.1;

    Matrix expected(2, 2);
    expected(0, 0) = 1.0; expected(0, 1) = 2.0;
    expected(1, 0) = 3.0 * scale_factor; expected(1, 1) = 4.0 * scale_factor;

    A.scaleRow(1, scale_factor);

    ASSERT_TRUE(A == expected);
}

TEST(MatrixRowOperationTest, GivenMatrix_WhenReducingRow_ThenRowIsReduced) {
    Matrix A(2, 2);
    A(0, 0) = 1.0; A(0, 1) = 2.0;
    A(1, 0) = 3.0; A(1, 1) = 4.0;

    Matrix expected(2, 2);
    expected(0, 0) = 1.0; expected(0, 1) = 2.0;
    expected(1, 0) = 2.0; expected(1, 1) = 2.0;

    A.reduceRow(1, 0);

    ASSERT_TRUE(A == expected);
}