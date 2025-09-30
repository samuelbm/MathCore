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

TEST(MatrixRowOperationTest, GivenMatrix_WhenAskingForPivot_ThenReturnPivotRowWithBiggestAbsoluteValue) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = -5.0; A(0, 2) = 7.0;
    A(1, 0) = 2.0; A(1, 1) = 2.0; A(1, 2) = 0.0;
    A(2, 0) = -3.0; A(2, 1) = -3.0; A(2, 2) = 3.0;

    size_t column = 0;
    size_t expected = 2;
    size_t pivot_row = A.find_pivot_row(column);

    ASSERT_EQ(expected, pivot_row);
}

TEST(MatrixRowOperationTest, GivenMatrix_WhenAskingForPivot_ThenReturnPivotRowEqualOrGreaterThanColumnIndex) {
    Matrix A(3, 3);
    A(0, 0) = 1.0; A(0, 1) = -5.0; A(0, 2) = 7.0;
    A(1, 0) = 2.0; A(1, 1) = 2.0; A(1, 2) = 0.0;
    A(2, 0) = -3.0; A(2, 1) = -3.0; A(2, 2) = 3.0;

    size_t column = 1;
    size_t expected = 2;
    size_t pivot_row = A.find_pivot_row(column);

    ASSERT_EQ(expected, pivot_row);
}

TEST(MatrixStaticTest, GivenMatrix_WhenFillingWithValue_ThenMatrixisFilled) {
    double fill_value = 3.14;

    Matrix expected(2, 2);
    expected(0, 0) = fill_value; expected(0, 1) = fill_value;
    expected(1, 0) = fill_value; expected(1, 1) = fill_value;

    Matrix A = Matrix::fill(2, 2, fill_value);

    ASSERT_TRUE(A == expected);
}

TEST(MatrixStaticTest, GivenMatrix_WhenCallingIdentity_ThenMatrixisIdentity) {    
    Matrix expected(2, 2);
    expected(0, 0) = 1.0; expected(0, 1) = 0.0;
    expected(1, 0) = 0.0; expected(1, 1) = 1.0;

    Matrix A = Matrix::identity(2);

    ASSERT_TRUE(A == expected);
}

TEST(MatrixStatic2DTest, GivenMatrix_WhenRotation2D_ThenReturnAppropriateMatrix) {    
    double angle_degrees = 90.0;
    Matrix expected(3, 3);
    expected(0, 0) = 0.0; expected(0, 1) = -1.0; expected(0, 2) = 0.0;
    expected(1, 0) = 1.0; expected(1, 1) = 0.0; expected(1, 2) = 0.0;
    expected(2, 0) = 0.0; expected(2, 1) = 0.0; expected(2, 2) = 1.0;

    Matrix A = Matrix::homogeneousRotation2D(angle_degrees);

    ASSERT_TRUE(A == expected);
}

TEST(MatrixStatic2DTest, GivenMatrix_WhenScale2D_ThenReturnAppropriateMatrix) {    
    double scale_factor_x = 2.0;
    double scale_factor_y = 3.0;
    Matrix expected(3, 3);
    expected(0, 0) = scale_factor_x; expected(0, 1) = 0.0; expected(0, 2) = 0.0;
    expected(1, 0) = 0.0; expected(1, 1) = scale_factor_y; expected(1, 2) = 0.0;
    expected(2, 0) = 0.0; expected(2, 1) = 0.0; expected(2, 2) = 1.0;

    Matrix A = Matrix::homogeneousScaling2D(scale_factor_x, scale_factor_y);

    ASSERT_TRUE(A == expected);
}

TEST(MatrixStatic2DTest, GivenMatrix_WhenTranslation2D_ThenReturnAppropriateMatrix) {    
    double translation_x = 2.0;
    double translation_y = 3.0;
    Matrix expected(3, 3);
    expected(0, 0) = 1.0; expected(0, 1) = 0.0; expected(0, 2) = translation_x;
    expected(1, 0) = 0.0; expected(1, 1) = 1.0; expected(1, 2) = translation_y;
    expected(2, 0) = 0.0; expected(2, 1) = 0.0; expected(2, 2) = 1.0;

    Matrix A = Matrix::homogeneousTranslation2D(translation_x, translation_y);

    ASSERT_TRUE(A == expected);
}

