//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Player.h

void step(void);
/*
 * Includes the code for determining the type of encounter to have
 *
 * Decrements the stepsRemaining
 */

void searchMoney(void);
/*
 * Consumes time to search for a random amount of money within a range
 *
 * Decrements time
 * Increments money
 */

void readPaper(void);
/*
 * Consumes time to increase intelligence by random amount witin a range
 *
 * Decrements time
 * Increment money
 */

void viewCharacter(void);
/*
 * Prints out information about current stats of stepsRemaining, time, intelligence, and money
 */

void quitToMainMenu(void);
/*
 * Exits to the main menu
 */

int tallyScore(void);
/*
 * Returns the total score for this Player
 */

bool isAlive(void);
/*
 * Returns whether or no this Player is alive
 */

