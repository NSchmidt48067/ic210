/*********************************************
Filename: part2.cpp
Author: MIDN Nathaniel Schmidt (265646)
Cantor Set
 *********************************************/
#include <iostream>
#include <string>
using namespace std;

// Prints out the string s, count times in a row,
// in a **single** line.
// You must implement this using recursion!
void repeat(string s, int count);
void cantor_row(int length);

// DO NOT CHANGE the main function! Just write the definition
// of repeat below.
int main() {
  int count;
  cout << "size: ";
  cin >> count;
  cout << "Width-" << count << " Cantor set:" << endl;

  cantor_row(count);//Prints out the single line
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

void cantor_row(int length){//A recursive function that prints out the underscores
    if (length == 1){
        cout << "X";
    }
    else {
        cantor_row(length/3);
        repeat("_", length/3);
        cantor_row(length/3);
    }
}
