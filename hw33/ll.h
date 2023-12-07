/*********************************************
Filename: ll.h
Author: MIDN Nathaniel Schmidt (265646)
Header File for the library
 *********************************************/
#pragma once

using namespace std;

struct Node{//The struct that will house the data
int data;
Node* next;
};

Node* add2back(int num, Node* L);//Adds a new number to the back of the list

void print(Node* L);//Prints out the list

void enter_after(int num, int old, Node* L);//Enters a number after a specific number is entered

Node* remove(int num, Node* L);//Removes a givern number from the list

void deletelist(Node* L);//Deletes the whole list

Node* deletefront(Node* L);//Function that adds new parts to the front of the list

Node* search(int num, Node* L);//Function that looks for the input char