/*********************************************
Filename: part1.cpp
Author: MIDN Nathaniel Schmidt (265646)
Can you repeat that
 *********************************************/
#include <iostream>
#include <string>
using namespace std;

// Prints out the string s, count times in a row,
// in a **single** line.
// You must implement this using recursion!
void repeat(string s, int count);

// DO NOT CHANGE the main function! Just write the definition
// of repeat below.
int main() {
  cout << "10 X's:"<< endl;
  repeat("X", 10);
  cout << endl;

  string DIAMOND = "\u2bc1";
  cout << "8 diamonds:" << endl;
  repeat(DIAMOND, 8);
  cout << endl;

  string TRIANGLE = "\u25b2";
  cout << "13 triangles:" << endl;
  repeat(TRIANGLE, 13);
  cout << endl;
  return 0;
}

void repeat(string s, int count){
    if (count == 1){//Base case
        cout << s;
    }
    else {//If its greater than one, it will print out the symbol, 
    //subtract one from the counter, and recall the function
        count--;
        cout << s;
        repeat(s, count);
    }
    
}