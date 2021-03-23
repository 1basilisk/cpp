//for printing AP
#include <iostream>
using namespace std;
int main()
{
    double a, d, n, l;
    cout << "Enter First Term";
    cin >> a;
    cout << "Enter Common Difference";
    cin >>d;
    cout<<"Emter number of terms";
    cin>>n;
    cout<<"The AP is\n";
    l=a+(n-1)*d;
    while(a<=l){
        
        cout << "\t"<<a;
        a=a+d;
    }
}