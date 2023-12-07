/*********************************************
Filename: read.cpp
Author: MIDN Nathaniel Schmidt (265646)

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

spawnpoint crboard(int bx, int by, ifstream& fin, spawnpoint spawn){
    
    spawn.count = 1;//A variable to take out of the function and use later
    int count = 1;
    char ch;

    for (int i = 0; i < by; i++){//Crates the board in the array
        for (int n = 0; n <= bx; n++){
            ch = fin.get();
            spawn.board[i][n] = ch;

            if (ch == 'Y'){//Records the player spawnpoint as the first value in the array
                spawn.board[i][n] = ' ';
                spawn.col[0] = i;
                spawn.row[0] = n;
            }
            else if (ch == 'Z') {//Records the spawn spots starting in the array at 1 and up
                spawn.board[i][n] = ' ';
                spawn.col[count] = i;
                spawn.row[count] = n;
                count++;
                spawn.count = count;
            }
            else if (ch == 'X'){//Records where the goal is
                spawn.goal.row = n;
                spawn.goal.col = i;
            }
        }
    }
    return spawn;
}

void pwin(spawnpoint spawn, int points){
    //Prints out the player spawn point and the spawn spots
  cout << "Player start: (" << spawn.col[0] << "," << spawn.row[0] - 1 << ")" << endl;
  cout << "Spawn spots: ";
  for (int i = 1; i < spawn.count; i++){
    cout << "(" << spawn.col[i] << "," << spawn.row[i] - 1 << ") ";
  }
  cout << endl;
  cout << "You won, high score = " << points << endl;
}

//Prints out the loss info
void ploss(spawnpoint spawn){
  //Prints out the player spawn point and the spawn spots
  cout << "Player start: (" << spawn.col[0] << "," << spawn.row[0] - 1 << ")" << endl;
  cout << "Spawn spots: ";
  for (int i = 1; i < spawn.count; i++){
    cout << "(" << spawn.col[i] << "," << spawn.row[i] - 1 << ") ";
  }
  cout << endl << "You lost, they got you!" << endl;
}

entity direction(entity player, int dir){//Converts the direction from a letter to a number
    if (dir == 'a'){
        player.dir =  0;
    }
    if (dir == 's'){
        player.dir = 1;
    }
    if (dir == 'd'){
        player.dir = 2;
    }
    if (dir == 'w'){
        player.dir = 3;
    }
    if (dir == 'r'){
        player.dir = 4;
    }
    return player;
}

//Moves the player
entity pmove(entity player, spawnpoint spawn, int c){
    
    player = direction(player, c);//Gets the direction in a usable number
    player.prev = player.loc;//Set the previous location to the current loc
    player.loc = step(player.loc, player.dir);//Move the player
    player = bounce(player, spawn);//Bounces the player
    
    if (player.dir != 4){
        drawChar(' ', player.prev.col, player.prev.row);//Remove the old P
        drawChar('P', player.loc.col, player.loc.row);//Draw the player in the new spot
    }
    //player.dir = 4;
    return player;
}

//Bounces things off the wall
entity bounce(entity thing, spawnpoint spawn){//Thing is anything that moves
    
    if (thing.dir == 0){//Determines Direction
        if (spawn.board[thing.loc.col][thing.loc.row] == '#'){//Determines if its next ot wall
            thing.dir = 2;
            thing.loc = thing.prev;//Resets the current location to the previous one
        }
    }

    else if (thing.dir == 1){//Determines Direction
        if (spawn.board[thing.loc.col][thing.loc.row] == '#'){//Determines if its next ot wall
            thing.dir = 3;
            thing.loc = thing.prev;//Resets the current location to the previous one
        }
    }

    else if (thing.dir == 2){//Determines Direction
        if (spawn.board[thing.loc.col][thing.loc.row] == '#'){//Determines if its next ot wall
            thing.dir = 0;
            thing.loc = thing.prev;//Resets the current location to the previous one
        }
    }

    else if (thing.dir == 3){//Determines Direction
        if (spawn.board[thing.loc.col][thing.loc.row] == '#'){//Determines if its next ot wall
            thing.dir = 1;
            thing.loc = thing.prev;//Resets the current location to the previous one
        }
    }
    return thing;
}

//Moves the ships
entity* smove(entity* ship, spawnpoint spawn, int sspawn){
    int turn;//Will decide what direction the ship will go
    
    for (int i = 1; i <= 5 * (sspawn - 1); i++){
        if (rand() % 10 == 0){//If it will change direction
             turn = (rand() % 2);//What direction will it go
            ship[i].dir = sturn(turn, ship[i]);
        }
        ship[i].prev = ship[i].loc;//Set the previous location to the current loc
        ship[i].loc = step(ship[i].loc, ship[i].dir);//Move the ship
        ship[i] = bounce(ship[i], spawn);//Bounces the ship
        drawChar(' ', ship[i].prev.col, ship[i].prev.row);//Remove the old *
    }
    for (int i = 1; i <= 5 * (sspawn - 1); i++){//Draws the star after the spaces so that they always show up
        drawChar('*', ship[i].loc.col, ship[i].loc.row);//Draw the player in the new spot
    }
    return ship;
}

//Moves the hunters
entity* hmove(entity* hunter, entity player, spawnpoint spawn, int hspawn){
    for (int i = 0; i < spawn.count - 1; i++){
        hunter[i].dir = tracking(hunter[i], player);
        hunter[i].prev = hunter[i].loc;//Set the previous location to the current loc
        hunter[i].loc = step(hunter[i].loc, hunter[i].dir);//Move the ship
        hunter[i] = bounce(hunter[i], spawn);//Bounces the ship
        drawChar(' ', hunter[i].prev.col, hunter[i].prev.row);//Remove the old *
    }
    for (int i = 0; i < spawn.count - 1; i++){//Draws the star after the spaces so that they always show up
        drawChar('K', hunter[i].loc.col, hunter[i].loc.row);//Draw the player in the new spot
    }
    return hunter;
}

//Determines what direction the hunter will go
int tracking(entity hunter, entity player){
    int dc = player.loc.col - hunter.loc.col;
    int dr = player.loc.row - hunter.loc.row;
    int cdir, rdir;
    if (dc < 0){//If statement that will set a direction based upon where the player is
        cdir = 3;
    }
    if (dc >= 0) {
        cdir = 1;
    }
    if (dr < 0){
        rdir = 0;
    }
    if (dr >= 0) {
        rdir = 2;
    }
    if (rand() % 2 == 0){//The hunter will either go laterally or vertically
        return rdir;
    }
    return cdir;
}

//The if statements for how it will tuurn
int sturn(int turn, entity ship){
//If statement determines what direction it will go based on the rand value and what direction it was going
         if (turn == 0 && (ship.dir == 0)){
         ship.dir = 1;
         }
         else if (turn == 0 && (ship.dir == 1)){
            ship.dir = 2;
         }
         else if (turn == 0 && (ship.dir == 2)){
            ship.dir = 3;
         }
         else if (turn == 0 && (ship.dir == 3)){
            ship.dir = 0;
         }
         else if (turn == 1 && (ship.dir == 0)){
            ship.dir = 3;
         }
         else if (turn == 1 && (ship.dir == 1)) {
            ship.dir = 0;
         }
         else if (turn == 1 && (ship.dir == 2)) {
            ship.dir = 1;
         }
         else if (turn == 1 && (ship.dir == 3)) {
            ship.dir = 2;
         }
         return ship.dir;
}

//Prints out the ships and player at the beginning
void printbeg(entity player, entity* ships, spawnpoint spawn, int bx, int by, int sspawn){
    for (int i = 0; i < by; i++){//Prints the board in NCurses
    for (int n = 0; n <= bx; n++){
        drawChar(spawn.board[i][n], i, n);
    }
}
for (int i = 1; i <= 5 * (sspawn - 1); i++){//Prints out the ships at the start
    drawChar('*', ships[i].loc.col, ships[i].loc.row);
}

drawChar('P', player.loc.col, player.loc.row);//Draws the P at the start

refreshWindow();
}

//Determines if there was a collision with a ship
bool death(entity* ship, entity player, int sspawn){
    for (int i = 1; i <= 5 * (sspawn - 1); i++){
        if ((equal(ship[i].loc, player.loc)) || ((equal(ship[i].prev, player.loc)) && equal(ship[i].loc, player.prev))){
            return true;
        }
    }
    return false;
}