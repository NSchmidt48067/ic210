/**********************************************
Filename: p6.cpp
Author: MIDN Nathaniel Schmidt (265646)
POINTS
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int* hit(int* hand);//Deals a card to the player or dealer
int* createdeck(int num, int* deck);//Creates a deck in order
void print(int* phand, int* dhand, int p, int d);//Prints out the game
int* deal(int* hand, int* deck, int turn, int num);//Deals the starting cards
int* shuffle(int* deck, int seed, int num);//Shuffles the ordered deck randomly
int score(int points, int* hand, int turn);//Calculates and prints out the points

int main() {
 //Declare Variables
  int num = 0, p = 0, d = 0, ppoints = 0, dpoints = 0, round = 1;//Counters for deck, player and dealer respectively
  int seed = 0;
  char comp = 'h', comd = 'h', com;
  int* deck;
  deck = new int[52];//Create the array that holds the deck
  int* phand;
  phand = new int[52];//Array for player's hand
  phand[0] = 0;
  int* dhand;
  dhand = new int[52];//Arry for dealer's hand
  dhand[0] = 0;

  cout << "Shuffle: [n | u <seed>]: ";//Gets a seed for random numbers
  cin >> com;

  deck = createdeck(num, deck);//Creates the deck
  
  if (com == 'u'){//Determines the command given to shuffle the deck or not
    cin >> seed;
    deck = shuffle(deck, seed, num);
  }
  
  cout << endl;
  
  for (int i = 0;i < 2;i++){//crates and prints out the first two cards to the dealer and player
    phand = deal(phand, deck, p, num);
    num++;//num keeps track of how many cards have been dealt out
    p++;//p keeps track of how many cards are in the player's hand

    dhand = deal(dhand, deck, d, num);
    num++;//num keeps track of how many cards have been dealt out
    d++;//d keeps track of how many cards are in the dealer's hand
  }
  
  print(phand, dhand, p, d);//Prints out the cards

    ppoints = score(ppoints, phand, p);//Calculates and prints out the points
    dpoints = score(dpoints, dhand, d);
    cout << "Player " << ppoints << ", Dealer " << dpoints;

  do{//Controls the rounds played
    cout << endl << "Round " << round << " Player's turn" << endl;//Player turn
    cout << "hit or stand ? [h/s] ";
    cin >> comp;

    if (comp == 's' && comd == 's')
        break;
    
    cout << endl;

    if (comp == 'h'){//Determines the command given by the user
      phand = deal(phand, deck, p, num);
      p++;
      num++;
    }

    print(phand, dhand, p, d);//Prints out the cards

    ppoints = score(ppoints, phand, p);//Calculates and prints out the points
    cout << "Player " << ppoints << ", Dealer " << dpoints;
    
    cout << endl  << "Round " << round << " Dealer's turn" << endl;//Dealer turn
    cout << "hit or stand ? [h/s] ";
    cin >> comd;

    if (comp == 's' && comd == 's')
        break;
    
   cout << endl;

    if (comd == 'h'){//Determines the command given by the user
      dhand = deal(dhand, deck, d, num);
      d++;
      num++;
    }
    
    print(phand, dhand, p, d);//Prints out the cards

    //Calculates and prints out the points
    dpoints = score(dpoints, dhand, d);
    cout << "Player " << ppoints << ", Dealer " << dpoints;

    round++;
  }while (round != 0);

cout << endl;
  print(phand, dhand, p, d);//Prints out the cards
  cout << "Player " << ppoints << ", Dealer " << dpoints << endl;

  delete [] deck;
  delete [] dhand;
  delete [] phand;

  return 0;
}

int* createdeck(int num, int* deck){//Creates a deck in order  
  for (int n = 100; n <= 400; n = n + 100){//Loop to determine the suit
    for (int i = 2; i <= 14; i++){//Loop to determine the card value
      deck[num] = i + n;
      num++;
    }
  }
 
  return deck;
}

void print(int* phand, int* dhand, int p, int d){//Prints out the hand entered
  string clubs = "\u2663";//Creates strings for the suits
  string diamonds = "\u2666";
  string hearts = "\u2665";
  string spades = "\u2660";
  int suit, val, big;
  char face;

  if (p > d){//Determines which user has more cards in their hand
    big = p;
    for (int i = d; i < big; i++){
      dhand[i] = 0;
    }
  }
  else{
    big = d;
    for (int i = p; i < big; i++){
    phand[i] = 0;
    }
  }

  cout << " Player Dealer" << endl;
  for (int i = 0; i < big;i++){//Loop to run through until the number of cards is up

    //PLAYER

    if (phand[i] == 0){//Determines the suit and card value
      val = 0;
    }
    else if (phand[i] < 150){//Determines the suit and card value
      val = phand[i] - 100;
      suit = 1;
    }
    else if (phand[i] < 250){
      val = phand[i] - 200;
      suit = 2;
    }
    else if (phand[i] < 350){
      val = phand[i] - 300;
      suit = 3;
    }
    else {
      val = phand[i] - 400;
      suit = 4;
    }
    
    if (val != 0){
      
      if (val == 11){//if statements determing if the card is greater than 10 and thus needs a letter to represent it
	face = 'J';
      }
      else if (val == 12){
	face = 'Q';
      }
      else if (val == 13){
	face = 'K';
      }
      else if (val == 14){
	face = 'A';
      }
      
      cout << "| ";//Start of printing
      if (val == 10){//If statement to determine whether to print a space, 10, or letter
	cout << val;
      }
      else if (val < 10){
	cout << " " << val;
      }
      else {
	cout << " "  << face;
      }
      
      if (suit == 1){//If statement that prints out the suit
	cout << clubs;
      }
      else if (suit == 2){
	cout << diamonds;
      }
      else if (suit == 3){
	cout << hearts;
      }
      else {
	cout << spades;
      }
    }
    else{
      cout << "|    ";
    }
    
    //DEALER
    
    if (dhand[i] == 0){//Determines suit and card value
	val = 0;
      }
      else if (dhand[i] < 150){
	val = dhand[i] - 100;
	suit = 1;
      }
      else if (dhand[i] < 250){
	val = dhand[i] - 200;
	suit = 2;
      }
      else if (dhand[i] < 350){
	val = dhand[i] - 300;
	suit = 3;
      }
      else {
	val = dhand[i] - 400;
	suit = 4;
      }
      
      if(dhand[i] != 0){//If statement that determines if there is a value for that hand
	if (val == 11){//if statements determing if the card is greater than 10 and thus needs a letter to represent it
	  face = 'J';
	}
	else if (val == 12){
	  face = 'Q';
	}
	else if (val == 13){
	  face = 'K';
	}
	else if (val == 14){
	  face = 'A';
	}
      
      cout << "  | ";//Start of printing

      if (val == 10){//If statement to determine whether to print a space, 10, or letter
	cout << val;
      }
      else if (val < 10){
	cout << " " << val;
      }
      else {
	cout << " " << face;
      }
      
      if (suit == 1){//If statement that prints out the suit
	cout << clubs;
      }
      else if (suit == 2){
	cout << diamonds;
      }
      else if (suit == 3){
	cout << hearts;
      }
      else {
	cout << spades;
      }
      
      cout << "  |";
    }
    else{
      cout << "  |      |";
    }
    cout << endl;
  }

  
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

int score(int points, int* hand, int turn){
int val;
points = 0;
for (int i = 0; i < turn; i++){
    if (hand[i] == 0){//Determines suit and card value
	    val = 0;
        } 
        else if (hand[i] < 150){
	        val = hand[i] - 100;
        }
        else if (hand[i] < 250){
    	    val = hand[i] - 200;
        }
        else if (hand[i] < 350){
    	    val = hand[i] - 300;
        }
        else {
    	    val = hand[i] - 400;
        }

    if (val == 14){//Determines the point value for face cards and aces
        val = 11;
    }
    else if (val >= 10){
        val = 10;
    }

    points = points + val;
    }

for (int i = 0; i < turn; i++){
if ((hand[i] == 114 || hand[i] == 214 || hand[i] == 314 || hand[i] == 414) && points > 21)
points = points - 10;
}

return points;
}