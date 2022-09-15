#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
#define MAX 128

int main() {
    sList slist = (sList*)malloc(sizeof(sList));
}



void addStudent(sList slist) {
    char str[MAX];
    int len;
    Student *student = (Student*)malloc(sizeof(Student));
    
    printf("Student last name: ");
    if (fgets(str, MAX , stdin) != NULL) {
        len = (int)strlen(str);
        str[len-1] = '\0';
        student->lastname = (char*)malloc(len);
        strcopy(student->lastname, str);
    }
    printf("Student first name: ");
    if (fgets(str, MAX , stdin) != NULL) {
        len = (int)strlen(str);
        str[len-1] = '\0';
        student->firstname = (char*)malloc(len);
        strcopy(student->firstname, str);
    }
    printf("Student id: ");
    if (fgets(str, MAX , stdin) != NULL) {
        len = (int)strlen(str);
        str[len-1] = '\0';
        student->id = (char*)malloc(len);
        strcopy(student->id, str);
    }
    printf("Student year: ");
    if (fgets(str, MAX , stdin) != NULL) {
        len = (int)strlen(str);
        str[len-1] = '\0';
        student->year = (char*)malloc(len);
        strcopy(student->year, str);
    }
    printf("Student graduation: ");
    if (fgets(str, MAX , stdin) != NULL) {
        len = (int)strlen(str);
        str[len-1] = '\0';
        student->graduation = (char*)malloc(len);
        strcopy(student->graduation, str);
    }
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
