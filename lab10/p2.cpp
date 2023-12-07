/*********************************************
Filename: p2.cpp
Author: MIDN Nathaniel Schmidt (265646)
Coming and Going
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "easycurses.h"
#include <unistd.h>
#include <cstdlib>
using namespace std;

//Declare Struct
struct coordinate {
char l;
int x, y;
};
  
int main()
{ char g, q;
int n;
cin >> n;
coordinate* coord = new coordinate[n];//Create struct

for (int i = 0; i < n; i++){//Take inputs into struct
    cin >> coord[i].l >> g >> coord[i].x >> g >> coord[i].y >> g;
}
    
    // Initialize ncurses
  startCurses();

while (q != 113){
  // Draw 4 digit characters to the terminal screen.
  for (int i = 0; i < n; i++){
      drawCharAndRefresh(coord[i].l, coord[i].x, coord[i].y);
      usleep(800000);
}
//Erase the characters that were just written
 for (int i = 0; i < n; i++){
      drawChar(' ', coord[i].x, coord[i].y);
}
//Erases the characters at the same time
     refreshWindow();
      usleep(800000);
  
  // Loop forever until user enters 'q'

  q = inputChar();
}

  // Close ncurses
  endCurses();
 
  return 0;
}