/*********************************************
Filename: p5.cpp
Author: MIDN Nathaniel Schmidt (265646)
huuuuuuuuuge wall
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
int x, y, dir;//For some reason, the values for x and why seem to be flipped in the computer. (x is y and y is x)
//dir is the direction of movement; 1 = N, 2 = E, 3 = S, 4 = W
};
  
//Declare Functions
void move(coordinate* coord, int n, int h, int w);


int main()
{ char g, q = 0;

srand(time(0));

int n;
cin >> n;
coordinate* coord = new coordinate[n];//Create struct

for (int i = 0; i < n; i++){//Take inputs into struct
    cin >> coord[i].l >> g >> coord[i].x >> g >> coord[i].y >> g;
    coord[i].dir = 1;
}
    


    // Initialize ncurses
  startCurses();

  //Getting window dimensions
int h, w;
getWindowDimensions(h, w);

  // Draw 4 digit characters to the terminal screen.
  for (int i = 0; i < n; i++){
      drawChar(coord[i].l, coord[i].x, coord[i].y);
}
      refreshWindow();
      usleep(80000);

int turn;
while (q != 113){
    
    for (int i = 0; i < n; i++){//Loop that determines if they actually change direction
        if (rand() % 5 == 0){//If it will change direction
         turn = (rand() % 2);//What direction will it go
         if (turn == 0 && (coord[i].dir == 0 || coord[i].dir == 2)){//If statement determines what direction it will go based on the rand value and what direction it was going
            coord[i].dir = 1;
         }
         else if (turn == 0 && (coord[i].dir == 1 || coord[i].dir == 3)){
            coord[i].dir = 2;
         }
         else if (turn == 1 && (coord[i].dir == 0 || coord[i].dir == 2)){
            coord[i].dir = 3;
         }
         else if (turn == 1 && (coord[i].dir == 1 || coord[i].dir == 3)) {
            coord[i].dir = 0;
         }
        }
    }
move(coord, n, h, w);

 q = inputChar(); //Will end if the user inputs a q
}

  // Close ncurses
  endCurses();
 
  return 0;
}

void move(coordinate* coord, int n, int h, int w){//move function moves the chars one space at a time

for (int i = 0; i < n; i++){
if (coord[i].x > 0 && (coord[i].x < h - 1) && coord[i].y > 0 && (coord[i].y < w - 1)){//If statement to determine parameters
    if (coord[i].dir == 0){
            drawChar(' ', coord[i].x, coord[i].y);    
            coord[i].x = coord[i].x - 1;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
            }
    else if (coord[i].dir == 1){
            drawChar(' ', coord[i].x, coord[i].y);    
            coord[i].y = coord[i].y + 1;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
            }
    else if (coord[i].dir == 2){
            drawChar(' ', coord[i].x, coord[i].y);    
            coord[i].x = coord[i].x + 1;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
            }
    else if (coord[i].dir == 3){
            drawChar(' ', coord[i].x, coord[i].y);    
            coord[i].y = coord[i].y - 1;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
            }
}
else {
        coord[i].dir = (coord[i].dir + 2) % 4;
        if (coord[i].x <= 0) {
            drawChar(' ', 0, coord[i].y);    
            coord[i].x = 1;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
        }
        else if (coord[i].x == h - 1){
            drawChar(' ', h - 1, coord[i].y);    
            coord[i].x = h - 2;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
        }
        else if (coord[i].y <= 0) {
            drawChar(' ', coord[i].x, 0);    
            coord[i].y = 1;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
        }
        else if (coord[i].y == w - 1){
            drawChar(' ', coord[i].x, w - 1);    
            coord[i].y = w - 2;        
            drawChar(coord[i].l, coord[i].x, coord[i].y);
        }
    }

}


    refreshWindow();
    usleep(80000);
    }

