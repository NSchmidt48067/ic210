/*********************************************
Filename: p4.cpp
Author: MIDN Nathaniel Schmidt (265646)
Random deck
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int* printdeck(int* deck);//Prints out the deck at the start
int* createdeck(int num);//Creates the deck in a function
void print(int* hand, int turn);//Prints out the cards in a hand
int* deal(int* hand, int* deck, int turn, int num);//Deals out the cards to the user and dealer
int* shuffle(int* deck, int seed, int num);//Takes the created deck and shuffles it around

int main() {
 //Declare Variables
  int num = 0, p = 0, d = 0;//Counters for deck, player and dealer respectively
  int seed = 0;
  char com;
  int* deck;
  deck = new int[52];//Create the array that holds the deck
  int* phand;
  phand = new int[52];//Array for player's hand
  int* dhand;
  dhand = new int[52];//Arry for dealer's hand
  
  cout << "Shuffle: [n | u <seed>]: ";//Gets a seed for random numbers
  cin >> com;
  
  deck = createdeck(num);//Creates the deck
  
  if (com == 'u'){//Determines the command given to shuffle the deck or not
    cin >> seed;
    deck = shuffle(deck, seed, num);
  }
  printdeck(deck);
  
  cout << endl;
  
  for (int i = 0;i < 2;i++){//crates and prints out the first two cards to the dealer and player
    phand = deal(phand, deck, p, num);
    num++;//num keeps track of how many cards have been dealt out
    p++;//p keeps track of how many cards are in the player's hand
    
    dhand = deal(dhand, deck, d, num);
    num++;//num keeps track of how many cards have been dealt out
    d++;//d keeps track of how many cards are in the dealer's hand
  }
  
  cout << "Player: ";
  print(phand, p);
  
  cout << "Dealer: ";
  print(dhand, d);
  
  for (int i = 1; i <= 3;i++){//Controls the rounds played
    cout << endl << "Round " << i << " Player's turn" << endl;//Player turn
    cout << "hit or stand ? [h/s] ";
    cin >> com;
    cout << endl;
    
    if (com == 'h'){//Determines the command given by the user
      phand = deal(phand, deck, p, num);
      p++;
      num++;
    }
    
    cout << "Player: ";//Prints out player's and dealer's hands
    print(phand, p);
    
    cout << "Dealer: ";
    print(dhand, d);
    
    cout << endl  << "Round " << i << " Dealer's turn" << endl;//Dealer turn
    cout << "hit or stand ? [h/s] ";
    cin >> com;
    
    if (com == 'h'){//Determines the command given by the user
      dhand = deal(dhand, deck, d, num);
      d++;
      num++;
    }
    
    cout << endl  << "Player: ";//Prints out the final hands
    print(phand, p);
    
    cout << "Dealer: ";
    print(dhand, d);
  }
  
  
  return 0;
}

int* createdeck(int num){//Creates a deck in order
  int* deck = new int[52];    
  
  for (int n = 100; n <= 400; n = n + 100){//Loop to determine the suit
    
    for (int i = 2; i <= 14; i++){//Loop to determine the card value
      deck[num] = i + n;
      num++;
    }
  }
  
  return deck;
}

int* printdeck(int* deck){//prints out the deck after it's been shuffled
  
  cout << "[";
  for (int i = 0;i < 52;i++){
    if (i == 51){//Doesn't print a space if its the last number to follow parameters
      cout << deck[i];
    }
    else{
      cout << deck[i] << " ";
    }
  }
  cout << "]" << endl;
  return deck;
}

void print (int* hand, int turn){//Prints out the hand entered
  if (hand[0] == 0){//If the hand has no cards
    cout << "[]";
  }
  else{//If the hand has at least one card in his hand
    cout << "[";
    for (int i = 0; i != turn; i++){//Loop to print out the entirety of the hand
      if (i == turn - 1){//When the final card in the hand is being printed
	cout << hand[i] << "]";
      }
      else {
	cout << hand[i] << " ";
      }
    }
  }
  cout << endl;
}

int* deal(int* hand, int* deck, int turn, int num){//Deals out a new card to a hand
  hand[turn] = deck[num];
  return hand;
}

int* shuffle(int* deck, int seed, int num){//Shuffles the deck
  srand(seed);
  for (int i = 0; i < 52;i++){
    int rando;
    rando = rand() % 52;
    swap(deck[i], deck[rando]);//Swaps the cards for a random card
  }
  return deck;
}
