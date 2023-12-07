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

int main()
{ string board;//Input the board
    cout << "board file: ";
    cin >> board;
    istream fin(board);

    if (!fin) {
        cout << "File not found";
    }

    int by, bx, thing;
    
    coordinate* place = new coordinate[];



    // Initialize ncurses
  startCurses();


  endCurses();
 
  return 0;
}


