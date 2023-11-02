/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Divisible by three
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
  
int main() {
  //Declare Variables
  int row, col, sum = 0;
  char g;
  
  //Input
  cout << "What size? ";
  cin >> row >> g >> col;
  
  //Create the Array that reads in the input
  int** A = new int* [row];
  for (int i = 0; i < row; i++){
    A[i] = new int [col];
    
  }
  
  //Create the Arrays that records what rows and columns are divisible by three
  int* R = new int [row];
  int* C = new int [col];
  
  
  //Take in the arrays inputs
  for (int i = 0; i < row; i++){
    for (int n = 0; n < col; n++){
      cin >> A[i][n];
    }
  }
  
  //For loop to determine which rows are divisible by three
  for (int i = 0; i < row; i++){
    for (int n = 0; n < col; n++){
      sum = sum + A[i][n];
    }
    sum = sum % 3;
    if (sum == 0)//Records which row is divisible by three
      R[i] = 1;

    else
      R[i] = 0;
    sum = 0;
  }
  
  //For loop that determines which columns are divisible by three
  for (int i = 0; i < col; i++){
    for (int n = 0; n < row; n++){
      sum = sum + A[n][i];
    }
    sum = sum % 3;
    if (sum == 0)//Records which column is divisible by three
      C[i] = 1;
    
    else
      C[i] = 0;
    sum = 0;
  }
  
  cout << "rows:";//Prints out which rows are divisible by three
  for (int i = 0; i < row; i++){
    if (R[i] == 1)
      cout << " " << i;
  }
  
  cout <<  endl << "cols:";//Prints out which columns are divisible by three
  for (int i = 0; i < col; i++){
    if (C[i] == 1)
      cout << " " << i;
  }
  cout << endl;
  
  //Delete the arrays
  for (int i = 0; i < col; i++){
    delete [] A[i];
  }
  delete [] A;
  delete [] C;
  delete [] R;
  return 0;
}