/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Voting
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Declaring structs
struct car{
  string c, garbage;
  double  pos, vel;
};

  
int main() {
  //Declare Variables
  char g;
  int cars;
  double npos;
  string file;

cin >> file;
ifstream fin(file);

  fin >> g >> g >> cars;

  car* A = new car[cars];

for (int i = 0; i < cars; i++){
    fin >> A[i].c >> A[i].garbage >> A[i].pos >> A[i].garbage >> A[i].vel;
}

  for (int n = 0; n < 9; n++){
    cout << "hour " << n << " ";
    for (int i = 0; i < cars; i++){
      if (n != 0)
        A[i].pos = A[i].pos + A[i].vel;
      cout << "[" << A[i].c << ":" << A[i].pos << "]";
    }
    cout << endl;
  }

  return 0;
}
