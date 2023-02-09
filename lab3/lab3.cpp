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

void print_array(int array[], int arlen){
    for(int i = 0; i < arlen; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void generate_final_array(int array[], int lowestIndex, int newArray[], int arlen) {
    for(int i = 0; i < arlen-1-lowestIndex; i++){
        newArray[i] = array[lowestIndex+i+1];
    }
    //this takes start of P1->endofP1-1 and places in P2. This chops off one ending value from P1.
    for(int b = 0; b < lowestIndex; b++) {
        newArray[arlen-1-lowestIndex+b] = array[b];
    }
}

 
bool check_well_balanced_list(int array[], int length) {
    //After analysis, if the array is itself a non-negative prefix sum, it is a well-balanced list. As the prefix sum will never go below 0. 
    //Acts like a stack.

    if(non_negative_sum(array, length) == true) return true;
    else return false;
}

int find_lowest_depth(int array[], int arrlen){
    //edge case, empty list or 1 element. index of lowest depth is 0.
    if(arrlen == 0 || arrlen == 1){
        return 0;
    }

    //second way of doing it witout prefix sum
    int lowestsum = 0;
    int currentsum=0;
    int lowest = 0;

    for(int i = 0; i < arrlen; i++){
        currentsum += array[i];
        if(currentsum < lowestsum){
            lowestsum = currentsum;
            lowest = i;
        }
    }
    //returns index of lowest prefic sum.
    return lowest;
}

int main(int argc, char** argv) {
    //add doctest unit tests before run.
    doctest::Context context;
    // Taken from DOCTEST
    context.applyCommandLine(argc, argv);
    int res = context.run(); // run
    if(context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
        return res;          // propagate the result of the tests

    //MAIN PROGRAM
    //take an input of n
     int n;
    cout << "Please enter an integer n (-1 to quit): ";
    cin >> n;
    //exit the program if -1 entered.
    if(n == -1){
        return 0;
    }

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

//UNIT TESTS

int t1[] = {};
int t2[] = {-1};
int t3[] = {1,1,-1,-1,-1,1,1,1};
int t4[] = {1,1,-1,-1,-1,1,-1};

TEST_CASE("This will check our new function to find the lowest depth index. Lowest index returns the index right after it "){
    CHECK(find_lowest_depth(t1, 0) == 0);
    CHECK(find_lowest_depth(t2, 0) == 0);
    CHECK(find_lowest_depth(t2, 1) == 0);
    CHECK(find_lowest_depth(t3, 8) == 4);
    CHECK(find_lowest_depth(t4, 7) == 4);
}

TEST_CASE("Testing our Array Shift function"){
    int t5[] = {1,1,-1,-1,-1,-1,1};//init len 7
    int newArray[6]; // now of len 6
    //our lowest dept returns the index of the element right after the lowest element,
    generate_final_array(t5, 5, newArray, 7);
    CHECK(newArray[0] == 1);
    CHECK(newArray[1] == 1);
    CHECK(newArray[2] == 1);
    CHECK(newArray[3] == -1);
    CHECK(newArray[4] == -1);
    CHECK(newArray[5] == -1);
    CHECK(check_well_balanced_list(newArray, 6) == true);
}

//TEST CASE FOR WELL-BALANCED FUNCTIONS
int test1[] = {1,1,1,1,-1,-1,-1,-1}; //true
int test2[] = {-1, 1, 1, -1, -1, 1}; //false
int test3[] = {1,-1,1,-1,1,-1,1,-1,1,-1}; //true
TEST_CASE("This test case checks if the list of 1's and -1s is well balanced using the function defined.") {
    CHECK(check_well_balanced_list(test1, 8) == true);
    CHECK(check_well_balanced_list(test2, 6) == false);
    CHECK(check_well_balanced_list(test3, 10) == true);
}