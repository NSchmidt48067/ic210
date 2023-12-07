/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Classes
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Node {
int data;
Node* next;
};

Node* add2front(int val, Node* oldlist);
//Function that adds new parts to the front of the list
  
int main()
{
  //Declare Variables
  int num;
  Node* L = new Node;
  
  //Take in numbers
  cin >> num;
  while (num >= 0){
    //Loop that will continue to take in numbers until a negative number is written
    L = add2front(num, L);
    cin >> num;
  }

  cout << L->next->next->data << endl;//Print out 3rd to last number

  
  return 0;
}

//Function that adds new numbers to the front of the list
Node* add2front(int val, Node* oldlist)
{
  Node* temp = new Node;
  temp->data = val;
  temp->next = oldlist;
  return temp;				// return the new list!
}