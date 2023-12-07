/*********************************************
Filename: hhmmss.h
Author: MIDN Nathaniel Schmidt (265646)
hhmmss Header file
 *********************************************/
#pragma once
#include "datum.h"
#include "point.h"
#include <iostream>
using namespace std;

//--- TIME IN HH:MM:SS ----------------------//
struct hhmmss
{
  int h,m,s;
};
istream& operator >> (istream& is, hhmmss& T);
bool operator < (hhmmss a, hhmmss b);