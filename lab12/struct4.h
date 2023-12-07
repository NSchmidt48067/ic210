/*********************************************
Filename: struct3.h
Author: MIDN Nathaniel Schmidt (265646)
Final Header File
 *********************************************/
#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Pair{
char f, l;
string word;
int num;
int count;
};

struct Node{
Pair data;
Node* next;
};

//Function that adds new words to the front of the list
Node* add2front(Pair val, Node* oldlist);

//Prints out the list
void print(Node* L);

//Prints out the nodes before the current one
void print_bef(Node* L, int num);

//Prints out a node's data
void print_cur(Node* L, int num);

//Deletes the whole list
void deletelist(Node* L);

//Function that deletes the front of the list
Node* deletefront(Node* L);

//deletes a number from the list
Node* remove(string word, Node* L);

//Finds the length of a list
int length(Node* L);

//Finds the word of the current node to remove the node
string ret_word(Node* L, int num);