/*********************************************
Filename: part2.cpp
Author: MIDN Nathaniel Schmidt (265646)
Moving a guy
*********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "easycurses.h"
#include "Pos.h"
#include "glib.h"
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

Pos goal;//Creates a position value for the goal
goal.row = spawn.goal.row;
goal.col = spawn.goal.col;
entity player;//Creates the struct for the player
player.loc.row = spawn.row[0];
player.loc.col = spawn.col[0];

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


drawChar('P', player.loc.col, player.loc.row);//Draws the P at the start

refreshWindow();

int points = 500;//Initializes the points
 
int c = 'r';//Input char to determine direction
do {//Loop that will run the game
    c = inputChar();
    player = pmove(player, spawn, c);//calls upon the 
    points--;//Keeps track of the score
} while(c != 'y' && (dist(player.loc, goal) >= 1)); 


//loop exits when the player reaches the goal
  endCurses();

pwin(spawn, points);//Prints out the points and spawnpoints
 
  return 0;
}