#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"

int main() {
    sList slist = (sList)malloc(sizeof(sList));
}



void addStudent(sList slist) {
    Student *student = (Student*)malloc(sizeof(Student));
    
    printf("Student last name: ");
    scanf("%s", student->lastname);
    printf("Student first name: ");
    scanf("%s", student->firstname);
    printf("Student id: ");
    scanf("%ld", &student->id);
    printf("Student year: ");
    scanf("%s", student->year);
    printf("Student graduation: ");
    scanf("%d", &student->graduation);
    if(slist->head)
}

void deleteStudent() {
    ;
}

void printBE() {
    ;
}

void printEB() {
    ;
}

void exit() {
    ;
}


/*
  char* lastname;
  char* firstname;
  long id;
  char* year;
  int graduation;
*/
