/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Making a Function
 *********************************************/
#include <iostream>
using namespace std;


int firstfactor(int);

int main()
{
  // Get integer n, n > 1, from user
  int n;
  cout << "Enter an integer larger than 1: ";
  cin >> n;

  // Print out factorization
  cout << "The factorization of " << n << " is ";
  while(n > 1)
  {
    // get & print next prime factor
    int f = firstfactor(n);
    cout << '(' << f << ')';
    n = n / f;
  }
  cout << endl;

  return 0;
}

int firstfactor(int n){//Finds the factors of the input number
  int i = 2, r;
  do {
    r = n % i;
    i++;
  } while(r != 0);
    i--;
    return i;
}
