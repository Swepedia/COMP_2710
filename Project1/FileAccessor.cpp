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

void getHighScores() {
    cout << "=====================\n";
    cout << "     High Scores\n"
    cout << "=====================\n\n";

    inStream.open("highScores.txt");
    if(inStream.fail()) {
        cout << "Failed to locate highScores.txt\n";
        exit(1);
    }

    int n = 1;
    inStream.get(next);
    while(!inStream.eof()) {
        cout << n << ". "
        cout << next << endl;
        inStream.get(next);
    }
    inStram.close();
}
