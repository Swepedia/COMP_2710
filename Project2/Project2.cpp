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
#include<vector>
#include<cstdlib>
#include<climits>
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

//int login();
/*
 * displays the login text
 * returns the option chosen:
 *      1)Login
 *      2)Quit
 */
int menuDecider(int upper);
/*
 * handles menu choices
 */
void screenAdmin();
/*
 * provides functionality for the admin screen
 */
void screenNormal();
/*
 * provides funcitonality for the non-admin screen
 */

int main() {
    cout << "================================================================\n";
    cout << "|         Welcome to the Auburn branch of Tiger bank!          |\n";
    cout << "================================================================\n";
    cout << "1) Login\n";
    cout << "2) Quit\n";
    cout << "Please choose an option: ";
    /*int answer = 0;
    cin >> answer;
    while(answer > 2 && answer < 1) {
        cout << "Input a valid value: ";
        cin >> answer;
    }
    */
    int answer;
    answer = menuDecider(2);
    if(answer == 1) {
        ifstream input("login");
        if(input.fail()) {
            cout << "Login info file not found\n";
            exit(1);
        }
        string next;
        vector<string> login;
        while(input >> next) {
            login.push_back(next);
        }
        input.close();
        string username;
        string password;
        //cin.clear();
        //cin.ignore(INT_MAX, '\n');
        bool loginSuccess = false;
        int user = 0;
        do {
            cout << "Username: ";
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);
            for(int i = 0; i < login.size(); i += 3) {
                if(login[i] == username && login[i + 1] == password) {
                    loginSuccess = true;
                    user = i;
                    break;
                }
            }
            if(!loginSuccess) {
                cout << "The user name or password is incorrect. Try again.\n";
            }
        }
        while(!loginSuccess);

        if(stoi(login[user + 2]) == 1) {
            screenAdmin();
        } else {
            screenNormal();
        }
    } else {
        return 0;
    }
    return 0;
}

/*int login() {
    cout << "================================================================\n";
    cout << "|         Welcome to the Auburn branch of Tiger bank!          |\n";
    cout << "================================================================\n";
    cout << "1) Login\n";
    cout << "2) Quit\n";
    cout << "Please choose an option: ";
    int answer = 0;
    cin >> answer;
    while(answer > 2 && answer < 1) {
        cout << "Input a valid value: "
        cin >> answer;
    }
    return answer;
}
*/

int menuDecider(int upper) {
    int answer = 0;
    cin >> answer;
    while(answer > upper && answer < 1) {
        cout << "Input a valid value: ";
        cin >> answer;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return answer;
}

void screenAdmin() {
    cout << "====================================================================\n";
    cout << "|       Teller Terminal System - System Administration             |\n";
    cout << "====================================================================\n";
    cout << "1) Client and Account Management\n";
    cout << "2) Add a branch staff member\n";
    cout << "3) Delete a branch staff member\n";
    cout << "4) Display branch staff\n";
    cout << "5) Change password\n";
    cout << "6) Exit\n";
    int answer = menuDecider(6);
}

void screenNormal() {
    cout << "====================================================================\n";
    cout << "|             Teller Terminal System - Branch Staff                |\n";
    cout << "====================================================================\n";
    cout << "1) Client and Account Management\n";
    cout << "2) Change password\n";
    cout << "3) Exit\n";
    int answer = menuDecider(3);
}
