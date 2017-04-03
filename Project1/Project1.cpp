//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Project1.cpp
//
//To Compile:
//      g++ -std=c++11 -o Project1 Project1.cpp Player.cpp EncounterDecider.cpp Puzzle.cpp FileAccessor.cpp
//Resources:
//      I used a method for getting random numbers, which was liked to by Zhitao Gong
//      I used the text book to figure out classes

#include<iostream>
#include<string>
#include<cstdlib>
#include "Player.h"
#include "EncounterDecider.h"
#include "Puzzle.h"
#include "FileAccessor.h"
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
    
    //Main game loop
    while(true) {
        cout << "1) Start a new game of Shelby Center and Dragons\n";
        cout << "2) View the high scores\n";
        cout << "3) Quit\n\n";

        cout << "\nPick an option: ";
        cin >> option;
        cout << endl;

        
        Player *player = new Player();
        switch(option) {
            case 1:
            {
                //Start game
                int choice = 0;
                bool play = true;
                while(play) {
                    cout << "You have:\n\n";
                    player->viewCharacter();
                    cout << "1) Move(-time)\n";
                    cout << "2) Read technical papers (+int -time)\n";
                    cout << "3) Search for money (-time +money)\n";
                    cout << "4) View character\n";
                    cout << "5) Quit to main menu\n\n";
                    cout << "please choose an action: ";
                    cin >> choice;
                    switch(choice) {
                        case 1:
                            player -> step();
                            break;
                        case 2:
                            player -> readPaper();
                            break;
                        case 3:
                            player -> searchMoney();
                            break;
                        case 4:
                            player -> viewCharacter();
                            cout << endl;
                            break;
                        case 5:
                            play = false;
                            break;
                        default:
                            cout << "Input a valid option.\n";
                            break;

                    }
                    if(!(player -> isAlive())) {
                        cout << "You have died!\n";
                        changeHighScore(player -> tallyScore());
                        play = false;
                    }
                    if(player -> hasWon()) {
                        cout << "Congratulations! You win!\n";
                        changeHighScore(player -> tallyScore());
                        play = false;
                    }
                }
            }
                break;
            case 2:
                //view high scores
                getHighScores();
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
