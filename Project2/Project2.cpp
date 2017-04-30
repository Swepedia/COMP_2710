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
#include<sstream>
using namespace std;

typedef string* StrPtr;

struct User {
    string username;
    string password;
    int role;
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
vector<string> checkForClient(vector<Client> clients);
/*
 * checks if the client exists and returns the client's name
 */
void saveAccounts(vector<Account> accounts);
/*
 * saves the accounts vector to file
 */
void saveClients(vector<Client> clients);
/*
 * saves the clients vector to file
 */
void saveUsers(vector<User> login);
/*
 * saves the users vector to file
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
            input >> next;
            tempUser.role = stoi(next);
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
        while(getline(input, tempClient.name)) {
            getline(input, tempClient.address);
            getline(input, tempClient.ssn);
            getline(input, tempClient.employer);
            getline(input, next);
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
        while(getline(input, tempAccount.name)) {
            getline(input, next);
            tempAccount.accountNumber = stoi(next);
            getline(input, tempAccount.accountType);
            getline(input, next);
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
                if(login[i].username == username && login[i].password == password) {
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

        if(login[user].role == 1) {
            bool run = true;
            ScreenAdmin currentUser(user, &login, &clients, &accounts);
            while(run) {
                screenAdmin();
                int answer = menuDecider(6);
                switch(answer) {
                    case 1:
                    {
                        bool exit = false;
                        while(!exit) {
                            exit = currentUser.accountManagement();
                        }
                        break;
                    }
                    case 2:
                        currentUser.staffAdd();
                        break;
                    case 3:
                        currentUser.staffDelete();
                        break;
                    case 4:
                        currentUser.staffDisplay();
                        break;
                    case 5:
                        currentUser.changePassword();
                        break;
                    case 6:
                        run = false;
                }
            }
        } else {
            bool run = true;
            ScreenNormal currentUser(user, &login, &clients, &accounts);
            while(run) {
                screenNormal();
                int answer = menuDecider(3);
                switch(answer) {
                    case 1:
                    {
                        bool exit = false;
                        while(!exit) {
                            exit = currentUser.accountManagement();
                        }
                        break;
                    }
                    case 2:
                        currentUser.changePassword();
                        break;
                    case 3:
                        run = false;
                }
            }
        }
        saveUsers(login);
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
}

void screenNormal() {
    cout << "====================================================================\n";
    cout << "|             Teller Terminal System - Branch Staff                |\n";
    cout << "====================================================================\n";
    cout << "1) Client and Account Management\n";
    cout << "2) Change password\n";
    cout << "3) Exit\n";
}

vector<string> checkForClient(vector<Client> clients) {
    string temp;
    bool success = false;
    vector<string> output;
    do {
        cout << "Choose a client: ";
        getline(cin, temp);
        for(int i = 0; i < clients.size(); i++) {
            if(clients.at(i).name == temp) {
                success = true;
                ostringstream stream;
                stream << i;
                output.push_back(stream.str());
            }
        }
        if(!success)
            cout << "Error - client not in the system!\n";
    } while(!success);
    string swap = output[0];
    output[0] = temp;
    output.push_back(swap);
    return output;
}

void saveUsers(vector<User> login) {
    ofstream outputUsers("login");
    if(outputUsers.fail()) {
        cout << "Failed to save User information";
        exit(1);
    }
    for(int i = 0; i < login.size(); i++) {
        outputUsers << login.at(i).username << endl
            << login.at(i).password << endl
            << login.at(i).role << endl;
    }
}

void saveClients(vector<Client> clients) {
    ofstream outputClients("clients");
    if(outputClients.fail()) {
        cout << "Failed to save client information";
        exit(1);
    }
    for(int i = 0; i < clients.size(); i++) {
        outputClients << clients.at(i).name << endl
            << clients.at(i).address << endl
            << clients.at(i).ssn << endl
            << clients.at(i).employer << endl
            << clients.at(i).income << endl;
    }
    outputClients.close();
}

void saveAccounts(vector<Account> accounts) {
    ofstream outputAccounts("accounts");
    if(outputAccounts.fail()) {
        cout << "Failed to save client information";
        exit(1);
    }
    for(int i = 0; i < accounts.size(); i++) {
        outputAccounts << accounts.at(i).name << endl
            << accounts.at(i).accountNumber << endl
            << accounts.at(i).accountType << endl
            << accounts.at(i).balance << endl;
    }
    outputAccounts.close();
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
                        clients -> push_back(tempClient);
                        cout << "A new client was added!\n";
                        cout << "Press any key to continue...";
                        getchar();
                        break;
                    }
                case 2:
                    {
                        Account tempAccount;
                        string temp;
                        /*bool success = false;
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
                        */

