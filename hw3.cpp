//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: hw3.cpp
//To compile type:
//    "g++ -o hw3 hw3.cpp"
#include<iostream>
using namespace std;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
/* Input: A_alive indicates whether Aaron is alive */ 
/*        B_alive indicates whether Bob is alive */ 
/*        C_alive indicates whether Charlie is alive */ 
/* Return: true if at least two are alive */ 
/*         otherwise return false */

void Aaron_shoots1(bool& B_alive, bool& C_alive);
/* Strategy 1: Use call by reference  
* Input: B_alive indicates whether Bob alive or dead  
*     C_alive indicates whether Charlie is alive or dead  
* Return: Change B_alive into false if Bob is killed.    
*         Change C_alive into false if Charlie is killed. 
*/

void Bob_shoots(bool& A_alive, bool& C_alive);
/* Call by reference  
*  Input: A_alive indicates if Aaron is alive or dead  
*      C_alive indicates whether Charlie is alive or dead  
*  Return: Change A_alive into false if Aaron is killed.    
*          Change C_alive into false if Charlie is killed. 
*/

void Charlie_shoots(bool& A_alive, bool& B_alive);
/* Call by reference
*  Input: A_alive indicate if Aaron is alive or dead
*       B_alive indicates whether Bob is alive or dead
*  Return: Change A_alive into false if Aaron is killed
*          Change B_alive into false if Bob is killed
*/

void Aaron_shoots2(bool& B_alive, bool& C_alive);
/* Strategy 2: Use call by reference  
 * Input: B_alive indicates whether Bob alive or dead  
 *     C_alive indicates whether Charlie is alive or dead  
 * Return: Change B_alive into false if Bob is killed.    
 *         Change C_alive into false if Charlie is killed. 
 */



int main() {
    bool A_alive = true;
    bool B_alive = true;
    bool C_alive = true;
    bool firstShotBeenFired = false;
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

void Charlie_shoots(bool& A_alive, bool& B_alive) {
    if(B_alive) {
        B_alive = false;
    }else {
        A_alive = false;
    }
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
}


