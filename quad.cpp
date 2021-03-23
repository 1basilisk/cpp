//to find roots of quadratic equation
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a,b,c,D,r1,r2;
    cout <<"enter cofficient of x^2"
        << "\t";
    cin >> a;
    cout << "\n"
        << "enter coeff of x"
        << "\t";
    cin >> b;
    cout << "\n"
        << "enter constant term"
        << "\t";
    cin >> c;
    // Finding discriminant
    D = b * b - 4 * a * c;
    // Putting conditions
    if(D < 0)
    {
        cout << "No Real Root. Try Again"
            << "\n\n";
    }
    if( D == 0)
    {
        r1 = -b/2/a;
        cout << "\t";
        cout << "The Root is: ";
        cout << "\t" << r1;
        cout << "\n";
    }
    if( D > 0 )
    {
        r1 = (-b + sqrt(D)) /2/a;
        r2 = (-b-sqrt(D))/2/a;
        cout << "Roots are: "
            << "\t"
            << r1 << "\t"
            <<"And\t" << r2;
    }
    return 0;
}