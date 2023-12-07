/*********************************************
Filename: struct2.cpp
Author: MIDN Nathaniel Schmidt (265646)
Accept or reject function file
 *********************************************/
#include <iostream>
#include <string>
#include <cmath>
#include "struct2.h"
using namespace std;

//Function that adds new pairs to the front of the list
Node* add2front(Pair val, Node* L)
{
  Node* temp = new Node;
  temp->data = val;
  temp->next = L;
  return temp;				// return the new list!
}

void print(Node* L){//Prints out a node's data
  if (L != NULL){
    cout << L->data.f << L->data.word << " " << L->data.num << L->data.l << " ";
    print(L->next);
  }
  else {
    cout << endl;
  }
}

void print_cur(Node* L, int num){//Prints out a node's data
  for (int i = 0; i <= num; i++){
    if (i == num){
        cout << L->data.f << L->data.word << " " << L->data.num << L->data.l << " ";
        cout << endl;
    }
    L = L->next;
  }
}

void print_bef(Node* L, int num){//Prints out the nodes before the current one
  for (int i = 0; i <= num; i++){
    if (i < num){
        cout << L->data.f << L->data.word << " " << L->data.num << L->data.l << " ";
        L = L->next;
    }
  }
  cout << endl;
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
