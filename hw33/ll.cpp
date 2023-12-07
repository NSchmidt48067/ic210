/*********************************************
Filename: ll.cpp
Author: MIDN Nathaniel Schmidt (265646)
Holds the function definitions
 *********************************************/
#include <iostream>
#include "ll.h"
using namespace std;

Node* add2back(int num, Node* L){//Adds a new number to the back of the list
   if (L == NULL)
    return new Node{num, NULL};

  L->next = add2back(num, L->next);
  return L;
}

void print(Node* L){//Prints out the list
  if (L != NULL)
  {
    cout << L->data << ' ';
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

//enters a number after the specified number
void enter_after(int num, int old, Node* L)
{
  for(Node* p = L; p != NULL; p = p->next){
   if( p->data == old){
      Node* temp = new Node;
      temp->data = num;
      temp->next = p->next;
      p->next = temp;
    }
  }
}

//deletes a number from the list
Node* remove(int num, Node* L)
{
  if (L == NULL){//If there is no number, delete nothing
    return NULL;
  }
  else
  {
    if (L->data == num){//Removes the next node
      Node* temp = L->next;
      delete L;
      return temp;
    }
    else {//Recursive case to find the number that its looking for
      L->next = remove(num, L->next);
      return L;
    }
  } 
}