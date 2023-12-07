/*********************************************
Filename: part3.cpp
Author: MIDN Nathaniel Schmidt (265646)
Pretty
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "struct4.h"
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
    val.count = count;
    L = add2front(val, L);
    count++;
}
Node* temp = L;
string word;
int spec = 0;//Special number to keep track of how to print and remove nodes
for (int i = 0; i < count; i++){
    cout << "The current node: ";
    print_cur(L, spec);//Prints out current node
    
    cout << "Sentence you made so far: ";//Prints out the nodes before the current one
    print_bef(L, spec);

    //Prints out the number of nodes after this one
    cout << "#words left: " << count - i - 1 << endl;

    //Askes is they accept or reject the node, does nothing right now
    cout << "[a]ccept or [r]eject: ";
    string cmd;
    cin >> cmd;
    cout << endl;

    if (cmd == "a"){//If statement that will remove a node or add to spec
    spec++;
    }
    else {
        word = ret_word(L, spec);
        L = remove(word, L);
    }
  }

  cout << "Sentence is: ";
  print(L);

  int score = 0;//Calculates the Score
  temp = L;
  count = length(L);
  for (int i = 0; i < count; i++){
    score = score + temp->data.num;
    temp = temp->next;
  }
  cout << "Score is: " << score << endl;

  deletelist(L);//Delete List
  return 0;
}
