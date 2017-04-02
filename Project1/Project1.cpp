//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Project1.cpp
//
//To Compile:
//Resources:

#include<iostream>
#include<string>
using namespace std

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

int Main() {
    cout << "What is your name?\n";
    cin >> name;
    cout << "==========================================================\n";
    cout << "                  Welcome, " << name << "\n";
    cout << "==========================================================\n\n";
    
    cout << "1) Start a new game of Shelby Center and Dragons\n";
    cout << "2) View the high scores\n";
    cout << "3) Quit\n";

    cout << "Pick an option: ";
    cin >> option;
    cout << endl;
    bool temp = true;
    while(temp) {
        switch(option) {
            case 1:
                //make Player
                temp = false;
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
