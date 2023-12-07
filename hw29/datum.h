/*********************************************
Filename: datum.h
Author: MIDN Nathaniel Schmidt (265646)
Datum Header
 *********************************************/
#pragma once
#include "point.h"
#include "hhmmss.h"
#include <iostream>
using namespace std;
//--- A DATA READING FROM THE EXPERIMENT ----//
struct datum
{
  point position;
  hhmmss time;
};
istream& operator >> (istream& is, datum& D);