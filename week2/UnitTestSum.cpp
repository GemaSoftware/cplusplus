#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "../doctest/doctest.h"
#include "PrefixSum.h"

int nums_1[] = {2, -3, 3, 2}; // {2, -1, 2, 3} // one negative, rest positive.
int nums_2[] = {1, 1, -1, -1}; //none are negative, last one is 0
int nums_3[] = {-1, -1, 1, 1}; //none are positive. last one is 0.

int nums_4[] = {5, 10, 15, 20}; //prefix sum should be {5, 15, 30, 50} all positive
int nums_5[] = {-5, -10, -15, -20}; //prefix sum should be {-5. -15, -30, -50} // all negative

int nums_6[] = {};
int nums_7[] = {25};
int nums_8[] = {-25};

int nums_9[] = {-1, -2, -3, 8};


//all prefix sums should return 0 if successful
TEST_CASE("testing the actual prefix sum functions") {
    CHECK(prefix_sum(nums_1, sizeof(nums_1)/sizeof(nums_1[0])) == 4);
    CHECK(prefix_sum(nums_2, sizeof(nums_2)/sizeof(nums_2[0])) == 0);
    CHECK(prefix_sum(nums_3, sizeof(nums_3)/sizeof(nums_3[0])) == 0);
    CHECK(prefix_sum(nums_4, sizeof(nums_4)/sizeof(nums_4[0])) == 50);
    CHECK(prefix_sum(nums_5, sizeof(nums_5)/sizeof(nums_5[0])) == -50);
    CHECK(prefix_sum(nums_6, sizeof(nums_6)/sizeof(nums_6[0])) == 0);
    CHECK(prefix_sum(nums_7, sizeof(nums_7)/sizeof(nums_7[0])) == 25);
    CHECK(prefix_sum(nums_8, sizeof(nums_8)/sizeof(nums_8[0])) == -25);
    CHECK(prefix_sum(nums_9, sizeof(nums_9)/sizeof(nums_9[0])) == 2);
}

TEST_CASE("testing the sums function modifications") {
    CHECK(non_negative_sum(nums_1, sizeof(nums_1)/sizeof(nums_1[0])) == false);
    CHECK(non_negative_sum(nums_2, sizeof(nums_2)/sizeof(nums_2[0])) == true);
    CHECK(non_positive_sum(nums_3, sizeof(nums_3)/sizeof(nums_3[0])) == true);
    CHECK(non_positive_sum(nums_4, sizeof(nums_4)/sizeof(nums_4[0])) == false);
    CHECK(non_positive_sum(nums_5, sizeof(nums_5)/sizeof(nums_5[0])) == true);
    CHECK(non_negative_sum(nums_7, sizeof(nums_7)/sizeof(nums_7[0])) == true);
    CHECK(non_positive_sum(nums_8, sizeof(nums_8)/sizeof(nums_8[0])) == true);
    CHECK(non_positive_sum(nums_9, sizeof(nums_9)/sizeof(nums_9[0])) == false);
    CHECK(non_negative_sum(nums_9, sizeof(nums_9)/sizeof(nums_9[0])) == false);
}