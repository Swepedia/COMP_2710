//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: hw4.cpp
//To compile:
//      g++ -o hw4 hw4.cpp
//
//resources:

#include<iostream>
#include<fstream>
using namespace std;

ifstream file1;
ifstream file2;

int file1Next;
int file2Next;

const int MAX_ARRAY_SIZE = 1000;
int sorted[MAX_ARRAY_SIZE];

int Main() {
