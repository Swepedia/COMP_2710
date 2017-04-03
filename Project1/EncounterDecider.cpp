//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: EncounterDecider.cpp

#include<cstdlib>
using namespace std;

const int  oddsNothing = 25;
const int oddsPuzzle = 25;
const int oddsProfessor = 10;
const int  oddsGradStudent = 10;
const int oddsGruntWork = 15;
const int  oddsGradePapers = 10;

int decideEncounter(void) {
    int odds = rand() % 100;
    if(odds < oddsNothing)
        return 0;
    if(odds < oddsNothing + oddsPuzzle)
        return 1;
    if(odds < oddsNothing + oddsPuzzle + oddsProfessor)
        return 2;
    if(odds < oddsNothing + oddsPuzzle + oddsProfessor + oddsGradStudent)
        return 3;
    if(odds < oddsNothing + oddsPuzzle + oddsProfessor + oddsGradStudent + oddsGruntWork)
        return 4;
    return 5;
}
