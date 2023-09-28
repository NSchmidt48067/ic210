/*********************************************
Filename: part2.cpp
Author: MIDN Nathaniel Schmidt (265646)
Lab 3 part2-Binary and Decimal Calculator
 *********************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  //Declare Variables
  char a, b, c, d, l, op;
  int n1, n2, n3, n4, sum = 0, sum2 = 0, num = 0, num2 = 0;
 
  //Read whether its a decimal or binary number
  cin >> l;

  if (l == 'B'){
   cin >> a >> b >> c >> d;
   n1 = a - '0';
   n2 = b - '0';
   n3 = c - '0';
   n4 = d - '0';
   sum = n1 * pow (2, 3) + n2 * pow (2, 2) + n3 * pow (2, 1) + n4 * pow (2, 0);
  }
  else {
    cin >> num;
  }

  //Determine if there is something to add and if its a decimal or binary number
  cin >> op;

  if (op == '+'){
    cin >> l;

     if (l == 'B'){
   cin >> a >> b >> c >> d;
   n1 = a - '0';
   n2 = b - '0';
   n3 = c - '0';
   n4 = d - '0';
   sum2 = n1 * pow (2, 3) + n2 * pow (2, 2) + n3 * pow (2, 1) + n4 * pow (2, 0);
     }
     else {
       cin >> num2;
     }
  }

  sum = sum + sum2 +num +num2;

  if (sum < 16){
  n1 =  sum%2;
    sum = sum/2;
  n2 = sum%2;
    sum = sum/2;
  n3 = sum%2;
    sum = sum/2;
  n4 = sum%2;
    sum = sum/2;

    cout << "B" << n4 << n3 << n2 << n1 << endl;
  }
  else {
    cout << "D" << sum << endl;
  }
  return 0;
}
