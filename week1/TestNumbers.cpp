#include <iostream>
#include "ECNumbers.h"
#include "ECCalculator.h"
#include "../doctest/doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

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
