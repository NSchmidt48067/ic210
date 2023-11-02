/*********************************************
Filename: p1.cpp
Author: MIDN Nathaniel Schmidt (265646)
Creating a deck
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main() {
  //Declare Variables
  int num = 0;
  int* deck;
  deck = new int[52];//Create the array that holds the deck
  
  cout << "[";
  
  for (int n = 100; n <= 400; n = n + 100){//Loop to determine the suit
    
    for (int i = 2; i <= 14; i++){//Loop to determine the card value
      deck[num] = i + n;
      if (deck[num] == 414){//Doesn't print a space if its the last number to follow parameters
	cout << deck[num];
      }
      else{//Prints a space after the number
	cout << deck[num] << " ";
	num++;
      }
    }
  }
  
  cout << "]" << endl;
  
  return 0;
}
