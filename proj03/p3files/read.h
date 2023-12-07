/*********************************************
Filename: read.h
Author: MIDN Nathaniel Schmidt (265646)
Header file to create the board
*********************************************/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct spawnpoint{//Enters everything involved with creating the board
int* row = new int[100];
int* col = new int[100];//Records where spawn spots are
int count;//Remembers how many spawn spots there are
char** board;//Holds the board's information
Pos goal;//Remembers where the goal is
};

//Inputs the board into an array
spawnpoint crboard(int bx, int by, ifstream& fin, spawnpoint spawn);

void pfinal(spawnpoint spawn, int points);