/*********************************************
Filename: point.cpp
Author: MIDN Nathaniel Schmidt (265646)
Point Definitions
 *********************************************/
#include "point.h"
#include <iostream>
using namespace std;

/*********************************************
 ** DEFINITIONS 
 *********************************************/
istream& operator >> (istream& is, point &p)
{
  char c;
  return is >> c >> p.x >> c >> p.y >> c;
}

ostream& operator << (ostream& os, point p)
{
  return os << '(' << p.x << ',' << p.y << ')';
}
