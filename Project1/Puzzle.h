//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Puzzle.h

#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

class Puzzle
{
public:
Puzzle(void);
/*
 * Constructor
 */

void getPuzzle(void);
/*
 * Prints out a random puzzle
 *
 * Assigns puzzle number to puzzle
 

bool puzzleCheck(std::string answer);
/*
 * Checks if the given answer for the puzzle is correct
 */
bool puzzleCheck(std::string answer);
};
