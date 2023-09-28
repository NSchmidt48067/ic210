
/*********************************************
Filename: hw06.cpp
Author: MIDN Nathaniel Schmidt (265646)
Cookies!
 *********************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  //Declare Variables
  int cookie, ocookie, eat, pig = 0, days = 0, a = 1;

  //Ask how many cookies
  cout << "How many cookies? ";
  cin >> cookie;
  ocookie = cookie;
  
  //How many cookies are eaten over a period of time
  while (cookie != 0){
    days = days + 1;
    cout << "Cookies eaten on day " << days << ": ";
    cin >> eat;
    
  //An if statement to determine if they tried to eat too many cookies
    if (eat > cookie) {
      cout << "Not enough cookies!" << endl;
      cookie = 0;
      a = 0;
    }
  //The else to the above if that will set a new piggiest day and keep track of how many cookies are left
    else {
      if (pig < eat){
	pig = eat;
      }
      
      cookie = cookie - eat;
    
    }
 
  }
  //Print out the Cookies eaten over a period of time with the day that you ate the most cookies
  if (a != 0){
  cout << "You ate " << ocookie << " cookies over " << days << " days." << endl;
  cout << "On your piggiest day you ate " << pig << " cookies." << endl;
  }
  return 0;
}
