#include "lab4.h"
#include <iostream>

using namespace std;


//class code
struct node * build_linked_list(const int elements) {
    struct node* temp = new node;
    struct node* root = temp;
    //store refrence to last pointer.
    node* last_pointer;

    //first set up linked list and grab pointer of last element.
    for(int i = 0; i < elements; i++){
        //we have to make sure we dont set temp=the new array after we reach element max.
        if(i == elements-1){
            temp->next = temp;
            temp->jump = temp;
            temp->number = i;
            last_pointer = temp;
        } else {
            temp->next = new node;
            temp->number = i;
            temp = temp->next;
        }   
    }
    //now lets assign jump to all nodes.
    temp = root;
    for(int i = 0; i < elements-1; i++){
        temp->jump = last_pointer;
        temp = temp->next;
    }

    //linked list is still pointing at the root node.
    return root;
}


struct node * build_linked_list_alternative(const int elements) {
    struct node* temp = new node;
    temp->number = elements-1;
    //store refrence to last pointer.
    node* last_pointer = temp;
    last_pointer->next = temp;
    last_pointer->jump = temp;
    //we are building the list backwards to O(n)
    for(int i = elements-1; i >0; i--){
        node* newNode = new node;
        newNode->next = temp;
        newNode->jump = last_pointer;
        newNode->number = i-1;
        temp = newNode;
    }
    //linked list is still pointing at the root node.
    return temp;
}

struct node * pointer_jump_linked_list(struct node * linked_list) {
  return linked_list->jump;
}

int sum_values_in_linked_list(struct node * list, const int elements) {
    int sum = 0;
    node* temp = list;
    for(int i = 0; i < elements; i++){
        sum+= temp->number;
        temp = temp->next;
    }
    return sum;
}

void print_linked_list(struct node * list, const int elements) {
  using namespace std;
  
  struct node * my_node = list;
  for (int i =0; i < elements; i++) {
    cout << my_node->number << " " << endl;
    my_node = my_node->next;
  }
}

int delete_linked_list(struct node * list, const int elements) {
   //this should operate the same way a normal delete will work.
   int del = 0;
   node* start = list;
   for(int i = 0; i < elements; i++){
        node* curr = start->next;
        delete start;
        del++;
        start = curr;
   }
    return del;
}