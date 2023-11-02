/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
GCD
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int gcd(int x, int y);

int main() {
  //Declare Variables
  char g;
  int n1, n2, val;
  do{//Loop to take in all numbers
    cin >> n1 >> g >> n2 >> g;
    val = gcd(n1, n2);
    if (val == 1){
      cout << n1 << "/" << n2 << " is in lowest terms!" << endl;
    }
    
  }while(g != ';');

  
  return 0;
}

int gcd(int x, int y){//Finds GCD
  int rx, ry, small;
  if (x >= y){
    small = y;
  }
  else{
    small = x;
  }
  for (int i = 2;i <= small;i++){//Finds GCD; If there is a GCD, return 0
    rx = x % i;
    ry = y % i;
    
    if (rx == 0 && ry == 0){
      return 0;
    }
  }
  return 1;//If no GCD return 1
}