                        temp = (checkForClient(*clients))[0];

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
                        accounts -> push_back(tempAccount);
                        cout << "A new account was created for " << tempAccount.name << "!\n";
                        cout << "Press any key to continue...";
                        getchar();
                        break;
                    }
                case 3:
                    {
                        vector<string> temp = checkForClient(*clients);
                        int loc = stoi(temp[1]);
                        cout << "Display " << temp[0] << "'s information:\n";
                        cout << "Address: " << clients -> at(loc).address << endl;
                        cout << "Social security number: " << clients -> at(loc).ssn << endl;
                        cout << "Employer: " << clients -> at(loc).employer << endl;
                        cout << "Annual income: " << clients -> at(loc).income << endl;
                        cout << "Client " << temp[0] << "'s information will be updated ...\n";
                        cout << "1) Confirm\n";
                        cout << "2) Cancel\n";
                        int answer = menuDecider(2);
                        if(answer == 1) {
                            Client tempClient;
                            string intConverter;
                            cout << "Address: ";
                            getline(cin, tempClient.address);
                            cout << "Social security number: ";
                            getline(cin, tempClient.ssn);
                            cout << "Employer: ";
                            getline(cin, tempClient.employer);
                            cout << "Annual income: ";
                            getline(cin, intConverter);
                            tempClient.income = stoi(intConverter);
                            clients -> erase(clients -> begin() + loc);
                            tempClient.name = temp[0];
                            clients -> push_back(tempClient);
                            cout << "Client " << temp[0] << "'s information was updated!\n";
                            cout << "Press any key to continue...";
                            getchar();
                        } else {
                            return true;
                        }
                        break;
                    }
                case 4:
                    {
                        string temp;
                        int loc;
                        int target;
                        bool success = false;
                        do {
                            cout << "Which account will be managed? ";
                            getline(cin, temp);
                            target = stoi(temp);
                            for(int i = 0; i < accounts -> size(); i++) {
                                if(target == accounts -> at(i).accountNumber) {
                                    success = true;
                                    loc = i;
                                }
                            }
                            if(!success) {
                                cout << "Error -- Account " << temp << " is not in the System!\n";
                            }
                        } while(!success);
                        cout << "Manage account " << temp << " for " << accounts -> at(loc).name << endl;
                        do {
                            cout << "1) Deposit\n";
                            cout << "2) Withdrawal\n";
                            cout << "3) Cancel\n";
                            int answer = menuDecider(3);
                            switch(answer) {
                                case 1:
                                    {
                                        cout << "Deposit amount: ";
                                        getline(cin, temp);
                                        accounts -> at(loc).balance += stoi(temp);
                                        break;
                                    }
                                case 2:
                                    {
                                        cout << "Withdrawal amount: ";
                                        getline(cin, temp);
                                        accounts -> at(loc).balance -= stoi(temp);
                                        break;
                                    }
                                case 3:
                                    success = false;
                            }
                        } while(success);
                        cout << "Press any key to coninue...";
                        getchar();
                    }
                case 5:
                    {
                        /*ofstream outputClients("clients");
                        ofstream outputAccounts("accounts");
                        if(outputClients.fail()) {
                            cout << "Failed to save client information";
                        }
                        if(outputAccounts.fail()) {
                            cout << "Failed to save Account information";
                        }
                        for(int i = 0; i < clients -> size(); i++) {
                            outputClients << clients -> at(i).name << endl
                                << clients -> at(i).address << endl
                                << clients -> at(i).ssn << endl
                                << clients -> at(i).employer << endl
                                << clients -> at(i).income << endl;
                        }
                        for(int i = 0; i < accounts -> size(); i++) {
                            outputAccounts << accounts -> at(i).name << endl
                                << accounts -> at(i).accountNumber << endl
                                << accounts -> at(i).accountType << endl
                                << accounts -> at(i).balance << endl;
                        }
                        */
                        saveClients(*clients);
                        saveAccounts(*accounts);
                        cout << "Client and account information saved!\n";
                        cout << "Press any key to continue...";
                        getchar();
                    }
                case 6:
                    return true;
            }

            return exit;
        }

        void ScreenNormal::changePassword() {
            bool success = false;
            do {
                cout << "New password: ";
                string temp;
                getline(cin, temp);
                if(login -> at(userID).password == temp) {
                    cout << "Your new password must be different!\n";
                if(temp.size() == 0)
                    cout << "Your new password can't be empty!";
                } else {
                    login -> at(userID).password = temp;
                    success = true;
                }
            } while(!success);
            cout << "Password changed!\n";
            cout << "Press any key to continue...";
            getchar();
        }


    //ScreenAdmin

        ScreenAdmin::ScreenAdmin(int userID, vector<User>* login, vector<Client>* clients,
                vector<Account>* accounts)
            : ScreenNormal(userID, login, clients, accounts) {}

        void ScreenAdmin::staffAdd() {
            cout << "You will be adding a staff member to the system...\n";
            string temp;
            User tempUser;
            bool success = false;
            do {
                cout << "User name: ";
                getline(cin, temp);
                if(temp.size() != 0) {
                    success = true;
                } else {
                    cout << "The user name can't be empty!";
                }
            } while(!success);
            tempUser.username = temp;
            success = false;
            do {
                cout << "Password: ";
                getline(cin, temp);
                if(temp.size() != 0) {
                    success = true;
                } else {
                    cout << "The password can't be empty!";
                }
            } while(!success);
            tempUser.password = temp;
            cout << "Choose role:\n";
            cout << "1) Normal user\n";
            cout << "2) Administrator\n";
            int answer = menuDecider(2);
            cout << "1) Confirm\n";
            cout << "2) Cancel\n";
            int confirm = menuDecider(2);
            if(answer == 1) {
                tempUser.role = 0;
            } else {
                tempUser.role = 1;
            }
            if(confirm == 1) {
                cout << "A new branch staff member is added!\n";
                login -> push_back(tempUser);
                cout << "User name: " << tempUser.username;
                if(tempUser.role == 0) {
                    cout << "    Role: Normal User\n";
                } else {
                    cout << "    Role: System Administrator\n";
                }
            }
            cout << "Press any key to continue...";
            getchar();
        }

        void ScreenAdmin::staffDelete() {
            string temp;
            cout << "Delete a user - User name: ";
            getline(cin, temp);
            cout << "1) Confirm\n";
            cout << "2) Cancel\n";
            int answer = menuDecider(2);
            bool success = false;
            if(answer == 1) {
                for(int i = 0; i < login -> size(); i++) {
                    if(login -> at(i).username == temp) {
                        cout << "User " << temp << " was deleted!\n";
                        login -> erase(login -> begin() + i);
                        success = true;
                    }
                }
                if(!success) {
                    cout << "Warning - User " << temp << " is not in the system. No user is deleted!\n";
                }
                cout << "Press any key to continue...";
                getchar();
            }
        }

        void ScreenAdmin::staffDisplay() {
            cout << "There are " << login -> size() << " users in the system.\n";
            for(int i = 0; i < login -> size(); i++) {
                cout << i + 1 << ". User name: " << login -> at(i).username << "\tRole: ";
                if(login -> at(i).role == 0) {
                    cout << "Branch Staff\n";
                } else {
                    cout << "System Administrator\n";
                }
            }
            cout << "Press any key to continue...";
            getchar();
        }
