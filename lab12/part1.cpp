/*********************************************
Filename: part1.cpp
Author: MIDN Nathaniel Schmidt (265646)
Linked Lists
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "struct.h"
using namespace std;

int main() {
//Reads in the File
string file;
cout << "Input file is: ";
cin >> file;
ifstream fin(file);
if (!fin){
  cout << "Error! File '" << file << "' not found!";
return 0;
}

int count = 0;
Node* L = NULL;
Pair val;
while (fin >> val.f){
    fin >> val.word >> val.num >> val.l;
    L = add2front(val, L);
    count++;
}

cout << "Count is " << count << endl;

print(L);

deletelist(L);

  return 0;
}
