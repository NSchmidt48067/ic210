/*********************************************
Filename: move.cpp
Author: MIDN Nathaniel Schmidt (265646)
File for moving the player
*********************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "easycurses.h"
#include "Pos.h"
#include "read.h"
#include "move.h"
#include <unistd.h>
#include <cstdlib>
using namespace std;

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
        refreshWindow();
        usleep(150000); // pause (sleep) for .15 seconds
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