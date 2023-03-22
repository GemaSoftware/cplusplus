#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "rvector.h"

TEST_CASE("Testing Reading Adj List"){
    //test.txt
    std::vector<std::vector<int>> test = read_adj_list_file("test.txt");
    CHECK(test[0][0] == 1);
    CHECK(test[0][1] == 2);
    CHECK(test[0][2] == 4);
    CHECK(test[1][0] == 3);
    CHECK(test[2][0] == 3);
    CHECK(test[3].size() == 0);
}