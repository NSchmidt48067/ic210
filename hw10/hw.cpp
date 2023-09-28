/*********************************************
Filename: hw10.cpp
Author: MIDN Nathaniel Schmidt (265646)
Child Vs Adult
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  //Declare Variables
  string garbage, filename;
  int month, day, year, a = 0, c = 0;
  char g;
  
  //Get File
  cout << "Filename: ";
  cin >> filename;
  ifstream file(filename);

  if (file) {
    while (file >> garbage){
      file >> month >> g;
      file >> day >> g;
      file >> year >> g;

      if (year <= 19){//Put the years into four digit format for easy determination
	year = year + 2000;
      }
      
      else {
	year = year + 1900;
      }
      
      // Determine child or adult
      if (year < 2000) {
	a++;
      }
      else if (month < 9 && year <= 2000){
	a++;
      }
      else if (day <= 27 && month <= 9 && year <= 2000){
	a++;
      }
      else{
	c++;
      }
    }
  }

  else {
    cout << "File not found!" << endl;
    return 1;
  }

  cout << a << " adults and " << c << " children" << endl;
  return 0;
}
