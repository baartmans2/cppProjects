#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;

//StudentList
//Raymond Baartmans
//10/17/2019

struct Student//create student struct
{
  char name[20];
  int id;
  float gpa;
};

//methods
Student* add();
void Delete(vector<Student*>* thelist);
void print(vector<Student*> thelist);
  
int main()
{
  bool done = false;//used to quit prgrm
  vector<Student*> studentlist;//list of students
  char input[10];//holds user input
  
  while (!done)//while the user chooses not to quit
    {
      cout << "Would you like to ADD, PRINT, DELETE, or QUIT? Use all caps." << endl;
      cin >> input;//get input

      if (strcmp(input, "ADD") == 0)
	{
	  studentlist.push_back(add());//jump to add method and add a student to vector
	}
      else if (strcmp(input, "PRINT") == 0)
	{
	  print(studentlist);//jump to print method and print
	}
      else if (strcmp(input, "DELETE") == 0)
	{
	  Delete(&studentlist);//jump to delete method and delete
	}
      else if (strcmp(input, "QUIT") == 0)//quit prgrm
	{
	  done = true;
	}
      else
	{
	  cout << "Enter a valid input please." << endl;
	}
      
    }
  
  return 0;
}

Student* add()
{

  //add method gets user inputs for gpa id name and sends them to the studentlist
  Student* student = new Student();
  cout << "Enter student name." << endl;
  cin >> student -> name;
  cin.ignore(1000, '\n');
  
  cout << "Enter student ID number." << endl;
  cin >> student -> id;
  cin.ignore(1000, '\n');
  cout << "Enter student GPA." << endl;
  cin >> student -> gpa;
  cin.ignore(1000, '\n');
  return student;
}

void Delete(vector<Student*>* thelist)//deletes student from list
{
  cout << "Enter the student ID number you would like to delete." << endl;
  int num;
  cin >> num;//store num

  vector<Student*>::iterator i;//go through each student in the list and check if the ID matches. deletes the first one
  for (i = thelist -> begin(); i != thelist -> end(); i++)
    {
      if ( (*i) -> id == num)
	{
	  delete (*i);//delete it
	  thelist -> erase(i);
	  cout << "Student deleted." << endl;
	  return;
	}
    }
  cout << "No student found." << endl;//displays if no ids match
  
}

void print(vector<Student*> thelist)//goes through list and prints each students name id and gpa
{
  vector<Student*>::iterator i;
  for (i = thelist.begin(); i != thelist.end(); i++)
    {
      std::cout << std::fixed;
      std::cout << setprecision(2);
      cout << "Name: " << (*i) -> name << ", ID: " << (*i) -> id << ", GPA: " << (*i) -> gpa << endl;
    }//Print em all out
}
