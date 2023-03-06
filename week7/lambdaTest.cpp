#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "lambdas.h"

using namespace std;

TEST_CASE("Testing Vector Creations"){
    vector<int> list1{1,2,3,4,5,6};
    vector<int> list2{27, 28, 30};
    vector<int> list3{1,2,3,4,5,6};
    vector<int> perfectNumbers{6, 28, 496, 8128};

    SUBCASE("Testing the vector return of perfect numbers"){
        CHECK(getPerfectInts(list1).size() == 1);
        CHECK(getPerfectInts(list2).size() == 1);
        CHECK(getPerfectInts(perfectNumbers).size() == 4);
    }

    SUBCASE("Testing the perfect numbers"){
        CHECK(getPerfectInts(perfectNumbers).at(0) == 6);
        CHECK(getPerfectInts(perfectNumbers).at(1) == 28);
        CHECK(getPerfectInts(perfectNumbers).at(2) == 496);
    }

}