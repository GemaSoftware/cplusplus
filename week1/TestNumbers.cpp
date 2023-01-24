#include <iostream>
#include "ECNumbers.h"
#include "ECCalculator.h"

using namespace std;

int main()
{
  // read in an integer n
  // your code here
    int test;
    cin >> test;

  // print out the square of it
  // your code here
  cout << "Number Squared: " << ECNumbers::ECSquareN(test) << endl;

  // print out 2n  
  // your code here
  cout << "Doubled N: " << ECNumbers::ECDoubleN(test) << endl;

  // print out 4 times of n by invoking ECCalculator's function
  // your code here
  cout << "4 times the number: " << ECFourTimesN(test) << endl;

  return 0;
}