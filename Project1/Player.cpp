//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Player.cpp

#include "Player.h"
#include<random>
#include<iostream>
#include<cstdlib>
using namespace std;
#include "EncounterDecider.h"

const int RANGE_LOWER = 8;
const int RANGE_UPPER = 25;

int stepsRemaining;
int timeLeft;
int intelligence;
int money;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(RANGE_LOWER, RANGE_UPPER);

Player::Player() {
    stepsRemaining = 20;
    timeLeft = static_cast<int>(dis(gen));
    intelligence = static_cast<int>(dis(gen));
    money = static_cast<int>(dis(gen));
}

void Player::step() {
    int encounter = decideEncounter();
    int timeLost;
    int intelligenceGained;

    switch(encounter) {
        case 1:
            break;
        case 2:
            timeLost = (rand() % 4) + 1;
            intelligenceGained = rand() % 2;
            cout << "Uh Oh! It's a professor trying to talk to you!\n";
            cout << "You lose " << timeLost << " time, and gain " << intelligenceGained << " intelligence!\n";
            timeLeft -= timeLost;
            intelligence += intelligenceGained;
            break;
        case 3:
            timeLost = (rand() % 3) + 1;
            cout << "It's a grad student!\n";
            cout << "You lose " << timeLost << " time.\n";
            timeLeft -= timeLost;
            break;
        case 4:
            cout << "You get hit by gruntwork.\n";
            cout << "Yout lose 2 time but gain 7 bucks!\n";
            timeLeft -= 2;
            money += 7;
            break;
    }
}

void Player::searchMoney() {
    money += rand() % 3;
    timeLeft --;
}

void Player::readPaper() {
    intelligence += rand() % 3;
    timeLeft --;
}

void Player::viewCharacter() {
    cout << "=============\n";
    cout << "  Character\n";
    cout << "=============\n\n";

    cout << "Steps-to-finish: " << stepsRemaining << endl;
    cout << "Time: " << timeLeft << endl;
    cout << "Intelligence: " << intelligence << endl;
    cout << "Money: $" << money <<".00\n\n";
}

int Player::tallyScore() {
    return timeLeft + intelligence + money;
}

bool Player::isAlive() {
    if(timeLeft > 0 && intelligence > 0 && money > 0)
        return false;
    return true;
}
