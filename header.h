#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
typedef class student {
    public:
    int rollNo;
    char name[20];
    float precent;
    class student* next;
}SLL;
void addRecord(SLL **);
void printRecord(SLL *);
void deleteRecord(SLL **);
void deleteAccordingToRollNo(SLL **);
void deleteAccordingToName(SLL **);