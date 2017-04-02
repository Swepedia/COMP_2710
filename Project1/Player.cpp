//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Player.cpp

#include "Player.h"
#include<random>
#include<iostream>
using namespace std;

const int RANGE_LOWER = 8;
const int RANGE_UPPER = 25;

int stepsRemaining;
int timeLeft;
int intelligence;
int money;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(RANGE_LOWER, RANGE_UPPER);

void Player() {
    stepsRemaining = 20;
    timeLeft = static_cast<int>(dis(gen));
    intelligence = static_cast<int>(dis(gen));
    money = static_cast<int>(dis(gen));
}

void step() {
    //use EncounterDecider class to decide the encounter
}

void searchMoney() {
    money += rand() % 3;
    timeLeft --;
}

void readPaper() {
    intelligence += rand() % 3;
    timeLeft --;
}

void viewCharacter() {
    cout << "=============\n";
    cout << "  Character\n";
    cout << "=============\n\n";

    cout << "Steps-to-finish: " << stepsRemaining << endl;
    cout << "Time: " << timeLeft << endl;
    cout << "Intelligence: " << intelligence << endl;
    cout << "Money: $" << money <<".00\n\n";
}

int tallyScore() {
    return timeLeft + intelligence + money;
}

bool isAlive() {
    if(timeLeft > 0 && intelligence > 0 && money > 0)
        return false;
    return true;
}
