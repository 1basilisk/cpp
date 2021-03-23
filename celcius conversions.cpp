/*temperture conversion
made at 10:12 29 jan 2019*/
#include <iostream>
using namespace std;
int main()
{
    double c, f, k;
    cout << "Enter temerature in celcius";
    cout << "\t";
    cin >> c;
    f = 1.8 * c + 32;
    k = c + 273.15;
    cout << f << "°F"
         << " and " << k << "K \n";
    main();
}