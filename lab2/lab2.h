#include "PrefixSum.h"

#ifndef __PREFIX_SUM_H
#define __PREFIX_SUM_H
/// @brief Takes the array provided and fills hald the array with 1's and half the array with -1's.
/// @param array newly initialized array.
/// @param length length of array
/// @return void. However, the array will have been modified to half 1 and half -1
void generate_num_list(int array[], int length);


/// @brief Scrambles the array via the fisher yates algorithm.
/// @param array array containing the integers to scramble
/// @param length the length of the array.
void fisher_yates_scramble(int array[], int length);


/// @brief This function will return the number of successful well balanced lists given 1000 iterations of random lists of 2n.
/// @param n integer n that will be used to generate list of 2n matching symbols.
/// @param times the number of times to generate, scramble, and check for well-balanced list
/// @return The number of successful well balanced lists from 1000 attempts for 2n symbols.
int well_balanced_list_gen(int n, int times);

/// @brief Checks to make sure the array is a "well-balanced list"
/// @param array array to check well balanced list
/// @param length length of array
/// @return true if the list is well balanced. False otherwise.
bool check_well_balanced_list(int array[], int length);

#endif