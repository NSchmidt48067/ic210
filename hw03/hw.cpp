#include <iostream>
using namespace std;

int main(){

  //Declare Variables
  int f1, f2, i1, i2, d1, d2, d, ftf, inf;
  char u;

  //Record Lengths
  cout << "Enter two lengths in feet and inches (larger first!)"<< endl;
  cin >> f1 >> u >> i1 >> u >> u;
  cin >> f2 >> u >> i2 >> u >> u ;
  
  //Calculate the distance
  f1= f1*12;
  f2= f2*12;
  d1= f1+i1;
  d2= f2+i2;
  d= d1-d2;
  inf= d%12;
  ftf= (d-inf)/12;

  //Print the Difference
  cout << "Difference is " << ftf  << "' "  << inf << "''";


}
