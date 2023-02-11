#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "week4funcs.h"

//BEGIN UNIT TESTS
TEST_CASE("Testing Stack Functions") {

    SUBCASE("Testing base stack push/pop functions"){
        std::string filename = "posSum";
        std::stack<int> stack;
        pushElementsToStlStack(stack, filename);
        //CHECK LEN = 10
        CHECK(stack.size() == 10);
        CHECK(stack.top() == 9);
        //CHECK POP
        for(int i = 0; i < 10; i++){
            CHECK(stack.size() == 10-i);
            CHECK(popElementStlStack(stack) == 10-i-1);
        }
        //CHECK stack is empty;
        CHECK(stack.empty() == true);
    }

    SUBCASE("testing the negative sum exceptions"){
        std::string filename = "negSum";
        std::stack<int> test;
        CHECK_THROWS(pushElementsToStlStack(test, filename));
    }

    SUBCASE("testing the queue functions") {
        std::string filename = "posSum";
        std::queue<int> queue;
        queueElementsStlQueue(queue, filename);
        CHECK(queue.size() == 10);
        CHECK(queue.front() == 0);
        for(int i = 0; i<10; i++){
            CHECK(dequeueElementStlQueue(queue) == i);
        }
        CHECK(queue.size() == 0);
        CHECK(queue.empty() == true);
    }

}