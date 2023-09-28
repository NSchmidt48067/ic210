/*********************************************
Filename: part1.cpp
Author: MIDN Nathaniel Schmidt (265646)
Lab 3 part1
 *********************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  //Declare Variables
  char g;
  double x1, y1, x2, y2, x3, y3;

  //Take in the three points
  cin >> g >> x1 >> g >> y1 >> g >> g  >>  x2 >> g >> y2 >> g >> g  >> x3 >> g >> y3;

  //Print out the boundries of the Box
  cout << x1 << " "  <<  y3;
  cout << x1 << " "  <<  y2;
  cout << x3 << " "  <<  y2;
  cout << x3 << " "  <<  y3
  cout << x1 << " "  <<  y3;
  
  return 0;
}
