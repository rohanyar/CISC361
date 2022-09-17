#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//check struct line 16
typedef struct student {
  char* lastname;
  char* firstname;
  long id;
  char* year;
  int graduation;
  struct student* next;
  struct student* prev;
} Student;


void addStudent(char* lastname, char* firstname, long studentid, char* yearofstudent, int gradyear);
void deleteStudent(char* lastname);
void printBE();
void printEB();
void exits();


//The last name of the student stored in a char*
//The first name of the student stored in a char*
//The student's id number stored as a long
//The year of the student (i.e. freshman, sophomore) stored in a char*
//The year of expected graduation stored as an int
//A "next" pointer to another one of these structs (so you can make a linked list)
//A "prev" pointer to another one of these structs (so you can make it a doubly linked list)
