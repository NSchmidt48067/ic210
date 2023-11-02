/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
GCD
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  //Declare Variables
  int num;
  string* A;


  cout << "Number of words: ";//Input number of words/array parts to have
  cin >> num;

  A = new string[num];//Create array
    
  cout << "Sentence: ";

  for (int i = 0; i < num;i++){//Puts sentence input into the array
    cin >> A[i];
  }

  for (int i = 0; i < num; i++){//Prints out the sentence in order with a ? at the end
    cout << A[i];
    if (i == num - 1){
      cout << "? ";
    }
    else{
      cout << " ";
    }
  }

  for (int i = num - 1; i != -1; i--){//Prints out the sentence in reverse order with an exclamation point on the end
    cout << A[i];
    if (i == 0){
      cout << "!";
    }
    else{
      cout << " ";
    }
  }

   cout << endl;
  return 0;
}