TEST(MatrixStatic3DTest, GivenMatrix_WhenRotationX3D_ThenReturnAppropriateMatrix) {    
    double angle_degrees = 90.0;
    Matrix expected(4, 4);
    expected(0, 0) = 1.0; expected(0, 1) = 0.0; expected(0, 2) = 0.0; expected(0, 3) = 0.0;
    expected(1, 0) = 0.0; expected(1, 1) = 0.0; expected(1, 2) = -1.0; expected(1, 3) = 0.0;
    expected(2, 0) = 0.0; expected(2, 1) = 1.0; expected(2, 2) = 0.0; expected(2, 3) = 0.0;
    expected(3, 0) = 0.0; expected(3, 1) = 0.0; expected(3, 2) = 0.0; expected(3, 3) = 1.0;

    Matrix A = Matrix::homogeneousRotationX3D(angle_degrees);

    ASSERT_TRUE(A == expected);
}

TEST(MatrixStatic3DTest, GivenMatrix_WhenRotationY3D_ThenReturnAppropriateMatrix) {    
    double angle_degrees = 90.0;
    Matrix expected(4, 4);
    expected(0, 0) = 0.0; expected(0, 1) = 0.0; expected(0, 2) = 1.0; expected(0, 3) = 0.0;
    expected(1, 0) = 0.0; expected(1, 1) = 1.0; expected(1, 2) = 0.0; expected(1, 3) = 0.0;
    expected(2, 0) = -1.0; expected(2, 1) = 0.0; expected(2, 2) = 0.0; expected(2, 3) = 0.0;
    expected(3, 0) = 0.0; expected(3, 1) = 0.0; expected(3, 2) = 0.0; expected(3, 3) = 1.0;

    Matrix A = Matrix::homogeneousRotationY3D(angle_degrees);

    ASSERT_TRUE(A == expected);
}

TEST(MatrixStatic3DTest, GivenMatrix_WhenRotationZ3D_ThenReturnAppropriateMatrix) {    
    double angle_degrees = 90.0;
    Matrix expected(4, 4);
    expected(0, 0) = 0.0; expected(0, 1) = -1.0; expected(0, 2) = 0.0; expected(0, 3) = 0.0;
    expected(1, 0) = 1.0; expected(1, 1) = 0.0; expected(1, 2) = 0.0; expected(1, 3) = 0.0;
    expected(2, 0) = 0.0; expected(2, 1) = 0.0; expected(2, 2) = 1.0; expected(2, 3) = 0.0;
    expected(3, 0) = 0.0; expected(3, 1) = 0.0; expected(3, 2) = 0.0; expected(3, 3) = 1.0;

    Matrix A = Matrix::homogeneousRotationZ3D(angle_degrees);

    ASSERT_TRUE(A == expected);
}

TEST(MatrixStatic3DTest, GivenMatrix_WhenScale3D_ThenReturnAppropriateMatrix) {    
    double scale_factor_x = 2.0;
    double scale_factor_y = 3.0;
    double scale_factor_z = 4.0;
    Matrix expected(4, 4);
    expected(0, 0) = scale_factor_x; expected(0, 1) = 0.0; expected(0, 2) = 0.0; expected(0, 3) = 0.0;
    expected(1, 0) = 0.0; expected(1, 1) = scale_factor_y; expected(1, 2) = 0.0; expected(1, 3) = 0.0;
    expected(2, 0) = 0.0; expected(2, 1) = 0.0; expected(2, 2) = scale_factor_z; expected(2, 3) = 0.0;
    expected(3, 0) = 0.0; expected(3, 1) = 0.0; expected(3, 2) = 0.0; expected(3, 3) = 1.0;

    Matrix A = Matrix::homogeneousScaling3D(scale_factor_x, scale_factor_y, scale_factor_z);

    ASSERT_TRUE(A == expected);
}

TEST(MatrixStatic3DTest, GivenMatrix_WhenTranslation3D_ThenReturnAppropriateMatrix) {    
    double translation_x = 2.0;
    double translation_y = 3.0;
    double translation_z = 4.0;
    Matrix expected(4, 4);
    expected(0, 0) = 1.0; expected(0, 1) = 0.0; expected(0, 2) = 0.0; expected(0, 3) = translation_x;
    expected(1, 0) = 0.0; expected(1, 1) = 1.0; expected(1, 2) = 0.0; expected(1, 3) = translation_y;
    expected(2, 0) = 0.0; expected(2, 1) = 0.0; expected(2, 2) = 1.0; expected(2, 3) = translation_z;
    expected(3, 0) = 0.0; expected(3, 1) = 0.0; expected(3, 2) = 0.0; expected(3, 3) = 1.0;

    Matrix A = Matrix::homogeneousTranslation3D(translation_x, translation_y, translation_z);

    ASSERT_TRUE(A == expected);
}