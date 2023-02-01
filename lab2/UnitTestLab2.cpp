#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "lab2.h"
#include <iostream>

using namespace std;

int test1[] = {1,1,1,1,-1,-1,-1,-1}; //true
int test2[] = {-1, 1, 1, -1, -1, 1}; //false
int test3[] = {1,-1,1,-1,1,-1,1,-1,1,-1}; //true
TEST_CASE("This test case checks if the list of 1's and -1s is well balanced using the function defined.") {
    CHECK(check_well_balanced_list(test1, 8) == true);
    CHECK(check_well_balanced_list(test2, 6) == false);
    CHECK(check_well_balanced_list(test3, 10) == true);
    
}

TEST_CASE("This checks that the full function works and checks for precision and accuracy.") {
    CHECK(!((well_balanced_list_gen(64, 1000) / 1000.0) > 0.7)); // this value should be near to 0.6
}
