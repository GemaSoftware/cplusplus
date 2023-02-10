#ifndef __PREFIX_SUM_H
#define __PREFIX_SUM_H

struct node {
  int number;
  struct node * next;
  struct node * jump;  
};

//This function will build a linked list using the node struct and return a pointer to the linked list on the heap.
struct node * build_linked_list(const int elements);

struct node * build_linked_list_alternative(const int elements);

//This function will print the linked list and all its elements to std out.
void print_linked_list(struct node * list, const int elements);

//This function will delete all elements in the linked list to prevent memory leaks.
int delete_linked_list(struct node * list, const int elements);

//This function will jump to the last element in the linked list via pointer jumping.
struct node * pointer_jump_linked_list(struct node * linked_list);

//Thist function will sum all values in the linked list.
int sum_values_in_linked_list(struct node * list, const int elements);

#endif