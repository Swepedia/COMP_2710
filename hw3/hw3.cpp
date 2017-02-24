//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: hw3.cpp
//To compile:
//      "g++ -std=c++11 -o hw3 hw3.cpp"
//
//resources:
//      I used the method for getting random numbers as linked to by Zhitao Gong.

#include<iostream>
#include<cassert>
#include<stdlib.h>
#include<random>
using namespace std;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
/* Input: A_alive indicates whether Aaron is alive */ 
/*        B_alive indicates whether Bob is alive */ 
/*        C_alive indicates whether Charlie is alive */ 
/* Return: true if at least two are alive */ 
/*         otherwise return false */

void test_at_least_two_alive(void);

void Aaron_shoots1(bool& B_alive, bool& C_alive);
/* Strategy 1: Use call by reference  
* Input: B_alive indicates whether Bob alive or dead  
*     C_alive indicates whether Charlie is alive or dead  
* Return: Change B_alive into false if Bob is killed.    
*         Change C_alive into false if Charlie is killed. 
*/

void test_Aaron_shoots1(void);

void Bob_shoots(bool& A_alive, bool& C_alive);
/* Call by reference  
*  Input: A_alive indicates if Aaron is alive or dead  
*      C_alive indicates whether Charlie is alive or dead  
*  Return: Change A_alive into false if Aaron is killed.    
*          Change C_alive into false if Charlie is killed. 
*/

void test_Bob_shoots(void);

void Charlie_shoots(bool& A_alive, bool& B_alive);
/* Call by reference
*  Input: A_alive indicate if Aaron is alive or dead
*       B_alive indicates whether Bob is alive or dead
*  Return: Change A_alive into false if Aaron is killed
*          Change B_alive into false if Bob is killed
*/

void test_Charlie_shoots(void);

void Aaron_shoots2(bool& B_alive, bool& C_alive);
/* Strategy 2: Use call by reference  
 * Input: B_alive indicates whether Bob alive or dead  
 *     C_alive indicates whether Charlie is alive or dead  
 * Return: Change B_alive into false if Bob is killed.    
 *         Change C_alive into false if Charlie is killed. 
 */

void test_Aaron_shoots2(void);

void waitForKey(void);
void takeATurn(void);
char checkWinner(void);
double percentage(int wins);

char whoseTurn = 'a';
bool firstShotBeenFired = false;
bool A_alive = true;
bool B_alive = true;
bool C_alive = true;

const int numOfSimulations = 10000;
const double A_ACCURACY = 1.0/3.0;
const double B_ACCURACY = 0.5;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(0,1);

int main() {
    cout << "*** Welcome to Maxwell's Duel Simulator ***\n";
    
    test_at_least_two_alive();
    waitForKey();

    test_Aaron_shoots1();
    waitForKey();

    test_Bob_shoots();
    waitForKey();

    test_Charlie_shoots();
    waitForKey();

    firstShotBeenFired = false;
    test_Aaron_shoots2();
    waitForKey();

    cout << "Ready to test strategy 1 (run 10,000 times):\n";
    waitForKey();

    A_alive = true;
    B_alive = true;
    C_alive = true;
    int A_win1 = 0;
    int B_win1 = 0;
    int C_win1 = 0;
    for(int i = 0; i < numOfSimulations; i++) {
        do {
            takeATurn();
        }
        while(at_least_two_alive(A_alive, B_alive, C_alive));

        char result = checkWinner();
        if(result == 'a') {
            A_win1++;
        }
        else if(result == 'b') {
            B_win1++;
        } else {
            C_win1++;
        }
        A_alive = true;
        B_alive = true;
        C_alive = true;
    }

    cout << "Aaron won " << A_win1 << "/" << numOfSimulations << " duels or " << percentage(A_win1) << "%\n";
    cout << "Bob won " << B_win1 << "/" << numOfSimulations << " duels or " << percentage(B_win1) << "%\n";
    cout << "Charlie won " << C_win1 << "/" << numOfSimulations << " duels or " << percentage(C_win1) << "%\n";


    cout << "Ready to test strategy 2 (run 10,000 times):\n";
    waitForKey();

    A_alive = true;
    B_alive = true;
    C_alive = true;
    firstShotBeenFired = false;
    whoseTurn = 'a';
    int A_win2 = 0;
    int B_win2 = 0;
    int C_win2 = 0;


    for(int i = 0; i < numOfSimulations; i++) {
        Aaron_shoots2(B_alive, C_alive);
        whoseTurn = 'b';

        do {
            takeATurn();
        }
        while(at_least_two_alive(A_alive, B_alive, C_alive));

        char result = checkWinner();
        if(result == 'a') {
            A_win2++;
        }
        else if(result == 'b') {
            B_win2++;
        } else {
            C_win2++;
        }
        A_alive = true;
        B_alive = true;
        C_alive = true;
        firstShotBeenFired = false;
        whoseTurn = 'a';
    }

    cout << "Aaron won " << A_win2 << "/" << numOfSimulations << " duels or " << percentage(A_win2) << "%\n";
    cout << "Bob won " << B_win2 << "/" << numOfSimulations << " duels or " << percentage(B_win2) << "%\n";
    cout << "Charlie won " << C_win2 << "/" << numOfSimulations << " duels or " << percentage(C_win2) << "%\n";


    if(A_win1 > A_win2) {
        cout << "Strategy 1 is better than strategy 2\n";
    } else {
        cout << "Strategy 2 is better than strategy 1\n";
    }

    return 0;
}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    int count = 0;

    if(A_alive) {
        count++;
    }
    if(B_alive) {
        count++;
    }
    if(C_alive) {
        count++;
    }

    if(count >= 2) {
        return true;
    }

    return false;
}

