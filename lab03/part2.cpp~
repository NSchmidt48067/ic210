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
  double x1, y1, x2, y2, x3, y3, maxx, minx, maxy, miny;


  //Take in the three points
  cin >> g >> x1 >> g >> y1 >> g >> g  >>  x2 >> g >> y2 >> g >> g  >> x3 >> g >> y3;

  //Find the Corners of the Box
  if (x1 >= x2 && x1 >= x3){
    maxx = x1;
  }
  else if (x2 >= x1 && x2 >= x3){
     maxx = x2;
  }
  else {
     maxx = x3;
  }

   if (x1 <= x2 && x1 <= x3){
    minx = x1;
  }
  else if (x2 <= x1 && x2 <= x3){
    minx = x2;
  }
  else {
    minx = x3;
  }

   
    if (y1 >= y2 && y1 >= y3){
    maxy = y1;
  }
  else if (y2 >= y1 && y2 >= y3){
    maxy = y2;
  }
  else {
    maxy = y3;
  }

   if (y1 <= y2 && y1 <= y3){
     miny = y1;
  }
  else if (y2 <= y1 && y2 <= y3){
    miny = y2;
  }
  else {
     miny = y3;
  }

   //Printing the Paremeters of the Box
   cout << minx << " " << miny << endl;
   cout << minx << " "  << maxy << endl;
   cout << maxx << " "  << maxy << endl;
   cout << maxx << " "  << miny << endl;
   cout << minx << " "  << miny << endl << endl;

   //Printing the parameters of the triangle
   cout << x1 << " "  << y1 << endl;
   cout << x2 << " "  << y2 << endl;
   cout << x3 << " "  << y3 << endl;
   cout << x1 << " "  << y1 << endl;
   
   
  return 0;
}
