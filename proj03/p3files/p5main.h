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
#include "glib4.h"
using namespace std;

//A struct that holds a round's info
struct round{
    string file;
    int ship_num;
    int h_num;
    int points;
};

//Allows for me to store the rules for a round in a linked list
struct Node{
    round data;
    Node* next;
};

//Keeps track of points and lives
struct points_lives{
    int lives;
    bool next_map;
    int points;

};

//A copy of part 4 that will be ran through for part5
points_lives the_game(round data, points_lives stats);

//Adds new info to the back of the list
Node* add2back(round data, Node* L);

//Function that deletes the front of the list
Node* deletefront(Node* L);

//Deletes the whole list
void deletelist(Node* L);