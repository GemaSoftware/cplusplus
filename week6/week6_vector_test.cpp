#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "week6.h"

TEST_CASE("Testing the Vectors"){
    SUBCASE("Testing the default struct constructor"){
        int_vector test1{0, 1, 2};
        int_vector test2{10, 12, 5};
        int_vector test3{20, 6, 10};
        CHECK(test1.id == 0);
        CHECK(test1.to == 2);
        CHECK(test2.id == 10);
        CHECK(test2.from == 12);
        CHECK(test3.id == 20);
        CHECK(test3.from == 6);
        CHECK(test3.to == 10);
    }

    SUBCASE("Testing the copy-constructor"){
        int_vector test1{0, 10, 20};
        int_vector test2 = test1;
        CHECK(test1.id == 0);
        CHECK(test1.from == 10);
        CHECK(test1.from == test2.from);
        CHECK(test1.to == test2.to);
        //now change test2.
        test2.from = 15;
        test2.to = 25;
        CHECK(test2.from == 15);
        CHECK(test1.from != test2.from);
        CHECK(test1.to != test2.to);
    }

    SUBCASE("Testing input edge case - empty file"){
        //file name of blank is blank_vectors.txt
        CHECK_THROWS(read_vectors("vectors/blank_vectors.txt"));
    }
}