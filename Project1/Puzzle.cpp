//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Puzzle.cpp

#include "Puzzle.h"
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

int puzzle;

string p0 = "What is the derivative of x^2?";
string a0 = "2x";
string p1 = "What is 300 - 22?";
string a1 = "278";
string p2 = "The more you take, the more you leave behind. What am I?";
string a2 = "footsteps";
string p3 = "You can see me in water, but I never get wet. What am I?";
string a3 = "reflection";
string p4 = "What belongs to you, but others use it more than you do?";
string a4 = "name";

void Puzzle() {
    puzzle = 99;
}

void getPuzzle() {
    puzzle = rand() % 5;
    switch(puzzle) {
        case 0:
            cout << p0;
            break;
        case 1:
            cout << p1;
            break;
        case 2:
            cout << p2;
            break;
        case 3:
            cout << p3;
            break;
        case 4:
            cout << p4;
            break;
    }
}

bool puzzleCheck(string answer) {
    switch(puzzle) {
        case 0:
            if(p0.compare(answer) == 0) 
                return true;
            break;
        case 1:
            if(p1.compare(answer) == 0)
                return true;
            break;
        case 2:
            if(p2.compare(answer) == 0)
                return true;
            break;
        case 3:
            if(p3.compare(answer) == 0)
                return true;
            break;
        case 4:
            if(p4.compare(answer) == 0)
                return true;
            break;
        default:
            return false;
    }
}

