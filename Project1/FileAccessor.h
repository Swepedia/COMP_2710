//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: FileAccessor.h

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<sstream>

void getHighScores(void);
/*
 * Gets the file highScores.txt and prints out the top 10 scores
 */

void changeHighScore(int score, std::string name);
/*
 * Checks if score deserves to be in the top 10 high scores
 */

