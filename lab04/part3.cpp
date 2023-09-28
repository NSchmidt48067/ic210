/*********************************************
Filename: part1.cpp
Author: MIDN Nathaniel Schmidt (265646)
Lab 4 part3
 *********************************************/
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
  //Declare Variables
  double Ctemp, Ftemp = 0, ttemp, atemp, min = 100, max = -100;
  int n = 0, time;
  string filenamein, filenameout, garbage, date, datemin, datemax;

  //Enter File Names
  cin >> filenamein >> filenameout;
  ifstream file(filenamein);

  //Create a file to write to
  ofstream out(filenameout);
  out << "day\thour\ttemp" << endl;

  //The While loop to find average temperature
  file >> garbage;
  file >> garbage;
  if (file){
    //If the file does exist, it will go to the loop
    while (file >> date >> time >> garbage >> Ctemp) {
    time = time + 1;

    Ftemp = 9.0/5.0; //Fahrenheit and avg Calculation
    Ftemp = Ftemp*Ctemp;
    Ftemp = Ftemp + 32;
    ttemp = ttemp + Ftemp;
    n++;

    if (Ftemp < min){
      min = Ftemp;
      datemin = date;
    }

    if (Ftemp > max){
      max = Ftemp;
      datemax = date;
    }

    out << date << " " << time << "\t" << Ftemp << endl;
  }
    
  }
  
  else {// If the file doesn't exist, the program will end
    cout << "Could not open file '" << filenamein << "'" << endl;
    return 1;
  }

  //Print out the average temperature
  atemp = ttemp/n;
  cout << "file: " << filenamein << endl << "ave: " << atemp << endl;
  cout << "min: " << min << " on " << datemin << endl;
  cout << "max: " << max << " on " << datemax << endl;  
  cout << "output in: " << filenameout << endl;
  return 0;
}
