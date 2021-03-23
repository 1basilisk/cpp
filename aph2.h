//for printing AP
#include <iostream>
using namespace std;

int printap()
{int a,d,n;
 int  l = a + (n - 1) * d;
    cout << "The AP is\n";
   
    while (a <= l)
    {
        cout << "\t" << a;
        a = a + d;
    }
}
