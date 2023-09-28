/*********************************************
Filename: p1.cpp
Author: MIDN Nathaniel Schmidt (265646)
Binary to Decimal P1
 *********************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  //Declare Variables
  char a, b, c, d;
  int n1, n2, n3, n4, sum;
 
  //Read 4 digit binary number
  cout << "Enter a 4-bit binary number: ";
  cin >> a >> b >> c >> d;
 
 
  //Determine decimal number
  
  n1 = a - '0';
  n2 = b - '0';
  n3 = c - '0';
  n4 = d - '0';

  sum = n1 * pow (2, 3) + n2 * pow (2, 2) + n3 * pow (2, 1) + n4 * pow (2, 0);

  //Print Decimal Number
  cout << "In decimal " << a << b << c << d << " = " << sum << endl;
  return 0;

}
