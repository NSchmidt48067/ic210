/*****************************



*****************************/
#include <iostream>
using namespace std;

int calspace(int num);//Function to find spaces

int main()
{
  int n;
  cout << "Integer? ";
  cin >> n;

  cout << "#spaces= " << calspace(n) << endl;
  return 0;
}

int calspace(int num)
{
  int sp = 0;

  if( num < 0 )
  {
    sp++;         // +1 for '-' sign
    num = -num;   // make num positive
  }

  
if (num >= 0 && num < 10){//Base case
    return sp+1;
}
else {//Adds one to sp and calls upon the function again
    return sp+1 + calspace(num / 10);
}

}