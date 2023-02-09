#include <iostream>
#include "ECRemoveElement.h"
using namespace std;

void ECRemoveSpace(int nums[], int len, int val)
{
    //init temp variable to store index of value to just swap
    int t = 0;

    //for every index in nums
    for(int i =0; i < len; i++){

        //if the current value doesnt equal the value we are looking for, set index of the dupliecated one to the current index.
        if(nums[i] != val){
            nums[t] = nums[i];
            //bump index up
            t++;
        }
    }       
}


