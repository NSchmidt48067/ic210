/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Voting
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Declaring functions
void get_names(string* candidate1, string* candidate2);
bool update_counts(string selection, string candidate1, int* count1, string candidate2, int* count2);
void display_results(string candidate1, int count1, string candidate2, int count2);
  
int main() {
  //Declare Variables
  string candidate1;
  string candidate2;

  get_names(&candidate1, &candidate2);

  int count1 = 0;
  int count2 = 0;

  cout << "Enter votes, ending with \"END\":" << endl;

  string selection;
  cin >> selection;
  while (update_counts(selection, candidate1, &count1, candidate2, &count2)) 
  {
    cin >> selection;
  }

  display_results(candidate1, count1, candidate2, count2);

  return 0;
}

void get_names(string* candidate1, string* candidate2){//getnames stores the names of the candidates in a pointer because their adress is called upon in int main
  cout << "Candidate names: ";
  cin >> candidate1[0] >> candidate2[0]; 
}


bool update_counts(string selection, string candidate1, int* count1, string candidate2, int* count2){//update counts determines who was voted for
  if (selection == candidate1){
    count1[0] = count1[0] + 1;
  }
  else if (selection == candidate2){
    count2[0] = count2[0] + 1;
  }
  else if (selection == "END"){
    return false;
  }
  else {
    cout << "Invalid name" << endl;
  }

  return true;
}

void display_results(string candidate1, int count1, string candidate2, int count2){//display results shows who won the vote
  if (count1 == count2){
    cout << "Tie!";
  }
  else if (count1 > count2){
    cout << candidate1 << " wins with " << count1 << " out of " << count1 + count2 << " votes " << endl;
  }
  else{
    cout << candidate2 << " wins with " << count2 << " out of " << count1 + count2 << " votes " << endl;
  }
}
