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