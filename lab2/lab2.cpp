#include "../week2/PrefixSum.h"
#include "lab2.h"
#include <iostream>


using namespace std;

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

int main(){
    //this is where we will do basic testing.
    int n;
    cin >> n; 
    int att;
    cin >> att;

    int success = 0;

    for(int i = 0; i < att; i++){
        int array[n];

    //generate the list of numbers that are 1's and -1's
    generate_num_list(array, n);

    //call the fisher yates algorithm on the array.
    fisher_yates_scramble(array, n);


    if(non_negative_sum(array, n) == true){
        success+=1;
    }
    }

    cout << "successes out of " << att << " attempts is " << success << endl;


    return 0;
}