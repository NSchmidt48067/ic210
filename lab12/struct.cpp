/*********************************************
Filename: struct.cpp
Author: MIDN Nathaniel Schmidt (265646)
Struct file and Functions
 *********************************************/
#include <iostream>
#include <string>
#include <cmath>
#include "struct.h"
using namespace std;

//Function that adds new pairs to the front of the list
Node* add2front(Pair val, Node* L)
{
  Node* temp = new Node;
  temp->data = val;
  temp->next = L;
  return temp;				// return the new list!
}

void print(Node* L){//Prints out the list
  if (L != NULL)
  {
    cout << L->data.f << L->data.word << " " << L->data.num << L->data.l << " ";
    print(L->next);
  }
  else {
    cout << endl;
  }
}

void deletelist(Node* L){//Deletes the whole list
  while (L != NULL)
    L = deletefront(L);
}

Node* deletefront(Node* L){//Function that deletes the front of the list
  if (L == NULL)
    return NULL;

  Node* ret = L->next;   // store the 2nd node to return
  delete L;              // delete the front node
  return ret;
}