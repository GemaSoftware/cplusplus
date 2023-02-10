#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lab4.h"
#include "../doctest/doctest.h"


TEST_CASE("Test the Linked List Creation"){
    struct node* main = build_linked_list(10);
    struct node* temp = main;
    for(int i = 0; i < 10; i++){
        CHECK(temp->number == i);
        temp = temp->next;
    }
    CHECK(pointer_jump_linked_list(main)->number == 9);
    CHECK(main->jump->next->next->number == 9);

    //delete the linked list.
    CHECK(delete_linked_list(main, 10) == 10);
}

TEST_CASE("Testing a larger linked list and each jump to point to final node.") {
    node* test2 = build_linked_list(50);
    node* temp_pointer = test2;
    for(int i = 0; i < 50; i++){
        CHECK(temp_pointer->jump->number == 49);
        CHECK(temp_pointer->number == i);
        temp_pointer = temp_pointer->next;
    }
    CHECK(sum_values_in_linked_list(test2, 50) == 1225);//0->49
    //delete the linked list for memory collection
    CHECK(delete_linked_list(test2, 50) == 50);
}