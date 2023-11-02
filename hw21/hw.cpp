/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Voting
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Declaring functions

  
int main() {
  //Declare Variables
  int legs, ttime, h, m;

  cout << "How many legs? ";
  cin >> legs;

  string* airport = new string [legs];

  for (int i = 1; i < legs; i++){



  }
  
  ttime = flights (airport, legs);
  if (ttime == 0){
    return 0;
  }

  h = ttime % 60;
  m = ttime - (h * 60);

  cout << "Reverse trip: ";
  for (int i = legs; i >= 0; i--){
    
    cout << airport[i][5] << airport[i][6] << airport[i][7];
    if (i == 0){
      cout << "->";
    }

  }
  cout << airport[0][1] << airport[0][2] << airport[0][3]  <<  endl << "Total time: " << h << " hours " << m << " minutes";  
  return 0;
}

int time (int ttime){
  int h, m;
  char g;
  cin >> h >> g >> m;

  ttime = m + h * 60;
  return ttime;
}

int flights (string* airport, int legs){
  char g;
  int ttime = 0;

  cin >> airport[0];
  ttime = time(ttime);
  for (int i = 1; i <= legs; i++){
    cin >> airport[i];
    
    ttime = time(ttime);
    
    if ((airport[i - 1][5] != airport[i][0]) && (airport[i - 1][6] != airport[i][1]) && (airport[i - 1][7] != airport[i][2])){
      cout << endl << "city mismatch";
      return 0;
    }
  }

 
   return ttime;
}
