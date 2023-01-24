#include <iostream>
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


/*
  // your code here
  int i, backwards = len - 1;
  while (i < backwards) {
    if(nums[i] == val) {
    int temp = nums[backwards];
    nums[backwards] = nums[i];
    nums[i] = temp;
    backwards--;
  } else {
    i++;
  }
  }*/



int main()
{
  int nums1[] = {3,2,2,3};
  ECRemoveSpace(nums1, 4, 3); 
  cout << "nums1: ";
  for(int i=0; i<4; ++i)
  {
    cout << nums1[i] << " ";
  } 
  cout << endl;
  int nums2[] = {0,1,2,2,3,0,4,2};
  ECRemoveSpace(nums2, 8, 2); 
  cout << "nums2: ";
  for(int i=0; i<8; ++i)
  {
    cout << nums2[i] << " ";
  } 
  cout << endl;
  return 0;
}
