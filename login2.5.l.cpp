#include <iostream>
#include "quad.h"
using namespace std;
void myf()
{
    cout << "you are welcome";
    quad();
}
int maain()
{
    string username;
    string passcode, c;

    cout << "enter user name";
    cout << "\t"
            "\t";
    cin >> username;
    if (username == "major")
    {
        cout << "enter passcode";
        cin >> passcode;
        if (passcode == "number1")
        {
            myf();
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
                myf();
            }
            else
            {
                cout << "access unauthorized";
            }
        }
    }
    else
    {
        cout << "unauthorized username"
             << "\n";
       ;
    }
}