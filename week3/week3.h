#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

struct node {
    int number;
    struct node* next;
};

/// @brief Creates a linked list of size elements and each element will increase by 1 in number.
/// @param elements number of elements in the linked list to create.
/// @return a node struct that contains the linked list.
struct node* build_linked_list(int elements);

/// @brief Prints all elements in the linked list.
/// @param elements count of elements in the linked list struct,
/// @return none. Prints each value of a linked list in order.
void print_linked_list(struct node* list, int elements);

/// @brief Deletes and frees the entire linked list.
/// @param elements number of elements in the linked list to delete.
/// @return the number of nodes deleted.
int delete_linked_list(struct node* list, int index);

/// @brief Sums up all values in the linked list 
/// @param elements number of elements to sum in order for the linked list
/// @return the sum of elements in the linked list in that order.
int sum_values_in_linked_list(struct node * list, int elements);

#endif

