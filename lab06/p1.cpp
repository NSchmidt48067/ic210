/*********************************************
Filename: p1.cpp
Author: MIDN Nathaniel Schmidt (265646)
Rolling Dice
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int rolldie();

int main() {
  //Declare Variables
  int seed, x, y;

  cout << "Enter seed value: ";//Take in Seed value
  cin >> seed;
  srand(seed);
  
  for (int i = 0; i < 5; i++){//Roll two dice 5 times
    x = rolldie();
    y = rolldie();
    cout << "Player rolled " << x  << " + " << y << " = " << x + y << endl;
  }

  
  return 0;
}

int rolldie(){//Determines the random rolled value
  int roll = 0;
  while (roll <= 0 || roll >=7){
  roll = rand() % 8;
  }
  return roll;
}
