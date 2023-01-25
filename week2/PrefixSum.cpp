#include "PrefixSum.h"

int prefix_sum(int array[], int length){
    //returns the sum of the array up to index length.

    int temp = 0;
    //case where we ask it to return prefix sum of length 0.
    if(length == 0){
        return array[0];
    }

    //up to the length, just sum every value
    for(int i = 0; i < length; i++){
        temp += array[i];
    }

    //return that value
    return temp;
}

//This function checks that prefix sum at every length is non negative.
bool non_negative_sum(int array[], int length){
    for(int i = 0; i < length; i++){
        if(prefix_sum(array, i) < 0) return false;
    }
    return true;
}

//This function checks that prefix sum at every length is non positive
bool non_positive_sum(int array[], int length){
    for(int i = 0; i < length; i++){
        if(prefix_sum(array, i) > 0) return false;
    }
    return true;
}