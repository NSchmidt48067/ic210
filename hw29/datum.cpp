/*********************************************
Filename: datum.cpp
Author: MIDN Nathaniel Schmidt (265646)
Datum Definitions
 *********************************************/
#include "datum.h"
#include <iostream>
using namespace std;


istream& operator >> (istream& is, datum& D)
{
  char c;
  return is >> c >> D.time >> c >> D.position >> c; 
}