//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: hw3.cpp
//To compile type:
//    "g++ -o hw3 hw3.cpp"

#include<iostream>
#include<cassert>
#include<cstdlib>
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


bool firstShotBeenFired = false;
bool A_alive = true;
bool B_alive = true;
bool C_alive = true;
const int numOfSimulations = 10000;

int main() {
    cout << "*** Welcome to Maxwell's Duel Simulator ***\n";
    
    test_at_least_two_alive();
    wait();

    test_Aaron_shoots1();
    wait();

    test_Bob_shoots();
    wait();

    test_Charlie_shoots();
    wait();

    test_Aaron_shoots2();
    wait();
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
    int odds = rand() % 300;
    bool hit = false;

    //implements the 1/3 accuracy of Aaron
    if(odds < 100) {
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
    int odds = rand() % 200;
    bool hit = false;

    //implements 1/2 accuracy of Bob
    if(odds < 100) {
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
    int odds = rand() % 300;
    bool hit = false;

    //implements 1/3 accuracy of Aaron
    if(odds < 100) {
        hit = true;
    }

    if(!firstShotBeenFired) {
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

void wait() {
    cout << "Press any key to continue...";
    cin.ignore().get();
    cout << "\n";
}
