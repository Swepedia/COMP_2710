//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Project2.cpp
//
//To Compile:
//  g++ -o Project2 Project2.cpp
//
//Resources:

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct User {
    string username;
    string password;
    int role;
};

struct Client {
    string name;
    string address;
    int ssn;
    string employer;
    double income;
};

int login();
/*
 * displays the login text
 * returns the option chosen:
 *      1)Login
 *      2)Quit
 */

int main() {
    if(login() == 1) {
    } else {
        return 0;
    }
    return 0;
}

int login() {
    cout << "================================================================\n";
    cout << "|         Welcome to the Auburn branch of Tiger bank!          |\n";
    cout << "================================================================\n";
    cout << "1) Login\n";
    cout << "2) Quit\n";
    cout << "Please choose an option: ";
    int answer;
    do {
        cin >> answer;
    } while(answer / 2);
    return answer;
}
