//for printing AP
#include <iostream>
using namespace std;
int a, d, n, l = a + (n - 1) * d;
int printap()
{
    cout << "Enter First Term";
    cin >> a;
    cout << "Enter Common Difference";
    cin >> d;
    cout << "Enter number of terms";
    cin >> n;
    cout << "The AP is\n";
   ;
    while (a <= l)
    {
        cout << "\t" << a;
        a = a + d;
    }
}
