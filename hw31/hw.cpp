/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Start of Words
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
string data;
Node* next;
};

void search(char l, Node* L);
//Function that looks for the input char
Node* add2front(string val, Node* oldlist);
//Function that adds new parts to the front of the list
Node* deletefront(Node* L);
//Deletes the first node
void deletelist(Node* L);
//Deletes the whole list
  
int main()
{
  //Declare Variables
  string num;
  char l;
  Node* L = new Node;
  
  //Take in strings
  cout << "Enter words followed by END: ";
  cin >> num;
  while (num != "END"){
    //Loop that will continue to take in words until END is entered
    L = add2front(num, L);
    cin >> num;
  }


cout << "What letter? ";
cin >> l;

  search(l, L);
  
deletelist(L);

  return 0;
}

//Function that adds new words to the front of the list
Node* add2front(string val, Node* oldlist)
{
  Node* temp = new Node;
  temp->data = val;
  temp->next = oldlist;
  return temp;				// return the new list!
}

void search(char l, Node* L)
{
    string word;
  for(Node* p = L; p != NULL; p = p->next)
  {
    word = p->data;
    if (l == word[0]){
        cout << word << endl;
    }
  }
}

Node* deletefront(Node* L)
{
  if (L == NULL)
    return NULL;

  Node* ret = L->next;   // store the 2nd node to return
  delete L;              // delete the front node
  return ret;
}

void deletelist(Node* L)
{
  while (L != NULL)
    L = deletefront(L);
}
