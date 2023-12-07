/*********************************************
Filename: p5main.cpp
Author: MIDN Nathaniel Schmidt (265646)
The game function call
*********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "easycurses.h"
#include "Pos.h"
#include "glib4.h"
#include "p5main.h"
#include <unistd.h>
#include <cstdlib>
using namespace std;

points_lives the_game(round data, points_lives stats)
{   cout << "board file: " << data.file << " (" << data.ship_num;
    cout << "," << data.h_num << "," << data.points << ")" << endl;
    //Creates the fin function
    ifstream fin(data.file);

    if (!fin) {//If the file is not found
        cout << "File not found";
        stats.lives = -1;
        return stats;
    }

    srand(time(0));//Randomizer for the ships direction

    int by, bx, garb;//Declare variables for the board's array
    char g;//Garbage char

    fin >> by >> g >> bx >> garb;//Input board parameters
    
    //The code below creates an array that records the spawnpoint and spots
    spawnpoint spawn;;
    for (int i = 0; i < 100; i++){
        spawn.row[i] = 0;
        spawn.col[i] = 0;
    }

    //Create the array for the board
    spawn.board = new char*[by];
    for (int i = 0; i < by; i++){
        spawn.board[i] = new char[bx];
    }

    //Stores the board, spawnpoint, spots, and goal in spawn
    spawn = crboard(bx, by, fin, spawn);

Pos goal;//Creates a position value for the goal
goal.row = spawn.goal.row;
goal.col = spawn.goal.col;
entity player;//Creates the struct for the player
player.loc.row = spawn.row[0];
player.loc.col = spawn.col[0];

//Creates the Ships
//+1 is so that I can use "% 5" later on
entity* ships = new entity[data.ship_num*(spawn.count - 1) + 1];
//The math above multiplies the given number of ships per spot
//By the number of spawn spots - 1 because there is one too many

int sspawn = 1;//Keeps track of how many times it spawns a ship at one spot
for (int i = 1; i <= data.ship_num*(spawn.count - 1); i++){
    ships[i].loc.row = spawn.row[sspawn];
    ships[i].loc.col = spawn.col[sspawn];
    ships[i].dir = rand() % 4;
    if ((i) % data.ship_num == 0){
        sspawn++;
    }
}


int hspawn = 1;//hspawn will spawn a hunter at each spot
entity* hunters = new entity[data.h_num*(spawn.count - 1)];
for (int i = 0; i < data.h_num*(spawn.count - 1); i++){
    hunters[i].loc.row = spawn.row[hspawn];
    hunters[i].loc.col = spawn.col[hspawn];
    hunters[i].dir = rand() % 4;
    if ((i) % data.h_num == 0){
        hspawn++;
    }
}

// Initialize ncurses
startCurses();
int h, w;//Gets terminal parameters
getWindowDimensions(w, h);
if (bx > h || by > w){//Ends the code if the board does not fit
    endCurses();
    cout << "Board parameters too large" << endl;
    stats.lives = -1;
    return stats;
}

//Prints out the board, the player at spawn, and the ships
printbeg(player, ships, hunters, spawn, data, bx, by, sspawn);

int points = 500;//Initializes the points
 
int c = 'r';//Input char to determine direction
bool cheat = false;

do {//Loop that will run the game
    c = inputChar();
    if (c == 'i'){//If the user presses i, they cannot die
        cheat == true;
    }
    player = pmove(player, spawn, c);//moves the player

    ships = smove(ships, spawn, data, sspawn);//moves the ships

    hunters = hmove(hunters, player, spawn, data, hspawn);//moves the hunters

    printmove(player, hunters, ships, spawn, data, sspawn);//prints moves

    points--;//Keeps track of the score

    drawChar('X', goal.col, goal.row);//Ensures that the goal will always print

    refreshWindow();
    usleep(150000); // pause (sleep) for .15 seconds

    //Did the player die
    if(death(ships, hunters, player, spawn, data, sspawn)){
        endCurses();
        stats.lives--;//Lose a life
        ploss(spawn);//Prints out the loss info
        usleep(2000000);//Pauses for 2 seconds
        stats.next_map = false;//Won't progress to next map
        return stats;
    }
} while(c != 'y' && (dist(player.loc, goal) >= 1)); 


//loop exits when the player reaches the goal
  endCurses();

  stats.points = stats.points + data.points + points;//Adds the rounds points to the total
  pwin(spawn, points);//Prints out the points and spawnpoints

  delete [] ships;//Deletes the arrays
  delete [] hunters;
 
  stats.next_map = true;
  //The player beat the map so it will move on to the next

  return stats;
}

Node* add2back(round data, Node* L){//Adds new info to the back of the list
   if (L == NULL)
    return new Node{data, NULL};

  L->next = add2back(data, L->next);
  return L;
}

void deletelist(Node* L){//Deletes the whole list
  while (L != NULL)
    L = deletefront(L);
}

Node* deletefront(Node* L){//Function that deletes the front of the list
  if (L == NULL)
    return NULL;

  Node* ret = L->next;   // store the 2nd node to return
  delete L;              // delete the front node
  return ret;
}