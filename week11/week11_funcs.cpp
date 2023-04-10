#include "week11.h"

Fraction create_fraction(int a, int b)
{
    Fraction res;
    res.fraction.first = a;
    res.fraction.second = b;
    return res;
}

Fraction multiply_fraction_pair(Fraction x, Fraction y)
{
    Fraction result;
    result.fraction.first = x.fraction.first * y.fraction.first;
    result.fraction.second = x.fraction.second * y.fraction.second;
    return result;
}

Fraction sum_fraction_pair(Fraction x, Fraction y)
{
    Fraction result;
    result.fraction.first = x.fraction.first*y.fraction.second + x.fraction.second * y.fraction.first;
    result.fraction.second = x.fraction.second * y.fraction.second;
    return result;
}

Matrix create_fraction_matrix(int rows, int cols){
    Matrix matrix(rows, cols);
    return matrix;
}

void setFraction(Matrix& matrix, int row, int col, const Fraction& fraction) {
        matrix.matrix[row][col] = fraction;
    }

void printMatrix(Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                std::cout << "(" << matrix.matrix[i][j].fraction.first << "/" << matrix.matrix[i][j].fraction.second << ") ";
            }
            std::cout << std::endl;
        }
    }

Matrix multiply_matrix(const Matrix& A, const Matrix& B) {
    //The doc tells us to assume that both matrixes are row=col but I wanted to add this in as a precaution.
    //you need a cols to equal b rows for mult to work.
    if (A.cols != B.rows) {
        throw std::runtime_error("Matrix multiplication not possible: Number of columns in A must be equal to the number of rows in B");
    }
    //init result matrix
    Matrix result(A.rows, B.cols);
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            // First create the "sum"
            Fraction sum = create_fraction(0, 1); // Initialize sum to 0/1
            for (int k = 0; k < B.rows; k++) {
                //multiply the two items
                Fraction product = multiply_fraction_pair(A.matrix[i][k], B.matrix[k][j]);
                //add to sum.
                sum = sum_fraction_pair(sum, product);
            }
            result.matrix[i][j] = sum; // Set the result in the resultant matrix
        }
    }
    return result;
}
