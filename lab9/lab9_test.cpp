#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "lab9.h"

TEST_CASE("Testing initial Matrix and all functions"){

    Matrix a(5, 5);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            CHECK(a.matrix[i][j] == 0);
        }
    }

    //setting uo matrixes for multiplying 1-9 * 1-9
    Matrix t1(3,3);
    int t = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            t1.matrix[i][j] = t;
            t++;
        }
    }

    Matrix t2(3,3);
    t = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            t2.matrix[i][j] = t;
            t++;
        }
    }

    //test and check for the proper values
    CHECK(t1.matrix[0][2] == 3);
    CHECK(t2.matrix[2][2] == 9);

    // Now test multiplication
    Matrix res = matrix_mult(t1, t2);
    CHECK(res.matrix[0][0] == 30);
    CHECK(res.matrix[0][1] == 36);
    CHECK(res.matrix[0][2] == 42);
    CHECK(res.matrix[1][0] == 66);
    CHECK(res.matrix[1][1] == 81);
    CHECK(res.matrix[1][2] == 96);
    CHECK(res.matrix[2][0] == 102);
    CHECK(res.matrix[2][1] == 126);
    CHECK(res.matrix[2][2] == 150);

    std::cout << res << std::endl;
    //testing the normalization
    normalize_and_divide_by_2(res);


}