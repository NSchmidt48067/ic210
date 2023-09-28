/*********************************************
Filename: p2.cpp
Author: MIDN Nathaniel Schmidt (265646)
Binary to Decimal P2
 *********************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  //Declare Variables
  int num, num2, a, b, c, d;
 
  //Read Number betweem 0 and 15
  cout << "Enter a number between 0 and 15: ";
  cin >> num;
 
  //Determine binary number
  num2 = num;
  a =num%2;
    num=num/2;
  b =num%2;
    num=num/2;
  c =num%2;
    num=num/2;
  d =num%2;
    num=num/2;

  //Print the Binary number
  cout << num2  << " in binary is " << d << c << b << a << endl;
  
  return 0;

}
