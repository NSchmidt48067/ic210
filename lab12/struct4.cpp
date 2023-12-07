/*********************************************
Filename: struct2.cpp
Author: MIDN Nathaniel Schmidt (265646)
Pretty function file
 *********************************************/
#include <iostream>
#include <string>
#include <cmath>
#include "struct4.h"
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
    cout << L->data.word << " ";
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
    else{
        L = L->next;
    }
  }
}

void print_bef(Node* L, int num){//Prints out the nodes before the current one
  for (int i = 0; i <= num; i++){
    if (i < num){
        cout << L->data.word << " ";
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

//deletes a number from the list
Node* remove(string word, Node* L)
{
  if (L == NULL){//If there is no number, delete nothing
    return NULL;
  }
  else
  {
    if (L->data.word == word){//Removes the next node
      Node* temp = L->next;
      delete L;
      return temp;
    }
    else {//Recursive case to find the number that its looking for
      L->next = remove(word, L->next);
      return L;
    }
  } 
}

int length(Node* L){//Finds the length of a list
  int count = 0;
  for(Node* curr = L; curr != NULL; curr = curr->next)
     count++;

  return count;
}

string ret_word(Node* L, int num){//Finds the word of the current node to remove the node
  string word;
  for (int i = 0; i <= num; i++){
    if (i == num){
        word = L->data.word;
        return word;
    }
    L = L->next;
  }
  return "";
}