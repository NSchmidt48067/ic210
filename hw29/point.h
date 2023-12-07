/*********************************************
Filename: point.h
Author: MIDN Nathaniel Schmidt (265646)
Point header file
 *********************************************/
#pragma once
#include "hhmmss.h"
#include "datum.h"
#include <iostream>
using namespace std;


//--- POINT ---------------------------------//
struct point
{
  double x, y;
};
istream& operator >> (istream& in, point& p);
ostream& operator << (ostream& os, point p);