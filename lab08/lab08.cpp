/*********************************************
Filename: lab08.cpp
Author: MIDN Nathaniel Schmidt (265646)
Hangman rules
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
{
  cout << "Testing printSpaced..." << endl;
  cout << "["; 
  printSpaced("wash"); 
  cout << "]" << endl;

  cout << "["; 
  printSpaced("HelloWorld!"); 
  cout << "]" << endl;

  

  cout << endl << "Testing mkShadowString..." << endl;
  string s1 = "food";
  string s2 = mkShadowString(s1);
  cout << "original: " << s1 << endl;
  cout << "  shadow: " << s2 << endl;
  string s3 = "require";
  string s4 = mkShadowString(s3);
  cout << "original: " << s3 << endl;
  cout << "  shadow: " << s4 << endl;

     
  cout << endl << "Testing uncover..." << endl;
  string u1 = "housepet";
  string u2 = "________";
  cout << u1 << endl << u2 << endl;
  
  string u3 = uncover(u1,u2,'e');
  if( u2 == u3 )
    cout << u3 << " there were not e's!"  << endl;
  else
    cout << u3 << " there were e's!"  << endl;
  u2 = u3;
 
  u3 = uncover(u1,u2,'q');
  if( u2 == u3 )
    cout << u3 << " there were not q's!"  << endl;
  else
    cout << u3 << " there were q's!"  << endl;

  cout << endl << "Testing crossOut..." << endl;
  string t1 = "Go get good food!";
  cout << t1 << endl;
  t1 = crossOut('o',t1);
  cout << t1 << endl;
  t1 = crossOut('g',t1);
  cout << t1 << endl;
   
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
