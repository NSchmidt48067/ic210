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
#include "read.h"
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

void pfinal(spawnpoint spawn, int points){
    //Prints out the player spawn point and the spawn spots
  cout << "Player start: (" << spawn.col[0] << "," << spawn.row[0] - 1 << ")" << endl;
  cout << "Spawn spots: ";
  for (int i = 1; i < spawn.count; i++){
    cout << "(" << spawn.col[i] << "," << spawn.row[i] - 1 << ") ";
  }
  cout << endl;
  cout << "You won, high score = " << points << endl;
}