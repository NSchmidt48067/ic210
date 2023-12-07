/*********************************************
Filename: move.h
Author: MIDN Nathaniel Schmidt (265646)
Header file to Move the player
*********************************************/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "easycurses.h"
#include "Pos.h"
#include "read.h"
using namespace std;

//Houses the information for any moving piece
struct entity{
Pos loc;
Pos prev;
int dir;
entity* next;
};

//Finds the direction as a number
entity direction(entity player, int dir);

//Moves the player
entity pmove(entity player, spawnpoint spawn, int c);

//Bounces things off the wall
entity bounce(entity player, spawnpoint spawn);