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
    char lastname[MAX];
    char firstname[MAX];
    char year[MAX];
    int len;
    printf("\n 1: Add Student\n 2: Delete Student\n 3: Print Beginning to End\n 4: Print End to Beginning\n 5: Exit\n");
    int decision = 0;
    if (fgets(str, MAX, stdin) != NULL)
    {
        decision = atol(str);
    }

    while (decision)
    {
        if (decision == 1)
        {
            Student *student = (Student *)malloc(sizeof(Student));
            printf("Student last name: ");
            if (fgets(lastname, MAX, stdin) != NULL) 
            {
                len = (int)strlen(lastname);
                lastname[len - 1] = '\0';
                student->lastname = (char*)(malloc(len));
                strcpy(student->lastname, lastname);
            }
    
            printf("Student first name: ");
            if (fgets(firstname, MAX, stdin) != NULL)
            {
                len = (int)strlen(firstname);
                firstname[len - 1] = '\0';
                student->firstname = (char*)(malloc(len));
                strcpy(student->firstname, firstname);
            }
            printf("Student id: ");
            if (fgets(str, MAX, stdin) != NULL)
            {
                student->id = (long)atol(str);
            }
            printf("Student year: ");
            if (fgets(year, MAX, stdin) != NULL)
            {
                len = (int)strlen(year);
                year[len - 1] = '\0';
                student->year = (char*)(malloc(len));
                strcpy(student->year, year);
            }
            printf("Student graduation: ");
            if (fgets(str, MAX, stdin) != NULL)
            {
                student->graduation = atoi(str);
            }
            addStudent(student->lastname, student->firstname, student->id, student->year, student->graduation);
            printf(" 1: Add Student\n 2: Delete Student\n 3: Print Beginning to End\n 4: Print End to Beginning\n 5: Exit\n");
            if (fgets(str, MAX, stdin) != NULL)
            {
                decision = atol(str);
            }

            /*
            free(student->lastname);
            free(student->firstname);
            free(student->id);
            free(student->year);
            free(student->graduation);
            free(student);
            */
        }
        else if (decision == 2)
        {
            printf("Enter last name of student to delete:\n");
            Student *student = (Student *)malloc(sizeof(Student));
            if (fgets(lastname, MAX, stdin) != NULL)
            {
                len = (int)strlen(lastname);
                lastname[len - 1] = '\0';
                student->lastname = (char*)(malloc(len));
                strcpy(student->lastname, lastname);
            }
            deleteStudent(student->lastname);
            printf(" 1: Add Student\n 2: Delete Student\n 3: Print Beginning to End\n 4: Print End to Beginning\n 5: Exit\n");
            if (fgets(str, MAX, stdin) != NULL)
            {
                decision = atol(str);
            }
        }
        else if (decision == 3)
        {
            printf("Printing list from beginning to end\n");
            printBE();
            printf(" 1: Add Student\n 2: Delete Student\n 3: Print Beginning to End\n 4: Print End to Beginning\n 5: Exit\n");
            if (fgets(str, MAX, stdin) != NULL)
            {
                decision = atol(str);
            }
        }
        else if (decision == 4)
        {
            printf("Printing list from end to beginning\n");
            printEB();
            printf(" 1: Add Student\n 2: Delete Student\n 3: Print Beginning to End\n 4: Print End to Beginning\n 5: Exit\n");
            if (fgets(str, MAX, stdin) != NULL)
            {
                decision = atol(str);
            }
        }
        else if (decision == 5)
        {
            printf("Freeing all dynamically allocated memory\n");
            exits();
            printf(" 1: Add Student\n 2: Delete Student\n 3: Print Beginning to End\n 4: Print End to Beginning\n 5: Exit\n");
            if (fgets(str, MAX, stdin) != NULL)
            {
                decision = atol(str);
            }
            break;
        }
    }
}

void addStudent(char *lastname, char *firstname, long id, char *year, int graduation)
{
    Student *student = (Student *)malloc(sizeof(Student));
    student->lastname = lastname;
    student->firstname = firstname;
    student->id = id;
    student->year = year;
    student->graduation = graduation;
    student->next = NULL;
    if (head == NULL)
    {
        student->prev = NULL;
        head = student;
    }
    else
    {
        tail->next = student;
        student->prev = tail;
    }
    tail = student;
}

void deleteStudent(char *lastname)
{
    if (head == NULL && tail == NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    Student *curr = head;
    while (curr != NULL)
    {
        
        if (strcmp(curr->lastname, lastname) == 0)
        {
            if (curr == head)
            {
                if(curr != tail){
                    curr->next->prev = NULL;
                }
                head = curr->next;

            }
            else if (curr == tail)
            {
                if(curr != head){
                    curr->prev->next = NULL;
                }
                tail = curr->prev;
            }
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            free(curr->lastname);
            free(curr->firstname);
            free(curr->year);
            free(curr);
            break;
        }
        curr = curr->next;
    }
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

void exits()
{
    Student *curr;
    while (head != NULL)
    {
        curr = head;
        head = head->next;
        free(curr->lastname);
        free(curr->firstname);
        free(curr->year);
        free(curr);
    }
}
