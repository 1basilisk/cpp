#include <iostream>

using namespace std;
int main()
{
    string username;
    string passcode, c;

    cout << "enter user name";
    cout << "\t"    "\t";
    cin >> username;
    if (username == "major")
    {
        cout << "enter passcode        ";
        cin >> passcode;
        if (passcode == "number1")
        {
            cout << "        you are logged in";
        }

        else
        {
            cout << "wrong password";
            cout << "\n";
            cout << "this is your last attempt";
            cout << "\n";
            cout << "enter passcode";
            cin >> passcode;
            if (passcode == "number2")
            {
                cout << "you are logged in";
            }
            else
            {
                cout << "access unauthorized";
            }
        }
    }
    else
    {
        cout << "you dont know anything";
    }
}