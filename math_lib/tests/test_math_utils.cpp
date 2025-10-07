#include "math_utils.hpp"
#include <gtest/gtest.h>

TEST(DoublesNearlyEquals, GivenNearIdenticalDoubles_WhenComparingThem_ThenReturnTrue) {
    double threshold_error = 1e-9;
    double a = 1.234;
    double b = a + threshold_error / 2;

    ASSERT_TRUE(are_doubles_nearly_equal(a, b, threshold_error));
}

TEST(DoublesNearlyEquals, GivenNoneIdenticalDoubles_WhenComparingThem_ThenReturnFalse) {
    double threshold_error = 1e-9;
    double a = 1.234;
    double b = a + threshold_error * 2;

    ASSERT_FALSE(are_doubles_nearly_equal(a, b, threshold_error));
}