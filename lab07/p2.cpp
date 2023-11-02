/*********************************************
Filename: p2.cpp
Author: MIDN Nathaniel Schmidt (265646)
Swapping
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int* read(int N);
bool isInOrder(int* A, int N);
void print(int* A, int N);
int swap(int* A, int N);

int main() {
  //Declare Variables
  char c;
  int N, turn = 1, points = 0, moves = 0;
  string com;

  cout << "Welcome to SWARE!" << endl << "board> ";
  
  cin >> c >> c >> N;

  int* A = read(N);
  do{//Do loop that keeps playing the game until a win is achieved
    turn = 1;

    while (turn != 0){//While loop that prompts the user if the command is not acceptable
      cout << endl;
      print(A,N);
      cout << "> ";
      cin >> com;
      
      if (com == "swap"){//Runs the swap function
	points = points + swap(A, N);//Keeps track of points
	moves++;//Keeps track of moves
	turn = 0;
      }
      
      else if (com == "reverse"){//For the next part of the assignment

	moves++;
	turn = 0;
      }
    
      else{//If the command is not valid
	cout << "Unknown move \'" << com << "\'" << endl;
	turn = 0;
      }
    }

  }while(!isInOrder(A, N));//If isInOrder() finds the numbers to be in order, it returns true and the not is put in the loop thus exiting the loop

  cout << endl;
  print(A, N);
  cout << points << " points! (" << moves << " moves)" << endl;

  delete [] A;
  
  return 0;
}

int* read(int N){//read reads in the information for the array and returns the array
  char g;
  cin >> g;

  int* A = new int[N];
  for (int i = 0;i < N; i++){
    cin >> A[i];
  }
  return A;
}

void print(int* A, int N){//print prints out the numbers, dashes, and letters correlating to the number in the array
  char l = 64;

  for (int i = 0; i < N;i++){
    cout << " "  << A[i];
  }
  cout << endl;
  for (int i = 0; i < (N * 2 + 1);i++){
    cout << "-";
  }
  cout << endl;
  for (int i = 0; i < N;i++){
    l = l + 1;
    cout << " "  << l;
  }
  cout << endl;
}

bool isInOrder(int* A, int N){// Determines if the array is in order
  int x = 0;

  for(int i = 0;i < N;i++){

    if (x > A[i]){
      return false;
    }
    x = A[i];
  }
  return true;
}

int swap(int* A, int N){// Moves values in the array around according to user input
  char a, b;
  int x, y, z;
  cin >> a >> b;
  x = a - 65;
  y = b - 65;

  z = A[x];
  A[x] = A[y];
  A[y] = z;

  return 3;
}
