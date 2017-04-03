//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: FileAccessor.h

#include "FileAccessor.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

ifstream inStream;
ofstream outStream;
int highScores[10];

void getHighScores() {
    cout << "=====================\n";
    cout << "     High Scores\n";
    cout << "=====================\n\n";

    inStream.open("highScores.txt");
    if(inStream.fail()) {
        cout << "Failed to locate highScores.txt\n";
        exit(1);
    }

    char next;
    int i = 1;
    inStream.get(next);
    while(!inStream.eof()) {
        cout << i << ". ";
        cout << next << endl;
        inStream.get(next);
    }
    inStream.close();
}

void changeHighScore(int score) {
    inStream.open("highScores.txt");
    if(inStream.fail()) {
        cout << "Failed to locate highScores.txt\n";
        exit(1);
    }

    outStream.open("highScores.txt");
    if(outStream.fail()) {
        cout << "Failed to locate highScores.txt\n";
        exit(1);
    }


    char next;
    int i = 0;
    inStream.get(next);
    while(!inStream.eof()) {
        highScores[i] = static_cast<int>(next);
        i++;
    }

    for(int k = 0; k < 10; k++) {
        if(score > highScores[k]) {
            highScores[k] = score;
            break;
        }
    }

    int k = 0;
    while(k < 10) {
        outStream << highScores[k] << endl;
    }

    inStream.close();
    outStream.close();
}
