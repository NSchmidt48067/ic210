/*********************************************
Filename: part3.cpp
Author: MIDN Nathaniel Schmidt (265646)
Ships
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

    srand(time(0));//Randomizer for the ships direction

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

//Creates the Ships
entity* ships = new entity[5*(spawn.count - 1) + 1];//+1 is so that I can use "% 5" later on
int sspawn = 1;//Keeps track of how many times it spawns a ship at one spot
for (int i = 1; i <= 5*(spawn.count - 1); i++){
    ships[i].loc.row = spawn.row[sspawn];
    ships[i].loc.col = spawn.col[sspawn];
    if ((i) % 5 == 0){
        sspawn++;
    }
}
//sspawn--;//So that it can be used later to print out the ships

    // Initialize ncurses
  startCurses();
int h, w;//Gets terminal parameters
getWindowDimensions(w, h);
if (bx > h || by > w){//Ends the code if the board does not fit
    endCurses();
    cout << "Board parameters too large" << endl;
    return 0;
}

//Prints out the board, the player at spawn, and the ships
printbeg(player, ships, spawn, bx, by, sspawn);

int points = 500;//Initializes the points
 
int c = 'r';//Input char to determine direction
bool cheat = false;

do {//Loop that will run the game
    c = inputChar();
    if (c == 'i'){//If the user presses i, they cannot die
        cheat == true;
    }
    player = pmove(player, spawn, c);//moves the player

    ships = smove(ships, spawn, sspawn);//moves the ships

    //Did the player die
    if (!cheat){
        if(death(ships, player, sspawn)){
            usleep(2000000);//Pauses for 2 seconds
            endCurses();
            ploss(spawn);//Prints out the loss info
            return 0;
        }
    }

    points--;//Keeps track of the score

    drawChar('X', goal.col, goal.row);//Ensures that the goal will always print

    refreshWindow();
    usleep(150000); // pause (sleep) for .15 seconds
} while(c != 'y' && (dist(player.loc, goal) >= 1)); 


//loop exits when the player reaches the goal
  endCurses();

pwin(spawn, points);//Prints out the points and spawnpoints
 
  return 0;
}