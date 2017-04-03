//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: FileAccessor.h

#include "FileAccessor.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<sstream>
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
    inStream.get(next);
    while(!inStream.eof()) {
        cout << next; 
        inStream.get(next);
    }
    inStream.close();
    cout << endl;
}

void changeHighScore(int score, string name) {
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
    inStream.get(next);
    for(int k = 1; k < 20; k += 2) {
        highScores[i] = static_cast<int>(next);
        inStream.get(next);
        inStream.get(next);
        i++;
    }

    inStream.close();
    inStream.open("highScores.txt");
    string line;
    string names;
    while(getline(inStream, line)) {
        names += " ";
        names += line;
        getline(inStream, line);
    }

    int pos;
    for(int k = 0; k < 10; k++) {
        if(score > highScores[k]) {
            highScores[k] = score;
            pos = k;
            break;
        }
    }

    for(int k = 0; k < names.length(); k++) {
        int j = 0;
        int x = 0;
        int y = 0;
        if(names.at(k) == ' ') {
            y = k;
            j++;
            if(j == pos) {
                names.erase(x, y - x);
                names.insert(x, name);
            }
            x = y;
        }
    }

    istringstream sstream(names);
    int k = 0;
    do {
        string sub;
        sstream >> sub;
        outStream << sub << endl;
        outStream << highScores[k] << endl;
        k++;
    }
    while(k < 10);

    inStream.close();
    outStream.close();
}
