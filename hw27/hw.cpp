/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Voting
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Point3
{
  double x, y, z;
};
  
int main() {
  //Declare Variables
   Point3 a, b;
   char g;

//I wasn't thinking about overloading, and just followed a part of the class notes that did this. 
//I understand how it works now
  cin >> g >> a.x >> g >> a.y >> g >> a.z >> g >> g >> b.x >> g >> b.y >> g >> b.z >> g;

//Print out solution
  cout << "Inner product of " << "(" << a.x << ", " << a.y << ", " << a.z << ")" <<
       " and " << "(" << b.x << ", " << b.y << ", " << b.z << ")" 
       << " is " << a.x*b.x + a.y*b.y + a.z*b.z << endl;

  return 0;
}