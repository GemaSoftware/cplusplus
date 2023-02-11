#ifndef __WEEK4_H
#define __WEEK4_H
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>


//STACK FUNCTIONS

/// @brief This function will take elements from the file line by line and insert the element into the stack.
/// @param stack This is the STL stack to ouch elements into.
/// @param filename The name of the file to read the integers from.
void pushElementsToStlStack(std::stack<int>& stack, const std::string& filename);

/// @brief This function takes the element at the top of the stack, pops it from the stack and returns it.
/// @param stack the stack to pop the element from.
/// @return the element at the top of the stack.
int popElementStlStack(std::stack<int>& stack);

/// @brief This function will add the elementfs from the file and then adds them into the STL queue.
/// @param queue the queue to add the elements into.
/// @param filename the name of the file to grab the elements from
void queueElementsStlQueue(std::queue<int>& queue, std::string& filename);

/// @brief This function dequeues an eleent from the STL queue and returns the value.
/// @param queue the queue to pull the elements from
/// @return the element at the front of the queue
int dequeueElementStlQueue(std::queue<int>& queue);

#endif