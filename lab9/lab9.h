//These header files will be used for the matrix functions for week11.
#ifndef LAB9_MATRIX_THING
#define LAB9_MATRIX_THING
//#include "../bigint/bigint.h" bigints are making everything complicated right now. Cant compile becaise multiple declarations. sticking with ints
#include <iostream>
#include <utility>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>


//Matrix Struct. Had to move this to after Fraction because we called create_fraction before it was "made"
struct Matrix {
    int rows;
    int cols;

    std::vector<std::vector<int>> matrix;

    Matrix(int rows, int cols) : rows(rows), cols(cols), matrix(rows, std::vector<int>(cols, 0)) {
    }
};

Matrix matrix_mult (Matrix a, Matrix b);
void normalize_and_divide_by_2(Matrix &m);
Matrix get_zero_edges(Matrix& m);
void main_algorithm_1(int verticies, Matrix m);
std::ostream & operator<<(std::ostream & os, Matrix & m);

#endif