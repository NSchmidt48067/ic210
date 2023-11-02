/*********************************************
Filename: lab.cpp
Author: MIDN Nathaniel Schmidt (265646)
Movies and Ratings
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;



int main()
{//Establish Variables
string garbage;
int user = 0, mov;
double rat;

 double** A = new double* [610];
 for (int i = 0; i < 610; i++){
    A[i] = new double[9724];
 }
 
 for (int i = 0; i < 610; i ++){//Set all values equal to 0 in the array
    for (int n = 0; n < 9724; n++){
        A[i][n] = 0;
    }
 }

ifstream fin("ratings.tsv");//Establish input variables for the files

fin >> garbage >> garbage >> garbage;

while (fin >> user){//Loop that goes through all the users
    fin >> mov >> rat;
    A[user][mov] = rat;
}

/*for (int i = 0; i < 100; i++){
    cout << A[1][i] << endl;
}*/

//Declare variables
int count, num;
double avg;
string com;

while (cin >> com){//Loop that runs while there is a command
    count = 0;
    avg = 0;
    if (com == "quit"){//Leaves the loop
        break;
    }
    else if (com == "movie"){//Finds the average rating of a movie
        cin >> num;
        for (int i = 0; i < 610; i++){//Loop that finds the average rating
            if (A[i][num] != 0){
                count++;
            }
            avg = avg + A[i][num];
        }
        avg = avg / count;
        cout << avg << endl;
    }
    else if (com == "user"){//Finds the average rating of a user
               cin >> num;
        for (int i = 0; i < 9724; i++){//Loop that finds the average rating
            if (A[num][i] != 0){
                count++;
            }
            avg = avg + A[num][i];
        }
        avg = avg / count;
        cout << avg << endl;
    }
}

for (int i = 0; i < 610; i++){
    delete [] A[i];
}

delete [] A;

  return 0;
}