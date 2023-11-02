/*********************************************
Filename: p3.cpp
Author: MIDN Nathaniel Schmidt (265646)
YOU'RE FIRED
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int rolldie();
int throwdice(int setpoint);
int firstroll();

int main() {
  //Declare Variables
  int seed, i = 1, val, setpoint;
  char c;

  cout << "Enter seed value: ";//Take in seed value
  cin >> seed;
  srand(seed);


  
  while (i != 0){//Loop that asks the player if they want to keep playing
    setpoint = firstroll();

    if (setpoint == 0){//Determines if the first roll is a winner or not
	cout << " Player wins!" << endl;
	i = 0;
      }
      
      else if(setpoint == -1){
	cout << " House wins!" << endl;
	i = 0;
      }

      else {
	cout << " setpoint is " << setpoint << "!" << endl;
      }
    
    while(i != 0){//Loop that plays the game after the first roll with new parameters
      val = throwdice(setpoint);
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
    cout << "Play again? ";
    cin >> c;
    if (c == 'y'){
      i = 1;
    }
  }

  
  return 0;
}

int rolldie(){//Returns the sum of the random rolls
  int roll = 0;
  while (roll <= 0 || roll >=7){
  roll = rand() % 8;
  }
  return roll;
}

int throwdice(int setpoint){//Determines who won on the 2nd roll and after
  int i = 1, x, y;
    x = rolldie();
    y = rolldie();

    cout << "Player rolled " << x << " + " << y << " = " << x + y;

    
    if (x + y == setpoint){
      return 0;
    }

    else if (x + y == 7 || x + y == 12){
      return -1;
    }

    else {
      return x+y;
    }
}

int firstroll(){//Determines the setpoint and who wins on the first roll
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
