//These header files will be used for the matrix functions for week11.
#ifndef WEEK11_NODE_UNIQ
#define WEEK11_NODE_UNIQ
//#include "../bigint/bigint.h" bigints are making everything complicated right now. Cant compile becaise multiple declarations. sticking with ints
#include <iostream>
#include <utility>
#include <vector>

struct Fraction {
    std::pair<int, int> fraction;
};

Fraction create_fraction(int a, int b);
Fraction multiply_fraction_pair(Fraction x, Fraction y);
Fraction sum_fraction_pair(Fraction x, Fraction y);

//Matrix Struct. Had to move this to after Fraction because we called create_fraction before it was "made"
struct Matrix {
    int rows;
    int cols;

    std::vector<std::vector<Fraction>> matrix;

    Matrix(int rows, int cols) : rows(rows), cols(cols), matrix(rows, std::vector<Fraction>(cols, create_fraction(0, 1))) {
    }
};
//Matrix functions
Matrix create_fraction_matrix(int rows, int cols);
void setFraction(Matrix& matrix, int row, int col, const Fraction& fraction);
void printMatrix(Matrix& matrix);
Matrix multiply_matrix(const Matrix& a, const Matrix& b);


#endif