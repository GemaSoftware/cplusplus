#include "lambdas.h"

std::vector<int> getPerfectInts(const std::vector<int> list){
    std::vector<int> vec;
    //capture by reference so we can access vec directly in lambda.
    std::for_each(list.begin(), list.end(), [&](const int& perfect_number){
        //get sum of all divisors
        int sum=0;
        for(int y = 1; y < perfect_number; y++){ if((perfect_number % y) == 0){ sum += y; } }
        if(sum == perfect_number){ vec.push_back(perfect_number); } else { }
    });
    return vec;
}



