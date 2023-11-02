/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Dot Product
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  //Declare Variables
  int num;
  char g, x, y;
  double sum;

  cin >> g >> g >> num;//Input for how many numbers each vector will have
  double* p1;
  p1 = new double[num];
  double* p2;
  p2 = new double[num];

  cin >> x >> g >> g;
  for (int n = 0; n < num;n++){//Takes in the numbers into the array
    cin >> p1[n] >> g;
  }

  cin >> y >> g >> g;
  for (int n = 0; n < num;n++){//Takes in the second vectors numbers into the array
    cin >> p2[n] >> g;
  }
    
  cout << "<" << x << "," << y << "> = ";//Print out the final product
  for (int i = 0; i < num; i++){
    cout << p1[i] << " * ";
    cout << p2[i] << " ";
    
    sum = sum + p1[i] * p2[i];
    
    if (i == num - 1){//If statement to determine if a + or = should be printed
      cout << "= " << sum << endl;
    }
    else{
      cout << "+ ";
    }
  }
    
  return 0;
}
