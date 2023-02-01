#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "week3.h"

TEST_CASE("Creating/Deleting Linked List Functionality.") {
    SUBCASE("Checking someone making linked list with 0 elements. we want to return NULL.") {
        node* null_test = build_linked_list(0);
        CHECK(null_test == NULL);

        //Check length of LL
        node* length_test = build_linked_list(23);
        node* temp = length_test;
        int length_count = 0;
        while(temp->next != NULL){
            length_count++;
            temp = temp->next;
        }
        CHECK(length_count == 23);
        CHECK(delete_linked_list(length_test, 23) == 23);
    }

    SUBCASE("TESTING DELETING THE LINKED LIST"){
        node* delete_test = build_linked_list(5);
        CHECK(delete_linked_list(delete_test, 5) == 5);

        node* delete_test1 = build_linked_list(1);
        CHECK(delete_linked_list(delete_test1, 1));
    }
}

TEST_CASE("Testing Linked List functionality") {
    SUBCASE("Test creation of linked list.") {
        node* test = build_linked_list(1);
        CHECK(test->number == 0);
    }

    SUBCASE("Testing larger linked lists.") {
        node* test2 = build_linked_list(10);
        node* temp = test2;
        for(int i = 0; i < 10; i++) {
            CHECK(temp->number == i);
            temp = temp->next;
        }
        CHECK(delete_linked_list(test2, 10) == 10);
    }

    SUBCASE("Testing the SUM of the linked lists"){
        node* test_sum1 = build_linked_list(3);
        CHECK(sum_values_in_linked_list(test_sum1, 3) == 3);
        CHECK(delete_linked_list(test_sum1, 3));

        node* test_sum2 = build_linked_list(10); // 0+1+2+...+9 = 45
        CHECK(sum_values_in_linked_list(test_sum2, 10) == 45);
        CHECK(delete_linked_list(test_sum2, 10) == 10);
    }


}