void test_at_least_two_alive(void) {
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";

    cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "Case passed ...\n";

    cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "Case passed ...\n";

    cout << "Case 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "Case passed ...\n";

    cout << "Case 4: Aaron alive, Bob alive Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "Case passed ...\n";

    cout << "Case 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(true != at_least_two_alive(false, false, true));
    cout << "Case passed ...\n";

    cout << "Case 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(true != at_least_two_alive(false, true, false));
    cout << "Case passed ...\n";

    cout << "Case 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(true != at_least_two_alive(true, false, false));
    cout << "Case passed ...\n";

    cout << "Case 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(true != at_least_two_alive(false, false, false));
    cout << "Case passed ...\n";
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    double odds = dis(gen); 
    //srand(system("getrandom"));
    //double odds = (RAND_MAX - rand())/static_cast<double>(RAND_MAX);
    bool hit = false;
    //cout << odds;

    //implements the 1/3 accuracy of Aaron
    if(odds < A_ACCURACY) {
        hit = true;
    }

    if(C_alive && hit) {
        C_alive = false;
    }
    else if(!C_alive && hit) {
        B_alive = false;
    }
}

void test_Aaron_shoots1(void) {
    B_alive = true;
    C_alive = true;
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

    cout << "Case 1: Bob alive, Charlie alive\n";
    cout << "\tAaron is shooting at Charlie\n";
    Aaron_shoots1(B_alive, C_alive);
    if(!C_alive) {
        cout << "\tCharlie is dead.\n";
    } else {
        cout << "\tAaron missed.\n";
    }

    C_alive = true;
    B_alive = false;
    cout << "Case 2: Bob dead, Charlie alive\n";
    cout << "\tAaron is shooting at Charlie\n";
    Aaron_shoots1(B_alive, C_alive);
    if(!C_alive) {
        cout << "\tCharlie is dead.\n";
    } else {
        cout << "\tAaron missed.\n";
    }

    C_alive = false;
    B_alive = true;
    cout << "Case 3: Bob alive, Charlie dead\n";
    cout << "\tAaron is shooting at Bob\n";
    Aaron_shoots1(B_alive, C_alive);
    if(!B_alive) {
        cout << "\tBob is dead.\n";
    } else {
        cout << "\tAaron missed.\n";
    }

    B_alive = true;
    C_alive = true;
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
    double odds = dis(gen);
    //srand(time(0));
    //double odds = (RAND_MAX - rand())/static_cast<double>(RAND_MAX);
    bool hit = false;
    //cout << odds;

    //implements 1/2 accuracy of Bob
    if(odds < B_ACCURACY) {
        hit = true;
    }

    if(C_alive && hit) {
        C_alive = false;
    }
    else if(!C_alive && hit) {
        A_alive = false;
    }
}

