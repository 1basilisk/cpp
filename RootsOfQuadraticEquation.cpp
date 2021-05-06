//to find roots of quadratic equations
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b, c, D, r1, r2;
    cout << "enter cofficient of x²"
         << "\t";
    cin >> a;
    cout << "\n"
         << "enter cofficient of x"
         << "\t";
    cin >> b;
    cout << "\n"
         << "enter constant term"
         << "\t";
    cin >> c;
    // Finding discriminant.
    D = b * b - 4 * a * c;
    //Putting Conditions.
    if (D < 0)
    {
        cout << "No Real Root. Try Again"
             << "\n"
                "\n";   /*since D is negative roots are         					imaginary*/

        main();
    }
    if (D == 0)        // condition for equal root
    {
        r1 = -b / 2 / a;
        cout << "\t";
        cout << "The Root Is:";
        cout << "\t" << r1;
        cout << "\n";
        main();
    }
    if (D > 0 )   /*condition for real and unequal                     		  roots*/
    {
        r1 = (-b + sqrt(D)) / 2 / a;
        r2 = (-b - sqrt(D)) / 2 / a;
        cout << "Roots are:"
             << "\t"
             << r1 << "\t"
             << "And"
             << "\t" << r2;
    }
}
//Working!!!50 LINES¡¡¡