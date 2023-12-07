/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Working in C
 *********************************************/
#include <stdio.h>

int main() {
    char g;//
    double x1, x2, y1, y2, x, y;//Takes in the numbers
    scanf(" (%lf,%lf) ", &x1, &y1);
    scanf(" (%lf,%lf)", &x2, &y2);

    x = (x1 + x2) / 2;
    y = (y1 + y2) / 2;

    printf("(%lf,%lf)\n", x, y);
    
    return 0;
}