void test_Bob_shoots(void) {
    A_alive = true;
    C_alive = true;
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive\n";

    cout << "Case 1: Aaron alive, Charlie alive\n";
    cout << "\tBob is shooting at Charlie\n";
    Bob_shoots(A_alive, C_alive);
    if(!C_alive) {
        cout << "\tCharlie is dead.\n";
    } else {
        cout << "\tBob missed.\n";
    }

    A_alive = false;
    C_alive = true;
    cout << "Case 2: Aaron dead, Charlie alive\n";
    cout << "\tBob is shooting at Charlie\n";
    Bob_shoots(A_alive, C_alive);
    if(!C_alive) {
        cout << "\tCharlie is dead.\n";
    } else {
        cout << "\tBob missed.\n";
    }

    A_alive = true;
    C_alive = false;
    cout << "Case 3: Aaron is alive, Charlie is dead\n";
    cout << "\tBob is shooting at Aaron\n";
    Bob_shoots(A_alive, C_alive);
    if(!A_alive) {
        cout << "\tAaron is dead.\n";
    } else {
        cout << "\tBob missed.\n";
    }

    A_alive = true;
    C_alive = true;
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
    if(B_alive) {
        B_alive = false;
    } else {
        A_alive = false;
    }
}

void test_Charlie_shoots(void) {
    A_alive = true;
    B_alive = true;
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

    cout << "Case 1: Aaron is alive, Bob is alive\n";
    cout << "\tCharlie is shooting at Bob\n";
    Charlie_shoots(A_alive, B_alive);
    if(!B_alive) {
        cout << "\tBob is dead.\n";
    } else {
        cout << "\tCharlie missed.\n";
    }

    B_alive = true;
    cout << "Case 2: Aaron dead, Bob alive\n";
    cout << "\tCharlie shooting at Bob\n";
    Charlie_shoots(A_alive, B_alive);
    if(!B_alive) {
        cout << "\tBob is dead.\n";
    } else {
        cout << "\tCharlie missed.\n";
    }

    B_alive = false;
    A_alive = true;
    cout << "Case 3: Aaron alive, Bob dead\n";
    cout << "\t Charlie is shooting at Aaron\n";
    Charlie_shoots(A_alive, B_alive);
    if(!A_alive) {
        cout << "\tAaron is dead.\n";
    } else {
        cout << "\tCharlie missed.\n";
    }

    A_alive = true;
    B_alive = true;
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    double odds = dis(gen);
    //srand(time(0));
    //double odds = (RAND_MAX - rand())/static_cast<double>(RAND_MAX);
    bool hit = false;
    //cout << odds;

    //implements 1/3 accuracy of Aaron
    if(odds < A_ACCURACY) {
        hit = true;
    }

    if(firstShotBeenFired) {
        if(C_alive && hit) {
            C_alive = false;
        }
        else if(!C_alive && hit) {
            B_alive = false;
        }
    }
    firstShotBeenFired = true;
}

void test_Aaron_shoots2(void) {
    firstShotBeenFired = false;
    B_alive = true;
    C_alive = true;
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

    cout << "Case 1: Bob alive, Charlie alive\n";
    cout << "\t Aaron intentionally misses his first shot\n";
    Aaron_shoots2(B_alive, C_alive);
    if(B_alive && C_alive) {
        cout << "\tBoth Bob and Charlie are alive.\n";
    } else {
        cout << "\tSomething went wrong.\n";
    }

    B_alive = false;
    cout << "Case 2: Bob dead, Charlie alive\n";
    cout << "\tAaron is shooting at Charlie\n";
    Aaron_shoots2(B_alive, C_alive);
    if(!C_alive) {
        cout << "\tCharlie is dead.\n";
    } else {
        cout << "\tAaron missed.\n";
    }

    B_alive = true;
    C_alive = false;
    cout << "Case 3: Bob alive, Charlie dead\n";
    cout << "\tAaron is shooting at Bob\n";
    Aaron_shoots2(B_alive, C_alive);
    if(!B_alive) {
        cout << "\tBob is dead.\n";
    } else {
        cout << "\tAaron missed.\n";
    }

    B_alive = true;
    C_alive = true;
    firstShotBeenFired = false;
}

void waitForKey(void) {
    cout << "Press any key to continue...";
    cin.ignore().get();
}

void takeATurn(void) {
    switch(whoseTurn) {

        case 'a':
            Aaron_shoots1(B_alive, C_alive);
            if(B_alive) {
                whoseTurn = 'b';
            } else {
                whoseTurn = 'c';
            }
            break;
        case 'b':
            Bob_shoots(A_alive, C_alive);
            if(C_alive) {
            whoseTurn = 'c';
            } else {
                whoseTurn = 'a';
            }
            break;
        case 'c':
            Charlie_shoots(A_alive, B_alive);
            whoseTurn = 'a';
            break;
    }
}

char checkWinner(void) {
    if(A_alive) {
        return 'a';
    }
    else if(B_alive) {
        return 'b';
    }
    return 'c';
}

double percentage(int wins) {
    return ((double)wins/(double)numOfSimulations) * 100.0;
}
