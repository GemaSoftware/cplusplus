#include "lab2.h"
#include <iostream>


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

void fisher_yates_scramble(int array[], int length){
    for(int i = length-1; i > 1; i--){
        //j will be the random index to swap with. [0, length)
        int j = rand() % length;
        //swap the two values
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
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


int main(){
    //Will create Unit Testing for each function in another file. This is mainly to check for the convergence.
    //So with n=30, we will run the algorithm at least 10000 times.
    cout << "Successes (n=30, att=1000): " << well_balanced_list_gen(30, 1000) << endl;
    cout << "Successes (n=30, att=2000): " << well_balanced_list_gen(30, 2000) << endl;
    cout << "Successes (n=30, att=4000): " << well_balanced_list_gen(30, 4000) << endl;
    cout << "Successes (n=30, att=8000): " << well_balanced_list_gen(30, 8000) << endl;
    cout << "Successes (n=30, att=16000): " << well_balanced_list_gen(30, 16000) << endl;

    return 0;
} 