#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

class Matrix {
public:
    Matrix(int rows, int columns);
    int add(int a, int b);

private: 
    int rows;
    int columns;   
};

#endif // CALCULATOR_HPP
