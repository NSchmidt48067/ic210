/*********************************************
Filename: p3.cpp
Author: MIDN Nathaniel Schmidt (265646)
Move it move it
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
  
//Declare Functions
void move(coordinate* coord, int n);

int main()
{ time(0);
    char g, q;
int n;
cin >> n;
coordinate* coord = new coordinate[n];//Create struct

for (int i = 0; i < n; i++){//Take inputs into struct
    cin >> coord[i].l >> g >> coord[i].x >> g >> coord[i].y >> g;
}
    
    // Initialize ncurses
  startCurses();

  // Draw 4 digit characters to the terminal screen.
  for (int i = 0; i < n; i++){
      drawChar(coord[i].l, coord[i].x, coord[i].y);
}
      refreshWindow();
      usleep(80000);

move(coord, n);
  
  

  // Close ncurses
  endCurses();
 
  return 0;
}

void move(coordinate* coord, int n){//move function moves the chars one space at a time
    for (int frame = 0; frame < 20; frame++){
        for (int i = 0; i < n; i++){
            drawChar(' ', coord[i].x, coord[i].y);    
            coord[i].y = coord[i].y + 1;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
        }
    refreshWindow();
    usleep(80000);
    }
}