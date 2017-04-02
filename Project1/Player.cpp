//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Player.cpp

#include<Player.h>
#include<random>

private final int RANGE_LOWER = 8;
private final int RANGE_UPPER = 25;

private int stepsRemaining;
private int time;
private int intelligence;
private int money;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(RANGE_LOWER, RANGE_UPPER);

void Player() {
    stepsRemaining = 20;
    time = dis(gen);
    intelligence = dis(gen);
    money = dis(gen);
}

void step() {
    //use EncounterDecider class to decide the encounter
}

void searchMoney() {
}
