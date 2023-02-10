#include "week3.h"
#include <iostream>

using namespace std;

struct node* build_linked_list(int elements){
    //find another way to check for <0 elements.
    if(elements == 0) {
        return NULL;
    }

    node * head = new node;
    struct node * list_ptr = head;

    for(int i = 0; i < elements; i++) {
        list_ptr->next = new node;
        list_ptr->number = i;
        list_ptr = list_ptr->next;
    }
    return head;

}


void print_linked_list(struct node* list, int elements) {
    node* temp = list;
    for(int i = 0; i < elements; i++){
        cout << temp->number << endl;
        temp = temp->next;
    }
}

int delete_linked_list(struct node* list, int elements) {
    int count = 0;
    node* temp = list;
    node* listToDelete[elements];
    for(int i = 0 ; i < elements; i++){
        listToDelete[i] = temp;
        temp = temp->next;
    }
    for(node* n: listToDelete){
        delete n;
        count++;
    }
    list = NULL;
    return count;
}

int sum_values_in_linked_list(struct node * list, int elements){
    int sum = 0;
    node* temp = list;
    for(int i = 0; i < elements; i++){
        sum += temp->number;
        temp = temp->next;
    }
    return sum;
}
