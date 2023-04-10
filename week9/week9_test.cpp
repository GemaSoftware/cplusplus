#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "rllptr.h"

TEST_CASE("Testing creating the List struct and its functions"){
    List* x = new List();
    x->push(1);
    x->push(2);
    x->push(3);
    CHECK(x->head->data == 3);
    CHECK(x->head->next->data == 2);
    CHECK(x->head->next->next->data == 1);
    delete x;
}