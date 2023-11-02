/*********************************************
Filename: hangman.cpp
Author: MIDN Nathaniel Schmidt (265646)
Hangman
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void printSpaced(string s);//Prints a spaced version of the word
string mkShadowString(string s);//Creates an underscore version of the word
string uncover(string original, string covered, char c);//Uncovers the word
string crossOut(char c, string s);//Crosses out guesses from the alphabet

int main()
{//Establish Variables
 int guess = 8, seed;
 string word, shadow, temp;
 string alph = "abcdefghijklmnopqrstuvwxyz";
 char c;

 ifstream fin("words07.txt");//Reads in from the word list

cout << "Welcome to hangman!" << endl;
cout << "Enter a seed value: ";
cin >> seed;

srand(seed);
seed = rand() % 1466;
for (int i = 0; i != (seed + 1); i++){//Chooses the word determined by rand
fin >> word;
}

shadow = mkShadowString(word);//Creates an underscore value of the word
temp = shadow;//Creates a placeholder for the previous shadow to determine if the letter guessed was good or not

 while (guess != 0){//Keeps playing the game until the user runs out of guesses
cout << "Wrong guesses remaining: " << guess << " " << alph;
cout << endl;
printSpaced(shadow);
cout << endl;

cout << ": ";
cin >> c;

alph = crossOut(c, alph);//Crosses out the guessed letter

shadow = uncover(word, shadow, c);//Uncovers the letter guessed if its in the word
if (temp == shadow){//temp is the previous version of shadow and determines if its a correct guess
    guess--;
    cout << "There were no " << c << "'s!" << endl;
}
temp = shadow;//Replacing temp

if (shadow == word){//If the user gets the word, leave the loop
    break;
}
 } 
   
if (shadow == word){//If they win
    cout << "You win!!!! The word was " << word << endl;
}
else {//If they lose
    cout << "You lose!!!! The word was " << word << endl;
}

  return 0;
}

void printSpaced(string s){//Prints a spaced version of the input
  int length;
  length = s.length();
  
  for (int i = 0; i < length; i++){//loop that prints out the word with a space unless its the last letter
    if (i == (length - 1)){
      cout << s[i];
    }
    else {
      cout << s[i] << " ";
    }
  }
  
}

string mkShadowString(string s){//Creates the underscore version of the input
  int length;
  length = s.length();

  for (int i = 0; i < length; i++){//Loop to change the characters to _
    s[i] = '_';
  }
  
  return s;
}

string uncover(string original, string covered, char c){//If the char is one of the letters in the string, it uncovers it in the output
  int length;
  length = original.length();

  for (int i = 0; i < length; i++)//Loop to go through every letter
  {
    if (original[i] == c){
      covered[i] = c;
    }
  }

  return covered;
}

string crossOut(char c, string s){//Crosses out the guessed letter in the alphabet
  int length;
  length = s.length();

  for (int i = 0; i < length; i++){//Loop to go through every letter
    if (s[i] == c){
      s[i] = '*';
    }
  }

  return s;
}
