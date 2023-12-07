/*********************************************
Filename: p4.cpp
Author: MIDN Nathaniel Schmidt (265646)
Moving Randomly
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "easycurses.h"
#include <unistd.h>
#include <cstdlib>
using namespace std;

//Declare Struct
struct coordinate {
char l;
int x, y, dir;
//dir is the direction of movement; 1 = N, 2 = E, 3 = S, 4 = W
};
  
//Declare Functions
void move(coordinate* coord, int n);

int main()
{ char g, q = 0;

srand(time(0));

int n;
cin >> n;
coordinate* coord = new coordinate[n];//Create struct

for (int i = 0; i < n; i++){//Take inputs into struct
    cin >> coord[i].l >> g >> coord[i].x >> g >> coord[i].y >> g;
    coord[i].dir = 2;
}

    // Initialize ncurses
  startCurses();

  // Draw 4 digit characters to the terminal screen.
  for (int i = 0; i < n; i++){
      drawChar(coord[i].l, coord[i].x, coord[i].y);
}
      refreshWindow();
      usleep(80000);

int turn;
for (int frame = 0; frame < 20; frame++){//Changes direction 20 times
    
    for (int i = 0; i < n; i++){//Loop that determines if they actually change direction
        if (rand() % 5 == 0){//If it will change direction
         turn = (rand() % 2);//What direction will it go
         if (turn == 0 && (coord[i].dir == 1 || coord[i].dir == 3)){//If statement determines what direction it will go based on the rand value and what direction it was going
            coord[i].dir = 2;
         }
         else if (turn == 0 && (coord[i].dir == 2 || coord[i].dir == 4)){
            coord[i].dir = 3;
         }
         else if (turn == 1 && (coord[i].dir == 1 || coord[i].dir == 3)){
            coord[i].dir = 4;
         }
         else if (turn == 1 && (coord[i].dir == 2 || coord[i].dir == 4)) {
            coord[i].dir = 1;
         }
        }
    }
move(coord, n);
}


  // Close ncurses
  endCurses();
 
  return 0;
}

void move(coordinate* coord, int n){//move function moves the chars one space at a time
        for (int i = 0; i < n; i++){
            if (coord[i].dir == 1){
            drawChar(' ', coord[i].x, coord[i].y);    
            coord[i].x = coord[i].x - 1;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
            }
            else if (coord[i].dir == 2){
            drawChar(' ', coord[i].x, coord[i].y);    
            coord[i].y = coord[i].y + 1;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
            }
            else if (coord[i].dir == 3){
            drawChar(' ', coord[i].x, coord[i].y);    
            coord[i].x = coord[i].x + 1;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
            }
            else if (coord[i].dir == 4){
            drawChar(' ', coord[i].x, coord[i].y);    
            coord[i].y = coord[i].y - 1;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
            }

        }
    refreshWindow();
    usleep(80000);
    }
