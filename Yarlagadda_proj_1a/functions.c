#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
#define MAX 128

Student *head = NULL;
Student *tail = NULL;

int main()
{
    char str[MAX];
    int len;
    printf("1: Add Student\n 2: Delete Student\n 3: Print Beginning to End\n 4: Print End to Beginning\n 5: Exit\n");
    int decision;
    if (decision == 1)
    {
        Student *student = (Student *)malloc(sizeof(Student)); 
        printf("Student last name: ");
        if (fgets(str, MAX, stdin) != NULL)
        {
            len = (int)strlen(str);
            str[len - 1] = '\0';
            student->lastname = (char *)malloc(len);
            strcopy(student->lastname, str);
        }
        printf("Student first name: ");
        if (fgets(str, MAX, stdin) != NULL)
        {
            len = (int)strlen(str);
            str[len - 1] = '\0';
            student->firstname = (char *)malloc(len);
            strcopy(student->firstname, str);
        }
        printf("Student id: ");
        if (fgets(str, MAX, stdin) != NULL)
        {
            len = (int)strlen(str);
            str[len - 1] = '\0';
            student->id = (char *)malloc(len);
            strcopy(student->id, str);
        }
        printf("Student year: ");
        if (fgets(str, MAX, stdin) != NULL)
        {
            len = (int)strlen(str);
            str[len - 1] = '\0';
            student->year = (char *)malloc(len);
            strcopy(student->year, str);
        }
        printf("Student graduation: ");
        if (fgets(str, MAX, stdin) != NULL)
        {
            len = (int)strlen(str);
            str[len - 1] = '\0';
            student->graduation = (char *)malloc(len);
            strcopy(student->graduation, str);
        }
        addStudent(student->lastname, student->firstname, student->id, student->year, student->graduation);
        free(student->lastname);
        free(student->firstname);
        free(student->id);
        free(student->year);
        free(student->graduation);
        free(student);
    }
    else if (decision == 2)
    {
        Student *student = (Student *)malloc(sizeof(Student)); 
        printf("Enter last name of student to delete: \n");
        if (fgets(str, MAX, stdin) != NULL)
        {
            len = (int)strlen(str);
            str[len - 1] = '\0';
            student->lastname = (char *)malloc(len);
            strcopy(student->lastname, str);
        }
        deleteStudent(student->lastname);
        free(student->lastname);
        free(student);
    }
    else if (decision == 3)
    {
        printf("Printing list from beginning to end\n");
        printBE();
    }
    else if (decision == 4)
    {
        printf("Printing list from end to beginning\n");
        printEB();
    }
    else if (decision == 5)
    {
        printf("Freeing all dynamically allocated memory\n");
        exit();
    }
}

void addStudent(char* lastname, char* firstname, long id, char* year, int graduation)
{
    Student *student = (Student *)malloc(sizeof(Student));
}

void deleteStudent(char* lastname)
{
    ;
}

void printBE()
{
    Student *curr = head;
    while (curr != NULL)
    {
        printf("Last name:%s / First name:%s / Id:%ld / Year:%s / Graduation:%i \n",
               curr->lastname, curr->firstname, curr->id, curr->year, curr->graduation);
        curr = curr->next;
    }
}

void printEB()
{
    Student *curr = tail;
    while (curr != NULL)
    {
        printf("Last name:%s / First name:%s / Id:%ld / Year:%s / Graduation:%i \n",
               curr->lastname, curr->firstname, curr->id, curr->year, curr->graduation);
        curr = curr->prev;
    }
}

void exit()
{
    Student *curr;
    while (head != NULL)
    {
        curr = head;
        head = head->next;
        free(curr);
    }
}

/*
  char* lastname;
  char* firstname;
  long id;
  char* year;
  int graduation;
*/
