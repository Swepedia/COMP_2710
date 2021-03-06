//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Player.h

#include<random>
#include<iostream>
#include<cstdlib>
using namespace std;

class Player
{
    const int RANGE_LOWER = 8;
    const int RANGE_UPPER = 25;

    int stepsRemaining;
    int timeLeft;
    int intelligence;
    int money;

public:
Player();
/*
 * Constructor for Player
 */

void step(void);
/*
 * Includes the code for determining the type of encounter to have
 *
 * Decrements the stepsRemaining
 * Decrements the timeLeft
 */

void searchMoney(void);
/*
 * Consumes timeLeft to search for a random amount of money within a range
 *
 * Decrements timeLeft
 * Increments money
 */

void readPaper(void);
/*
 * Consumes timeLeft to increase intelligence by random amount witin a range
 *
 * Decrements timeLeft
 * Increment money
 */

void viewCharacter(void);
/*
 * Prints out information about current stats of stepsRemaining, timeLeft, intelligence, and money
 */

int tallyScore(void);
/*
 * Returns the total score for this Player
 */

bool isAlive(void);
/*
 * Returns whether or no this Player is alive
 */
bool hasWon(void);
};
