#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{double b ;
while(b <10-2) {
 cout.precision(b);
 cout.fill('*');
 cout.width(25);
	cout << right<< b << fixed<< endl;
	b =b+ 1 ;
}

}