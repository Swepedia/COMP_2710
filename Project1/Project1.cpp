//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Project1.cpp
//
//To Compile:
//      g++ -std=c++11 -o Project1 Project1.cpp Player.cpp
//Resources:
//      I used a method for getting random numbers, which was liked to by Zhitao Gong

#include<iostream>
#include<string>
#include<cstdlib>
#include "Player.h"
using namespace std;

void startGame(void);
/*
 * Return:
 *      Makes a Player and starts the game
*/

void viewHighScores(void);
/*
 * Return:
 *      Uses the file accessor to print out a list of the top 10 high scores
 */

void quit(void);
/*
 * Return:
 *      Ends the program
 */

bool continuePlaying = true;
string name = "";
int option;

int main() {
    srand(time(0));
    cout << "What is your name?\n";
    cin >> name;
    cout << "==========================================================\n";
    cout << "                  Welcome, " << name << "\n";
    cout << "==========================================================\n\n";
    
    cout << "1) Start a new game of Shelby Center and Dragons\n";
    cout << "2) View the high scores\n";
    cout << "3) Quit\n";

    //Main game loop
    while(true) {
        cout << "\nPick an option: ";
        cin >> option;
        cout << endl;

        switch(option) {
            case 1:
                //make Player and start game
                break;
            case 2:
                //view high scores
                break;
            case 3:
                //Quits the program
                return 0;
                break;
            default:
                cout << "Input a valid option.\n";
                break;
        }
    }

    return 0;
}
