/*********************************************
Filename: p2.cpp
Author: MIDN Nathaniel Schmidt (265646)
CRAPS
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int rolldie();
int throwdice();

int main() {
  //Declare Variables
  int seed, i = 1, val;

  cout << "Enter seed value: ";//Take in Seed value
  cin >> seed;
  srand(seed);
  
  while(i != 0){//A loop to keep rolling the dice until someone wins
    val = throwdice();
    if (val == 0){
      cout << " Player wins!" << endl;
      i = 0;
    }

    else if(val == -1){
      cout << " House wins!" << endl;
      i = 0;
    }

    else {
      cout << " roll again" << endl;
    }
  }

  
  return 0;
}

int rolldie(){//Returns the random values for the rolled dice
  int roll = 0;
  while (roll <= 0 || roll >=7){
  roll = rand() % 8;
  }
  return roll;
}

int throwdice(){//Calls upon the rolldie() function and returns a house, player win or the number rolled
  int i = 1, x, y;
    x = rolldie();
    y = rolldie();

    cout << "Player rolled " << x << " + " << y << " = " << x + y;
    
    if (x + y == 7 || x + y == 11){
      return 0;
    }

    else if (x + y == 2 || x + y == 3 || x + y == 12){
      return -1;
    }

    else {
      return x+y;
    }
}
