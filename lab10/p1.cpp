/*********************************************
Filename: p1.cpp
Author: MIDN Nathaniel Schmidt (265646)
NCurses Basics
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "easycurses.h"
#include <unistd.h>
#include <cstdlib>
using namespace std;


  
int main()
{ // Initialize ncurses
  startCurses();

  // Draw 4 digit characters to the terminal screen.
  drawCharAndRefresh('A', 0, 0);
  usleep(800000);
  
  drawCharAndRefresh('B', 20, 30);
  usleep(800000);

  drawCharAndRefresh('C', 20, 31);
  usleep(800000);

  drawCharAndRefresh('D', 15, 50);
  
  // Loop forever until user enters 'q'
  char c;
  do { 
    c = inputChar();
  } while ( c!= 'q' );

  // Close ncurses
  endCurses();
 
  return 0;
}