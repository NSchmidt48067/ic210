
/*********************************************
Filename: hw06.cpp
Author: MIDN Nathaniel Schmidt (265646)
Add or Square
 *********************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  //Declare Variables
  double a, b, num, numfinal;
  char garbage;
  string function, p1, garbage2, p2;
  
  //Read numbers
  cout << "Values for a and b? " ;
  cin >> a >> garbage >> b;

  //Ask for command
  cout << "What do you want? ";
  cin >> function >> p1;
  
  if (function == "add"){
    cin >> garbage2 >> p2;
  }
  
  //Execute command and print out answer
  if (p1 == "a") {
    numfinal = pow(a, 2);
    cout << "a = " << numfinal << " and b = " << b << endl;
  }

  else if (p2 == "a"){
    num = stod(p1);
    numfinal = num + a;
    cout << "a = " << numfinal << " and b = " << b << endl;
  }
  
  else if (p1 == "b"){
 numfinal = pow(b, 2);
    cout << "a = " << a << " and b = " << numfinal << endl;
  }
  
  else if (p2 == "b"){
 num = stod(p1);
    numfinal = num + b;
    cout << "a = " << a << " and b = " << numfinal << endl;
  }
  
  return 0;
}
