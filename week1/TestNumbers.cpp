#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "ECNumbers.h"
#include "ECCalculator.h"
#include "ECRemoveElement.h"
#include "../doctest/doctest.h"

using namespace std;

TEST_CASE("testing the square functions") {
    CHECK(ECNumbers::ECSquareN(2) == 4);
    CHECK(ECNumbers::ECSquareN(3) == 9);
    CHECK(ECNumbers::ECSquareN(4) == 16);
    CHECK(ECNumbers::ECSquareN(5) == 25);
}

TEST_CASE("testing the double functions") {
    CHECK(ECNumbers::ECDoubleN(3) == 6);
    CHECK(ECNumbers::ECDoubleN(4) == 8);
    CHECK(ECNumbers::ECDoubleN(5) == 10);
    CHECK(ECNumbers::ECDoubleN(2) == 4);
}

TEST_CASE("Testing the ECRemoveSpace functions"){
    int nums1[] = {3,2,2,3};
    int nums2[] = {0,1,2,2,3,0,4,2};

    ECRemoveSpace(nums1, 4, 3);
    CHECK(nums1[0] == 2);
    CHECK(nums1[1] == 2);

    ECRemoveSpace(nums2, 8, 2);
    CHECK(nums2[0] == 0);
    CHECK(nums2[1] == 1);
    CHECK(nums2[2] == 3);
    CHECK(nums2[3] == 0);
    CHECK(nums2[4] == 4);
}