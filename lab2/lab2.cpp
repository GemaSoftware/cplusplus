#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest/doctest.h"
#include "lab2.h"
#include <iostream>
#include "lab2.h"

using namespace std;

//Function Implementations

void generate_num_list(int array[], int length){
    //first half should be 1's, second should be 0's
    for(int i = 0; i < length/2; i++){
        array[i] = 1;
    }
    for(int i = length/2; i < length; i++){
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
 
bool check_well_balanced_list(int array[], int length) {
    //After analysis, if the array is itself a non-negative prefix sum, it is a well-balanced list. As the prefix sum will never go below 0. 
    //Acts like a stack.

    if(non_negative_sum(array, length) == true) return true;
    else return false;
}

int well_balanced_list_gen(int n, int times) {
    int success = 0;
    for(int i = 0; i < times; i++){
        //init array of 2n integers
        int array[2*n];

        //fill the array with 1's and -1s
        generate_num_list(array, 2*n);

        //call the fisher yates algorithm and scramble the list randomly.
        fisher_yates_scramble(array, 2*n);

        //check if the array is successful
        bool check = check_well_balanced_list(array, 2*n);

        if(check == true) success += 1;

    }
    return success;
}


//MAIN FUNCTION. Includes overrides for 
int main(int argc, char** argv){
    doctest::Context context;
    // Taken from DOCTEST
    // defaults
    context.addFilter("test-case-exclude", "*math*"); // exclude test cases with "math" in their name
    context.setOption("abort-after", 5);              // stop test execution after 5 failed assertions
    context.setOption("order-by", "name");            // sort the test cases by their name
    context.applyCommandLine(argc, argv);
    // overrides
    context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail
    int res = context.run(); // run
    if(context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
        return res;          // propagate the result of the tests
    int client_stuff_return_code = 0;

    //My Code
    int loop = 0;
    while(loop != -1){
        int n;
        cout << "Please enter an integer n (-1 to quit): ";
        cin >> n;
        if(n == -1){
            loop = -1;
            continue;
        }
        
        //now we have n, get the number of attempts to create and check.
        int att;
        cout << "Please enter number of iterations: (-1 to quit): ";
        cin >> att;
        if(att == -1){
            loop = -1;
            continue;
        }

        //now we have n and number of attempts. Call function and return number of successes.
        int successes = well_balanced_list_gen(n, att);
        cout << "Number of successes for n=" << n << " and " << att << " attempts is " << successes << endl;
        cout << "Ratio of Success/Attempts: " << successes / (float) att << "\n" << endl;

    }
    return res + client_stuff_return_code;
}

//TEST CASES

//TEST CASE FOR DETERMINISTIC FUNCTIONS
TEST_CASE("Chechking the deterministic functions") {
    SUBCASE("CHECKING SWAP FUNCTION") {
        int a[] = {1, 0};
        int b[] = {1, 2, 3};

        //swap a ints.
        swap_arr(a, 0, 1);
        CHECK(a[0] == 0);

        //swap index 0 and 2 on b.
        swap_arr(b, 0, 2);
        CHECK(b[0] == 3);
        CHECK(b[2] == 1);
    }

    SUBCASE("CHECKING array creator of equal 1's and -1's"){
        int a[10]; // should be 5 1's and 5'-1s
        generate_num_list(a, 10);
        for(int i = 0; i < 5; i++){
            CHECK(a[i] == 1);
            CHECK(a[9-i] == -1);
        }

        int b[50];
        generate_num_list(b, 50);
        for(int i = 0; i < 25; i++){
            CHECK(b[i] == 1);
            CHECK(b[49-i] == -1);
        }
    }
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

