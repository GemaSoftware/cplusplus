#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest/doctest.h"
#include "../week2/PrefixSum.h"
#include <iostream>
#include "lab3.h"

using namespace std;

void generate_num_list(int array[], int nplusone){
    //first half should be 1's, second should be 0's
    for(int i = 0; i < (nplusone-1)/2; i++){
        array[i] = 1;
    }
    for(int i = (nplusone-1)/2; i < nplusone; i++){
        array[i] = -1;
    }
}

void swap_arr(int arr[], int a, int b) {
    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void fisher_yates_scramble(int array[], int length){
    for(int i = length-1; i > 1; i--){
        //j will be the random index to swap with. [0, length)
        int j = rand() % length;
        swap_arr(array, i, j);
    }
}

void generate_final_array(int array[], int lowestIndex, int newArray[], int arlen) {
    //this places P2 at the front
    for(int i = 0; i < arlen-lowestIndex; i++){
        newArray[i] = array[lowestIndex+i];
    }
    //this takes start of P1->endofP1-1 and places in P2. This chops off one ending value from P1.
    for(int b = 0; b < lowestIndex-1; b++) {
        newArray[arlen-lowestIndex+b] = array[b];
    }

}

 
bool check_well_balanced_list(int array[], int length) {
    //After analysis, if the array is itself a non-negative prefix sum, it is a well-balanced list. As the prefix sum will never go below 0. 
    //Acts like a stack.

    if(non_negative_sum(array, length) == true) return true;
    else return false;
}

int find_lowest_depth(int array[], int arrlen){
    int lowest=0;
    int lowestIndex=0;
    for(int a = 0; a < arrlen; a++){
            if(prefix_sum(array, a) < lowest){
                lowest = prefix_sum(array, a);
                lowestIndex = a;
        }
    }
    return lowestIndex;
}

int main() {
    //take an input of n
     int n;
    cout << "Please enter an integer n (-1 to quit): ";
    cin >> n;

    int itter;
    cout << "Please enter an integer itter (-1 to quit): ";
    cin >> itter;

    int success = 0;

    for(int i = 0; i < itter; i++){
        //Given a list of 2𝑛 + 1 integers, fill the first 𝑛 elements with 1 and the next 𝑛+1 elements with -1
        int array[(2*n)+1];
        int arrlen = (2*n)+1;
        generate_num_list(array, (2*n)+1);

        // Use the Fisher-Yates algorithm to randomly scramble this list of 2𝑛 + 1 elements
        fisher_yates_scramble(array, arrlen);

        //remove ones that start with a -1.
        if(array[0] == -1){
            continue;
        }

        // Find the lowest depth of any valley in this list of 2𝑛 + 1 elements
        int lowestIndex = find_lowest_depth(array, arrlen);   
        //We now have the lowest depth and its index.

        // Create a new array of 2n that will store P2 and P1'
        int newArray[arrlen-1];
        generate_final_array(array, lowestIndex, newArray, arrlen);
        //check if well balanced, if it is, add to number of successful.
        if(check_well_balanced_list(newArray, arrlen-1) == true){
            success+=1;
        }
        
    }

    cout << "Number of successes: " <<success << endl; 

    return 0;
}