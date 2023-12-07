/*********************************************
Filename: part5.cpp
Author: MIDN Nathaniel Schmidt (265646)
The Game
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



int main(){
    Node* rules = NULL;//Initialize the linked list
    round info;//The data for each round
    ifstream fin("gameScript.txt");

    string garbage;//Garbage variables
    char g;
    points_lives stats;//Initializes a variable to track points and lives
    stats.lives = 3;//Life variable
    stats.next_map = false;
    stats.points = 0;//Keeps track of points

    //Loop to store the data in a linked list
    while(fin >> info.file >> info.ship_num >> info.h_num >> garbage >> g >> info.points){
    rules = add2back(info, rules);
    }

    //Loop that will run through the different maps
    for(Node* p = rules; p != NULL && (stats.lives > 0); p = p->next){
        stats.next_map = false;//If the player dies, repeat the same level
        //If the player beats a level, exit the while loop and go to next map
        while (!stats.next_map && stats.lives > 0){
            stats = the_game(p->data, stats);
            usleep(2000000);//Pause for 2 seconds
        }
        stats.lives = 3;//Resets the lives to 3 after they beat a level
    }
    if (stats.lives > 0)//Only prints out if the player wins
        cout << "Wow you won the entire game, final score was " << stats.points;
        cout << endl;

        deletelist(rules);

  return 0;
}