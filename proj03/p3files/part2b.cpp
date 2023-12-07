/*********************************************
Filename: part1.cpp
Author: MIDN Nathaniel Schmidt (265646)
Making the Board
*********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "easycurses.h"
#include "Pos.h"
#include "read.h"
#include "move.h"
#include <unistd.h>
#include <cstdlib>
using namespace std;



int main()
{ string name;//Input the board
    cout << "board file: ";
    cin >> name;
    ifstream fin(name);

    if (!fin) {
        cout << "File not found";
    }

    int by, bx, thing;//Declare variables for the board's array
    char g, ch;

    fin >> by >> g >> bx >> thing;//Input board parameters
    
//The code below creates an array that records where the spawnpoints
    int count = 1;
    spawnpoint spawn;;
for (int i = 0; i < 100; i++){
    spawn.row[i] = 0;
    spawn.col[i] = 0;
}

    spawn.board = new char*[by];//Create the array for the board
    for (int i = 0; i < by; i++){
        spawn.board[i] = new char[bx];
    }

      spawn = crboard(bx, by, fin, spawn);

Pos goal;
Pos player;


    // Initialize ncurses
  startCurses();
int h, w;//Gets terminal parameters
getWindowDimensions(w, h);
if (bx > h || by > w){//Ends the code if the board does not fit
    endCurses();
    cout << "Board parameters too large" << endl;
    return 0;
}

for (int i = 0; i < by; i++){//Prints the board in NCurses
    for (int n = 0; n <= bx; n++){
        drawChar(spawn.board[i][n], i, n);
    }
}


drawChar('P', player.row, player.col);//Draws the P

refreshWindow();

int points = 500;

char dir;

while (dist(player, goal) > 1){
    dir = inputChar();
    int direct = direction(dir);
    player = step(player, direct);
    drawChar('P', player.row, player.col);
    refreshWindow();


    usleep(150000); // pause (sleep) for .15 seconds
}
 
char c;//Loop to hole ncurses
do {
  usleep(150000); // pause (sleep) for .15 seconds
  c = inputChar();
} while(c != 'y'); //loop exits with a 'y'
  endCurses();

//Prints out the player spawn point and the spawn spots
  cout << "Player start: (" << spawn.col[0] << "," << spawn.row[0] << ")" << endl;
  cout << "Spawn spots: ";
  for (int i = 1; i < count; i++){
    cout << "(" << spawn.col[i] << "," << spawn.row[i] << ") ";
  }
  cout << endl;
 
  return 0;
}

