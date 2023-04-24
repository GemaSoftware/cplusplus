#include "lab9.h"

std::ostream & operator<<(std::ostream & os, Matrix & m) {
    using namespace std;
  for (auto vv: m.matrix) {
    for (auto v : vv) {
      os << v << " ";
    }
    os << endl;
  }  
  return os;
}

Matrix matrix_mult (Matrix a, Matrix b){
    Matrix res(a.cols, b.rows);

    for(int i = 0; i<a.rows; i++){
        for(int j=0; j<b.cols; j++){
            res.matrix[i][j] = 0;
            for(int k=0; k< b.rows; k++){
                res.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
            }
        }
    }
    return res;
}


//Normalize each row of the matrix.
//diuvide each element by the sum of its absolute values and then divide by 2.
void normalize_and_divide_by_2(Matrix &m) {
    using namespace std;
    for(int i = 0; i<m.rows; i++){
        int rsum = 0;
        //get the total row sum
        for (int j = 0; j < m.cols; j++){
            rsum += abs(m.matrix[i][j]);
        }
        
        for(int j=0; j<m.cols; j++){
            m.matrix[i][j] /= (2 * rsum);
        }

    }
}

Matrix get_zero_edges(Matrix& m){
    Matrix res(m.rows, m.cols);
    for (int i = 0; i < m.rows; i++){
        for (int j = 0; j < m.cols; j++){
            if (i == j || m.matrix[i][j] == 0){
                res.matrix[i][j] = 1;
            } else {
                for (int k = 0; k < m.rows; k++){
                    if(k != i && k != j && m.matrix[i][k] != 0 && m.matrix[k][j] != 0 && (m.matrix[i][k] + m.matrix[k][j]) == 0) {
                        res.matrix[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }
    return res;
}

void main_algorithm_1(int verticies, Matrix m){
    using namespace std;
    int n = abs(verticies);

    for(int i = 2; i< ceil(log(n)) + 1; i++){
        m = matrix_mult(m, m);
        //remove +/- 1 edges from m?

        //normalize and divide by 2 
        normalize_and_divide_by_2(m);

        // z <- Get-Zero-Edges(M)
        Matrix z = get_zero_edges(m);

        // m = z m z -- matrix multiply.
        Matrix temp = matrix_mult(z, m);
        Matrix res = matrix_mult(temp, m);
    }
}