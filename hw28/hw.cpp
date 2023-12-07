/*********************************************
Filename: hw.cpp
Author: MIDN Nathaniel Schmidt (265646)
Classes
 *********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Designates struct, operators and functions
struct Section{
  string cls, course, day;
};

istream& operator >> (istream& cin, Section& sections);
ostream& operator << (ostream& cout, Section sections);

Section* read(ifstream*, int* n);
void searchByCourse(Section* sections, int n);
void searchBySection(Section* sections, int n);
void searchByDay(Section* sections, int n);
  
int main()
{
  string fname;
  cout << "Filename: ";
  cin >> fname;
  ifstream fin(fname);

  int n;
  Section* sections = read(&fin, &n);

  string cmd;
  cout << "> ";
  while( (cin >> cmd) && (cmd != "quit") )
  {
    if( cmd == "course" )
      searchByCourse(sections, n);
    else if ( cmd == "section" )
      searchBySection(sections, n);
    else if ( cmd == "day" )
      searchByDay(sections, n);

    cout << endl << "> ";
  }


  delete [] sections;
  return 0;
}

//Reads in the struct array
Section* read(ifstream* fin, int* n){
char g;

*fin >> g >> g >> *n;//Finds how many classes there are
Section* A = new Section[*n];

for (int i = 0; i < *n; i++){//Reads in all the data
    *fin >> A[i].course >> A[i].cls >> A[i].day;
}

    return A;
}

void searchByCourse(Section* sections, int n){//Finds all the classes with the course
string course;
cin >> course;

for (int i = 0; i < n; i++){//Prints out the courses that match the user's input
    if (course == sections[i].course){
      cout << sections[i].course << " " << sections[i].cls << " " << sections[i].day << endl;
    }
  }
}

void searchBySection(Section* sections, int n){//Finds all the classes with the section
string section;
cin >> section;

for (int i = 0; i < n; i++){//Prints out the sections that match the user's input

    if (section == sections[i].cls){
      cout << sections[i].course << " " << sections[i].cls << " " << sections[i].day << endl;
    }
  }
}

void searchByDay(Section* sections, int n){//Finds all the classes with the day
char day;
cin >> day;

for (int z = 0; z <= n; z++){//Runs through the number of classes there are

  for (int i = 0; i < sections[z].day.length(); i++){//Runs through each character in the string

      if (day == sections[z].day[i]){//Prints out the course that matches the day
        cout << sections[z].course << " " << sections[z].cls << " " << sections[z].day << endl;
      }
    }
  }
}