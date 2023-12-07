/*********************************************
Filename: glib4.h
Author: MIDN Nathaniel Schmidt (265646)
Header for part 4
*********************************************/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "easycurses.h"
#include "Pos.h"
#include "p5main.h"
using namespace std;

struct spawnpoint{//Enters everything involved with creating the board
int* row = new int[100];
int* col = new int[100];//Records where spawn spots are
int count;//Remembers how many spawn spots there are
char** board;//Holds the board's information
Pos goal;//Remembers where the goal is
};

//Houses the information for any moving piece
struct entity{
Pos loc;
Pos prev;
int dir;
entity* next;
};

//Inputs the board into an array
spawnpoint crboard(int bx, int by, ifstream& fin, spawnpoint spawn);

void pwin(spawnpoint spawn, int points);

//Finds the direction as a number
entity direction(entity player, int dir);

//Moves the player
entity pmove(entity player, spawnpoint spawn, int c);

//Bounces things off the wall
entity bounce(entity player, spawnpoint spawn);

//Moves the ships
entity* smove(entity* ship, spawnpoint spawn, round data, int sspawn);

//The if statements for how it will tuurn
int sturn(int turn, entity ship);

//Prints out the ships and player at the beginning
void printbeg(entity player, entity* ships, entity* hunters, spawnpoint spawn, round data, int bx, int by, int sspawn);

//Determines if there was a collision with a ship
bool death(entity* ship, entity* hunter, entity player, spawnpoint spawn, round data, int sspawn);

//Prints out the loss info
void ploss(spawnpoint spawn);

//Moves the hunters
entity* hmove(entity* hunter, entity player, spawnpoint spawn, round data, int hspawn);

//Determines what direction the hunter will go
int tracking(entity hunter, entity player);

//Prints out the characters after the previous positions have been erased
void printmove(entity player,entity* hunters,entity* ships, spawnpoint spawn, round data, int sspawn);