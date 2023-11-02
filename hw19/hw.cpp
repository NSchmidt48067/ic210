/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)

 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Declaring functions
int readN();
int* readData(int n);
void show(int* A, int n);
void swap(int* A, int n);

int main() {
  //Declare Variables
  int n = readN();
  int* A = readData(n);

  string cmd;
  cout << "cmd: ";
  while( (cin >> cmd) && cmd != "quit" ) 
  {
    if( cmd == "show" )
      show(A, n);
    else if ( cmd == "swap" )
      swap(A, n);

    cout << "cmd: ";
  }

  delete[] A;

  return 0;
}

int readN(){//readN function determines the size of the array
  char g;
  int n;
  cin >> g >> g >> n;
  return n;
}

int* readData(int n){//readData reads in the information for the array and returns the array
  int* A = new int[n];
  for (int i = 0;i < n; i++){
    cin >> A[i];
  }
  return A;
}

void show(int* A, int n){//show prints out the stars correlating to the number in the array
  
  for (int i = 0;i < n;i++){
    cout << "[" << i << "] ";
    for (int s = 0;s < A[i];s++){
      cout << "*";
    }
    cout << endl;
  }
}

void swap(int* A, int n){//swap swaps the values in the array
  int x, y, z;

  cin >> x >> y;
  z = A[x];
  A[x] = A[y];
  A[y] = z;
  
}
