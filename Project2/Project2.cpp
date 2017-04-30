//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: Project2.cpp
//
//To Compile:
//  g++ -o Project2 Project2.cpp
//
//Resources:
//  Absolute C++ 6th ed.
//  code posted in specifications on how to mask the passwords with '*'

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
    string role;
};

struct Client {
    string name;
    string address;
    string ssn;
    string employer;
    int income;
};

struct Account {
    string name;
    int accountNumber;
    string accountType;
    int balance;
};

class ScreenNormal {
public:
    int userID;
    vector<User>* login;
    vector<Client>* clients;
    vector<Account>* accounts;
    ScreenNormal(int userID, vector<User>* login, vector<Client>* clients, vector<Account>* accounts);
    bool accountManagement();
    void changePassword();
};

class ScreenAdmin : public ScreenNormal {
public:
    ScreenAdmin(int userID, vector<User>* login, vector<Client>* clients, vector<Account>* accounts);
    void staffAdd();
    void staffDelete();
    void staffDisplay();
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
    int answer;
    answer = menuDecider(2);
    if(answer == 1) {
        ifstream input("login");
        if(input.fail()) {
            cout << "Login info file not found\n";
            exit(1);
        }
        string next;
        vector<User> login;
        User tempUser;
        while(input >> tempUser.username) {
            input >> tempUser.password;
            input >> tempUser.role;
            login.push_back(tempUser);
        }
        input.close();
        input.open("clients");
        if(input.fail()) {
            cout << "Client info file not found\n";
            exit(1);
        }
        vector<Client> clients;
        Client tempClient;
        while(input >> tempClient.name) {
            input >> tempClient.address;
            input >> tempClient.ssn;
            input >> tempClient.employer;
            input >> next;
            tempClient.income = stoi(next);
            clients.push_back(tempClient);
        }
        input.close();
        input.open("accounts");
        if(input.fail()) {
            cout << "Account info file not found\n";
            exit(1);
        }
        vector<Account> accounts;
        Account tempAccount;
        while(input >> tempAccount.name) {
            input >> next;
            tempAccount.accountNumber = stoi(next);
            input >> tempAccount.accountType;
            input >> next;
            tempAccount.balance = stoi(next);
            accounts.push_back(tempAccount);
        }
        string username;
        string password;
        bool loginSuccess = false;
        int user = 0;
        do {
            cout << "Username: ";
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);
            for(int i = 0; i < login.size(); i++) {
                if(login[i].username == username && login[i + 1].password == password) {
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

        if(stoi(login[user + 2].role) == 1) {
            screenAdmin();
        } else {
            screenNormal();
        }
    } else {
        return 0;
    }
    return 0;
}


int menuDecider(int upper) {
    cout << "Please choose an option: ";
    int answer = 0;
    cin >> answer;
    while(answer > upper || answer < 1) {
        cout << "Input a valid option: ";
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

////////////////////////////////////////////////////////////////////////////////////////////
//                                      Classes                                           //
////////////////////////////////////////////////////////////////////////////////////////////


    //ScreenNormal

        ScreenNormal::ScreenNormal(int userID, vector<User>* login, vector<Client>* clients,
                vector<Account>* accounts)
            : userID(userID), login(login), clients(clients), accounts(accounts) {}

        bool ScreenNormal::accountManagement() {
            cout << "======================================================================\n";
            cout << "|      Teller Terminal System -- Client and Account Managament       |\n";
            cout << "======================================================================\n";
            cout << "1) Add a Client\n";
            cout << "2) Add an Account\n";
            cout << "3) Edit Client Information\n";
            cout << "4) Manage an Account\n";
            cout << "5) Save Client and Account Information\n";
            cout << "6) Exit\n";

            bool exit = false;
            int answer = menuDecider(6);

            switch (answer) {
                case 1:
                    {
                        Client tempClient;
                        string temp;
                        cout << "A new Client will be added:\n";
                        cout << "Client name: ";
                        getline(cin, tempClient.name);
                        cout << "Address: ";
                        getline(cin, tempClient.address);
                        cout << "Social security number: ";
                        getline(cin, tempClient.ssn);
                        cout << "Employer: ";
                        getline(cin, tempClient.employer);
                        cout << "Annual income: ";
                        getline(cin, temp);
                        tempClient.income = stoi(temp);
                        clients->push_back(tempClient);
                        cout << "A new client was added!\n";
                        cout << "Press any key to continue...";
                        getchar();
                        break;
                    }
                case 2:
                    {
                        Account tempAccount;
                        string temp;
                        bool success = false;
                        do {
                            cout << "Choose a client: ";
                            getline(cin, temp);
                            for(int i = 0; i < clients->size(); i++) {
                                if(clients->at(i).name == temp)
                                    success = true;
                            }
                            if(!success)
                                cout << "Error - client not in the system!\n";
                        } while(!success);

                        tempAccount.name = temp;
                        cout << "A new account will be created for " << temp << "...\n";
                        cout << "Account number: ";
                        getline(cin, temp);
                        tempAccount.accountNumber = stoi(temp);
                        cout << "Account type: ";
                        getline(cin, tempAccount.accountType);
                        cout << "Balance: ";
                        getline(cin, temp);
                        tempAccount.balance = stoi(temp);
                        accounts->push_back(tempAccount);
                        cout << "A new account was created for " << tempAccount.name << "!\n";
                        cout << "Press any key to continue...";
                        getchar();
                        break;
                    }
            }

            return exit;
        }

        void ScreenNormal::changePassword() {
        }


    //ScreenAdmin

        ScreenAdmin::ScreenAdmin(int userID, vector<User>* login, vector<Client>* clients,
                vector<Account>* accounts)
            : ScreenNormal(userID, login, clients, accounts) {}

        void ScreenAdmin::staffAdd() {
        }

        void ScreenAdmin::staffDelete() {
        }

        void ScreenAdmin::staffDisplay() {
        }
