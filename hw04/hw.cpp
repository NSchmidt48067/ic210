#include <iostream>

using namespace std;

int main() {

  //Set Variables
  char l1, l2, l3;
  int c1, c2, c3;

  //Prompt User and Receive input
  cout << "Input a 3-letter word in uppercase letters: ";
  cin >> l1 >> l2 >> l3;

  //Use the letter as a number
  c1= l1+32;
  c2= l2+32;
  c3= l3+32;

  //Convert the new number to a letter and print
   l1= c1;
   l2= c2;
   l3= c3;
  cout << "Output: " << l1 << l2 << l3 << endl;


  int b=3;
  double a=16.4;
  char c=4*16.4+3;
  cout << int(c);
  return 0;


  
}
