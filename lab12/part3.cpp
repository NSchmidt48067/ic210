/*********************************************
Filename: part3.cpp
Author: MIDN Nathaniel Schmidt (265646)
Pretty
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "struct3.h"
using namespace std;

int main() {
//Reads in the File
string file;
cout << "Input file is: ";
cin >> file;
cout << endl;
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

for (int i = 0; i < count; i++){
    cout << "The current node: ";
    print_cur(L, i);//Prints out current node
    
    cout << "Nodes before the current: ";//Prints out the nodes before the current one
    print_bef(L, i);

    //Prints out the number of nodes after this one
    cout << "#nodes after the current: " << count - i - 1 << endl;

    //Askes is they accept or reject the node, does nothing right now
    cout << "[a]ccept or [r]eject: ";
    string cmd;
    cin >> cmd;
    cout << endl;

    if (cmd == "a"){//If statement for part4

    }
    else {

    }
  }

  cout << "List is: ";
  print(L);

  int score = 0;//Calculates Score
  Node* temp = L;
  for (int i = 0; i < count; i++){
    score = score + temp->data.num;
    temp = temp->next;
  }
  cout << "Score is: " << score << endl;

  deletelist(L);//Deletes list
  return 0;
}
