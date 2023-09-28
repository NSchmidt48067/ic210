/*********************************************
Filename: part3.cpp
Author: MIDN Nathaniel Schmidt (265646)
Lab 3 part3 Triangle Determiner
 *********************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  //Declare Variables
  double a, b, c, n1, n2, n3, e, s, l, g = 0, h = 0, sum, sum1;

  //Take in three sides of a triangle
  cout << "Enter side lengths: ";
    cin >> n1 >> n2 >> n3;

  //Determine if two sides are equal
  if (n1 == n2 && n1 > n3){
    cout << "This is a acute isosceles triangle." << endl;
    h = 1;
  }
  else if (n1 == n3 && n1 > n2){
     cout << "This is a acute isosceles triangle." << endl;
  }
   else if (n3 == n2 && n3 > n1){
     cout << "This is a acute isosceles triangle." << endl;
  }
  if (n1 == n2 && n1 < n3){
     cout << "This is a obtuse isosceles triangle." << endl;
  }
  else if (n1 == n3 && n1 < n2){
     cout << "This is a obtuse isosceles triangle." << endl;
  }
   else if (n3 == n2 && n3 < n1){
     cout << "This is a obtuse isosceles triangle." << endl;
  }
  
  
  //Determine the longest side
  if (n1 >= n2 && n1 >= n3){
    c = n1;
    a = n2;
    b = n3;
    sum = n2 + n3;
    if (c > sum) {
      g = 1;
    }
  }
  else if (n2 >= n1 && n2 >= n3){
    c = n2;
    a = n1;
    b = n3;
    sum = n1 + n3;
      if (c > sum) {
      g = 1;
    }
  }
  else if (n3 >= n2 && n3 >= n1){
    c = n3;
    a = n2;
    b = n1;
    sum = n1 + n2;
      if (c > sum) {
      g = 1;
    }
  }

  //Determine what kind of triangle it is
  a = a*a;
  b = b*b;
  c = c*c;
  sum1 = a + b;

  if (n1 == n2 && n2 == n3){
    cout << "This is a acute equilateral triangle." << endl;
  }
  else if (sum1 > c && h ==0){
    cout << "This is a acute scalene triangle." << endl;
  }
  else if (sum1 == c && h == 0){
    cout << "This is a right triangle." << endl;
  }
  else  if (sum1 < c && g != 1){
    cout << "This is a obtuse scalene triangle." << endl;
      }
   else  if (sum < n1 || sum < n2 || sum < n3) {
    cout << "Error! these lengths violate the triangle inequality!" << endl;
  }
  return 0;
}
