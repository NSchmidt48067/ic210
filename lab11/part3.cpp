/*********************************************
Filename: part3.cpp
Author: MIDN Nathaniel Schmidt (265646)
Full Cantor
 *********************************************/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Prints out the string s, count times in a row,
// in a **single** line.
// You must implement this using recursion!
void repeat(string s, int count);
void cantor_row(int length, int levels);

// DO NOT CHANGE the main function! Just write the definition
// of repeat below.
int main() {
  int count;
  cout << "size: ";
  cin >> count;
  cout << "Width-" << count << " Cantor set:" << endl;

  int levels;
  for (int i = 0; i < count; i++){//Determines how many levels it needs to print
    levels = pow(3, i);
    if (levels == count){
      levels = i;
      break;
    }
}


for (int i = 0; i <= levels; i++){//Loop that makes sure every line is printed
    cantor_row(count, i);
    cout << endl;
}

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

void cantor_row(int length, int levels){//A recursive function that prints out the underscores
    if (levels == 0){//Base case
        repeat("X", length);//Prints out the first line
    }
    else {//For every line except the first one
        cantor_row(length/3, levels - 1);
        repeat("_", length/3);
        cantor_row(length/3, levels - 1);
    }
}
