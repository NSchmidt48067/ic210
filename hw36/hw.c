/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Start of Words
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
char data[128];
struct Node* next;
};

void search(char l,struct Node* L);
//Function that looks for the input char
struct Node* add2front(char* val, struct Node* oldlist);
//Function that adds new parts to the front of the list
struct Node* deletefront(struct Node* L);
//Deletes the first node
void deletelist(struct Node* L);
//Deletes the whole list
  
int main()
{
  //Declare Variables
  char num[128];
  char l;
  struct Node* L = NULL;
  
  //Take in strings
  printf("Enter words followed by END: ");
  scanf(" %s", num);
  while (num[2] != 'D'){
    //Loop that will continue to take in words until END is entered
    L = add2front(num, L);
    scanf(" %s", num);
  }


printf("What letter? ");
scanf(" %c", &l);

  search(l, L);
  
deletelist(L);

  return 0;
}

//Function that adds new words to the front of the list
struct Node* add2front(char* val, struct Node* oldlist)
{
  struct Node* temp = malloc(sizeof(struct Node));
  strcpy(temp->data, val);
  temp->next = oldlist;
  return temp;				// return the new list!
}

void search(char l, struct Node* L)
{
    char* word;
  for(struct Node* p = L; p != NULL; p = p->next)
  {
    word = p->data;
    if (l == word[0]){
        printf("%s\n", word);
    }
  }
}

struct Node* deletefront(struct Node* L)
{
  if (L == NULL)
    return NULL;

  struct Node* ret = L->next;   // store the 2nd node to return
  free(L);              // delete the front node
  return ret;
}

void deletelist(struct Node* L)
{
  while (L != NULL)
    L = deletefront(L);
}
