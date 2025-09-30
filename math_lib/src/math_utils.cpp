#include "math_utils.hpp"
#include <cmath>

bool are_doubles_nearly_equal(double a, double b, double threshold)
{
    return std::fabs(a - b) < threshold;
}
