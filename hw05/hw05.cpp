#include <iostream>

using namespace std;

int main() {
  //Declare Variables
  int year;
  
  //Get Year
  cout << "Enter year: ";
  cin >> year;
  
  //Determine if year is a Leap Year and Print answer
  if (year%400 == 0){
    cout << "Is Leap Year" << endl;
    
  }
  else if (year%100 == 0){
    if (year%4 == 0){
    cout << "Is Not Leap Year" << endl;
    }
  }
    
  else if (year%4 == 0 ){
      cout << "Is  Leap Year" << endl;
    }
  
  else{
    cout << "Is Not Leap Year" << endl;
  }
  
  return 0;
}
