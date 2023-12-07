/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Working in C
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaring functions
int readN();
int* readData(int n);
void show(int* A, int n);
void swap(int* A, int n);

int main() {
      //Declare Variables
  int n = readN();
  int* A = readData(n);

  char cmd[10];
  printf("cmd: ");
  while( (scanf(" %s", cmd)) && cmd[3] != 't' ) 
  {
    if( cmd[3] == 'w' )
      show(A, n);
    else if ( cmd[3] == 'p' )
      swap(A, n);

    printf("cmd: ");
  }

    free(A);
    
    return 0;
}

int readN(){//readN function determines the size of the array
  char g;
  int n;
  scanf(" %c %c %d", &g, &g, &n);
  return n;
}

int* readData(int n){//readData reads in the information for the array and returns the array
  int* A = malloc(n*sizeof(int));
  for (int i = 0;i < n; i++){
    scanf(" %d", &A[i]);
  }
  return A;
}

void show(int* A, int n){//show prints out the stars correlating to the number in the array
  
  for (int i = 0;i < n;i++){
    printf("[%d] ", i);
    for (int s = 0;s < A[i];s++){
      printf("*");
    }
    printf("\n");
  }
}

void swap(int* A, int n){//swap swaps the values in the array
  int x, y, z;

  scanf(" %d %d", &x, &y);
  z = A[x];
  A[x] = A[y];
  A[y] = z;
  
}
