#include <iostream>
#include "matrix.hpp"

int main() {
    Matrix mat(3, 3);

    int sum = mat.add(5, 3);

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}