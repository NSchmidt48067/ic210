/*********************************************
Filename: part1.cpp
Author: MIDN Nathaniel Schmidt (265646)
Playing a Simple game
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  //Declare Variables
  int p, w;
  string board, garbage;
  char g, death;

  //Enter board name
  cin >> board;

  
  
  ifstream fin(board);

  if (!fin){//Does the file exist?
    cout << "File not found!" << endl;
    return 1;
  }
  else {//Yes, it exists
  
  fin >> garbage >> g >> w;

  cout << "Enter position between 1 and " << w << " : ";
  cin >> p;
  
  if (p >= 1 && p <= w){//Is the position entered within the parameters
  
  for (int n = 1; fin >> g; n++){//Keeps track of the number of rows
    for (int i = 1; i <= w; i++){//Keeps track of the number of columns
      fin >> death;
      if (death == 'X' && p == i){//If it finds an X and the entered position is the same as the column the X is found in 
	cout << "You died on step " << n << endl;
	return 1;
      }
      
    }
    fin >> g;
  }

  }

  else {//Invalid Position
    cout << "Invalid position!" << endl;
    return 1;
  }
  cout << "You survived!" << endl;
  }
  return 0;
}
