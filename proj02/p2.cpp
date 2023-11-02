/*********************************************
Filename: p2.cpp
Author: MIDN Nathaniel Schmidt (265646)
Dealing to a player and dealer
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
 //Declare Variables
  int num = 0, p = 0, d = 0;//Counters for deck, player and dealer respectively
  string com;
  int* deck;
  deck = new int[52];//Create the array that holds the deck
  int* phand;
  phand = new int[52];//Array for player's hand
  int* dhand;
  dhand = new int[52];//Arry for dealer's hand
  
  
  
  cout << "[";
  
  for (int n = 100; n <= 400; n = n + 100){//Loop to determine the suit
    
    for (int i = 2; i <= 14; i++){//Loop to determine the card value
      deck[num] = i + n;
      
      if (deck[num] == 414){//Doesn't print a space if its the last number to follow parameters
	cout << deck[num];
      }
      else{
	cout << deck[num] << " ";
	num++;
      }
    }
  }
  
  cout << "]" << endl << "> ";
  
  cin >> com;//Takes in the command
  
  num = 0;
  
  phand[0] = 0;//Initializes the values so that if the command is to print a hand before cards have been dealt, it won't give an error in valgrind
  dhand[0] = 0;
  
  do{//Allows the user to keep dealing cards until they want to quit.
    if (com == "print-p"){
      if (phand[0] == 0){//If the player has no cards
	cout << "[]";
      }
      else{//If the player has at least one card in his hand
	cout << "[";
	for (int i = 0; i != p; i++){//Loop to print out the entirety of the player's hand
	  if (i == p - 1){//When the final card in the player's hand is being printed
	    cout << phand[i] << "]";
	  }
	  else {
	    cout << phand[i] << " ";
	  }
	}
      }
      cout << endl << "> ";
    }
    else  if (com == "print-d"){
      if (dhand[0] == 0){//If the dealer has no cards in his hand
	cout << "[]";
      }
      else{//If the dealer has at least one card in his hand
	cout << "[";
	for (int i = 0; i != d; i++){//Loop to print out  the dealer's hand
	  if (i == d - 1){//When the final card in the dealer's hand is being printed
	    cout << dhand[i] << "]";
	  }
	  else {
	    cout << dhand[i] << " ";
	  }
	}
      }
      cout << endl << "> ";
    }
    else  if (com == "deal-p"){//Deals a card to the player
      phand[p] = deck[num];
      cout << "> ";
      num++;//num keeps track of how many cards have been dealt out
      p++;//p keeps track of how many cards are in the player's hand
    }
    else  if (com == "deal-d"){
      dhand[d] = deck[num];
      cout << "> ";
      num++;//num keeps track of how many cards have been dealt out
      d++;//d keeps track of how many cards are in the dealer's hand
    }
    else{//If the user doesn't input a proper command, the code ends
      delete [] phand;
      delete [] dhand;
      delete [] deck;
      return 0;
    }
  }while(cin >> com);
  
  delete [] phand;
  delete [] dhand;
  delete [] deck;
  
  return 0;
}
