// login.cpp        version 2.6
// Co-Authors: Rohit Mehta, Utkarsh Sharma
// Last Modified: 2019 Jan, 30
#include <iostream>
#include <cstdlib>        // for exit()
using namespace std;
#define MAX_USR 5 // current user count
// used to access user database
#define USR 0
#define PASS 1

// our data of known users
const string users[MAX_USR][2] =
    {{"rohit", "123roh"},
     {"utkarsh", "major"},
     {"mohit", "dead001"},
     {"manish", "12345"},
     {"abhishek", "wwe"}};

int main()
{
    cout << "\t * * * Log In Prompt * *  *\n";
    cout << "Who are you?\t";
    string who;
    getline(cin, who);

    int i = 0; // current row in the users table
    while (i < MAX_USR && users[i][USR] != who)
        i++;

    if (i == MAX_USR)
    {
        cerr << "I don't know you...\n";
        cerr << "Strangers are Prohibited.\n";
        exit(8);
    }
    else
    {
        // now we'll use 'who' to store user's password
        int chance = 3;
        do
        {
            cout << "Password:\t";
            cout << "\033[1;3" << 0 << ";4" << 0 << 'm' << flush;
            getline(cin, who);
            cout << "\033[1;3" << 7 << ";4" << 0 << 'm' << flush;
            chance--; // user lost his chance
        } while (chance > 0 && users[i][PASS] != who);

        if (chance == 0)
        {
            cerr << "Error: Wrong Password\n";
            cerr << "Access unauthorized.\n";
            main();
        }
        else
        {
            cout << "Access Granted.\n";
            cout << "Welcome Mr. " << users[i][USR] << endl;
        }
    }
    return 0;
}
// in version 2.7
// I want to hide the echoing of password on screen that user types.