/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Making Rectangles
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  //Declare Variables
  int h, w, o;

  //Read in variables
  cout << "Enter height (greater than 2): ";
  cin >> h;
  cout << "Enter width (greater than 2): ";
  cin >> w;
  cout << "Enter offset: ";
  cin >> o;

  //Print Rectangle
  for (int i = 0; i < h; i++){//Controls height
    for (int n = 0; n < o; n++){//Controls offset
      cout << " ";
    }
    if (i == 0 || i == h - 1){
    for (int t = 0; t < w; t++){//Controls width
      cout << "*";
    }
    }
    else {
      cout << "*";
      for (int x = 1; x < (w-1); x++){
	cout << " ";
      }
      cout << "*";
    }
    cout << endl;
  }
  
  return 0;
}
