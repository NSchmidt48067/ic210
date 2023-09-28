/*********************************************
Filename: hw09.cpp
Author: MIDN Nathaniel Schmidt (265646)
Finding the best student
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  //Declare Variables
  string filename, name, g, bestp;
  double grade, hw, quiz, test, bestg = 0;
  
  //Enter the filename
  cout << "Filename: ";
  cin >> filename;
  ifstream file(filename);

  //Clean out the Garbage
  file >> g;
  file >> g;
  file >> g;
  file >> g;
  
  //The while loop
   while (file >> name){

  cout << name << "   ";

  file >> hw;
  file >> quiz;
  file >> test;

  grade = .2*hw + .2*quiz + .6*test;
  cout << grade << endl;

  if (grade >= bestg){
    bestg = grade;
    bestp = name;
  }
 
   }

   cout << "The best student is " << bestp << "." << endl;


  return 0;
}
