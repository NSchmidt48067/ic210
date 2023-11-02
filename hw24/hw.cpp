/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Powers
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
  
double pow(double x, int n);

int main()
{
//Declare Variables
  double x;
  int n;
//Take in variables
  cout << "Enter x and n: ";
  cin >> x >> n;
  cout << "x^n is " << pow(x,n) << endl;
  return 0;
}

double pow(double x, int n){//Function that finds the power of the number
    if (n == 0)//Base Case
    return 1;

else {
    return x * pow(x, n - 1);//Becomes x * x * x * x * x ... * 1
}
}